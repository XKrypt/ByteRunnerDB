#include "../database_file_manager/database_file_manager.h"
#include "database_manager.h"
#include "../storage/storage.h"
#include <cppfs/FileHandle.h>
#include <cppfs/FilePath.h>
#include <cppfs/fs.h>
#include "json.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "uuid_v4.h"
#include "endianness.h"
#include <chrono>
namespace fs = std::filesystem;
using json = nlohmann::json;
DatabaseManager::DatabaseManager()
{
    std::string currentPath = fs::current_path().string();
    this->projectFolder = currentPath;

    std::ifstream jsonData(projectFolder + "/runner-project.json");

    config = json::parse(jsonData);

    maxFileSize = config["max_file_size"];

    if (config["storages"].is_array())
    {
        for (auto storageJson : config["storages"])
        {
            Storage storage;
            storage.storageName = storageJson["name"];
            storage.storageFolder = storageJson["folder"];
            std::cout << storage.storageName << std::endl;
            storages.push_back(storage);
        }
    }
    else
    {
        std::cout << "error loading storages.";
    }
}

DatabaseManager::~DatabaseManager()
{
}

std::string DatabaseManager::GetFileToWrite(Storage* storage)
{
    std::string storagePath = projectFolder + "/" + storage->storageFolder;

    for (const auto &entry : fs::directory_iterator(storagePath))
    {
        if (entry.path().extension() == ".byteRun")
        {
            size_t dbFileSize = fs::file_size(entry.path());
            if (dbFileSize < maxFileSize)
            {
                return entry.path().string();
            }
        }
    }

    // Obter o timestamp atual usando o relógio de alta resolução
    auto now = std::chrono::high_resolution_clock::now();

    // Converter o timestamp para um valor inteiro (representando nanossegundos)
    auto timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();

    // Imprimir o timestamp
    std::cout << "Timestamp: " << timestamp << std::endl;

    return storagePath + "/" + std::to_string(timestamp) + ".byteRun";
}

bool DatabaseManager::WriteNewDocument(const char *storageName, json data)
{
    UUIDv4::UUIDGenerator<std::mt19937_64> uuidGenerator;
    UUIDv4::UUID uuid = uuidGenerator.getUUID();

    data["uid"] = uuid.str();

    std::string dataString = data.dump();

    Storage *storageToWrite = nullptr;
    for (auto &storage : storages)
    {
        std::cout << storage.storageName << std::endl;
        if (storage.storageName == storageName)
        {
            storageToWrite = &storage;
            std::cout << "found" << std::endl;
            break;
        }
    }

    if (storageToWrite == nullptr)
    {
        std::cout << "storage not found" << std::endl;
        return false;
    }
    std::string fileName = GetFileToWrite(storageToWrite);
    databaseFileManager.writeToDatabaseFile(dataString, fileName, uuid.str());

    return true;
}
bool DatabaseManager::OverrideDocument(const char *docId, const char *storageName, json data)
{
    Storage *storageToWrite = nullptr;
    for (auto &storage : storages)
    {
        std::cout << storage.storageName << std::endl;
        if (storage.storageName == storageName)
        {
            storageToWrite = &storage;
            std::cout << "found" << std::endl;
            break;
        }
    }

    if (storageToWrite == nullptr)
    {
        std::cout << "storage not found" << std::endl;
        return false;
    }

    data["id"] = docId;
    std::string storagePath = projectFolder + "/" + storageToWrite->storageFolder;

    for (const auto &entry : fs::directory_iterator(storagePath))
    {
        if (entry.path().extension() == ".byteRun")
        {
            std::string idDoc(docId);
            std::string file = entry.path().string();
            std::string dataStr = data.dump();

            bool result = databaseFileManager.ModifyDocument(idDoc, file, dataStr);
            if (result)return true;
        }
    }

    return false;
}
bool DatabaseManager::DeleteDocument(const char *docId, const char *storageName)
{
    Storage *storageToWrite = nullptr;
    for (auto &storage : storages)
    {
        std::cout << storage.storageName << std::endl;
        if (storage.storageName == storageName)
        {
            storageToWrite = &storage;
            std::cout << "found" << std::endl;
            break;
        }
    }

    if (storageToWrite == nullptr)
    {
        std::cout << "storage not found" << std::endl;
        return false;
    }
    std::string storagePath = projectFolder + "/" + storageToWrite->storageFolder;

    for (const auto &entry : fs::directory_iterator(storagePath))
    {
        if (entry.path().extension() == ".byteRun")
        {
            std::string idDoc(docId);
            std::string file = entry.path().string();
            bool result = databaseFileManager.DeleteDocument(idDoc, file);
            if (result)return true;
        }
    }
    return false;
}
bool DatabaseManager::GetDocument(json data)
{
    return true;
}

void DatabaseManager::createProject(std::string &folder, std::string &projectName)
{

    // Folder of project
    cppfs::FileHandle folderToPutProject = cppfs::fs::open(folder);

    if (!folderToPutProject.exists())
    {
        std::cout << "Folder \"" << folder << "\" is not found" << std::endl;
        return;
    }

    // Create project folder
    cppfs::FilePath path(folder + "/" + projectName);
    std::string folderPath = path.path();
    cppfs::FileHandle projectFolder = cppfs::fs::open(folderPath);

    if (!projectFolder.exists())
    {
        projectFolder.createDirectory();
    }

    // Create configurations
    json config;

    config["project-name"] = projectName;
    config["port"] = 4848;
    config["storages"] = {
        {{"name", "default"},
         {"folder", "default"},
         {"rules", "rules.json"},
         {"scripts", "scripts/"}}};

    config["global-scripts"] = "global/scripts/";

    // Project configurations
    cppfs::FilePath projectFilePath(folderPath + "/" + "runner-project.json");
    std::ofstream projectConfigs(projectFilePath.path());

    // Indentations
    projectConfigs << config.dump(4);
    projectConfigs.close();

    // TODO: create a function to automate this code block
    cppfs::FilePath storageDefaultPath(folderPath + "/" + "default/");
    cppfs::FileHandle storageDefault = cppfs::fs::open(storageDefaultPath.path());
    storageDefault.createDirectory();

    cppfs::FilePath storageDefaultScriptsPath(folderPath + "/" + "default/scripts");
    cppfs::FileHandle storageDefaultScript = cppfs::fs::open(storageDefaultScriptsPath.path());
    storageDefaultScript.createDirectory();

    cppfs::FilePath storageDefaultDataPath(folderPath + "/" + "default/data/");
    cppfs::FileHandle storageDefaultDataFolder = cppfs::fs::open(storageDefaultDataPath.path());
    storageDefaultDataFolder.createDirectory();

    cppfs::FilePath globalFolderPath(folderPath + "/" + "global/");
    cppfs::FileHandle globalFolder = cppfs::fs::open(globalFolderPath.path());
    globalFolder.createDirectory();

    cppfs::FilePath globalScriptsPath(folderPath + "/" + "global/scripts");
    cppfs::FileHandle globalScriptsFolder = cppfs::fs::open(globalScriptsPath.path());
    globalScriptsFolder.createDirectory();
}