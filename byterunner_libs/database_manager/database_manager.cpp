#include "../database_file_manager/database_file_manager.h"
#include "database_manager.h"
#include "storage/storage.h"
#include "cppfs/FileHandle.h"
#include "../../libs/nlhoman/json.hpp"
#include <iostream>
#include <boost/filesystem.hpp>
namespace fs = boost::filesystem;
DatabaseManager::DatabaseManager()
{
    std::string currentPath = fs::current_path().string();
    this->projectFolder = currentPath;
}

DatabaseManager::~DatabaseManager()
{
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