#include "database_file_manager.h"
#include <iostream>
#include <cppfs/fs.h>
#include <cppfs/FileHandle.h>
#include <cppfs/FilePath.h>
#include "uuid/uuid.h"
#include "endianness.h"
#include <iostream>
#include <vector>
#include <bitset>
#include <cstddef>
#include <fstream>
#include <sys/types.h>
#include <sys/stat.h>
#include <json.hpp>
#include <cstdint>
#include <boost/filesystem.hpp>
using json = nlohmann::json;
namespace fs = boost::filesystem;
DatabaseFileManager::DatabaseFileManager()
{
    std::string currentPath = fs::current_path().string();
    this->projectFolder = currentPath;
    cppfs::FileHandle folder = cppfs::fs::open(this->projectFolder);

    if (folder.exists() && folder.isDirectory())
    {
        this->projectFolder = projectFolder;
        std::cout << "Carregada com sucesso" << std::endl;
    }
    else
    {
        std::cout << "A pasta não existe e sera criada" << std::endl;
        folder.createDirectory();
        this->projectFolder = projectFolder;
        std::cout << "Carregada com sucesso" << std::endl;
    }
}

int DatabaseFileManager::bytesToInt(std::uint8_t *buffer)
{
    int valorInt = static_cast<int>(buffer[0]) |
                   (static_cast<int>(buffer[1]) << 8) |
                   (static_cast<int>(buffer[2]) << 16) |
                   (static_cast<int>(buffer[3]) << 24);
    return valorInt;
}

void DatabaseFileManager::intToBytes(int valorInt, unsigned char *bytes)
{
    bytes[0] = static_cast<std::uint8_t>(valorInt);
    bytes[1] = static_cast<std::uint8_t>(valorInt >> 8);
    bytes[2] = static_cast<std::uint8_t>(valorInt >> 16);
    bytes[3] = static_cast<std::uint8_t>(valorInt >> 24);
}

void DatabaseFileManager::createStorage(std::string &name, std::string &rules)
{
    std::string path = this->projectFolder + name;
    cppfs::FileHandle storageFolder = cppfs::fs::open(path);
    if (!storageFolder.exists())
    {
        storageFolder.createDirectory();
    }

    json storageInfo;

    storageInfo["name"] = name.c_str();
    storageInfo["files"] = {"initial"};

    std::string tableString = storageInfo.dump(4);

    std::fstream storageFile(path + "/storage_info.json", std::fstream::out);

    storageFile << tableString;

    storageFile.close();
}

bool DatabaseFileManager::ModifyDocument(std::string &id, std::string &filePath, std::string &newData)
{
    std::ifstream dbFile(this->projectFolder + filePath, std::ios::binary);

    int currentPosition = 0;
    dbFile.seekg(0, std::ios::end);
    std::streampos fileSize = dbFile.tellg();
    std::cout << "Database size on modify:" << fileSize << std::endl;
    dbFile.seekg(0);

    while (currentPosition < fileSize)
    {
        dbFile.seekg(currentPosition);

        std::uint8_t idSizeInt8[sizeof(int)];
        std::uint8_t dataSizeInt8[sizeof(int)];
        // Read id
        dbFile.read((char *)(&idSizeInt8), sizeof(idSizeInt8));

        int sizeOfId = this->bytesToInt(idSizeInt8);
        char idBytes[sizeOfId];

        dbFile.seekg(currentPosition + 8);
        dbFile.read(idBytes, sizeof(idBytes));

        std::string idString(idBytes, sizeof(idBytes));
        std::cout << idString << "   :   " << id << std::endl;

        // read the data size
        dbFile.seekg(currentPosition + 4);
        dbFile.read((char *)(&dataSizeInt8), sizeof(dataSizeInt8));

        // bytes to int
        int sizeOfData = this->bytesToInt(dataSizeInt8);

        if (strcmp(id.c_str(), idString.c_str()) == 0)
        {
            unsigned int dataSize = newData.length();
            std::uint8_t dataSizeBytes[4];
            this->intToBytes(dataSize, dataSizeBytes);

            char dataBytes[dataSize];

            for (size_t i = 0; i < newData.length(); i++)
            {
                dataBytes[i] = newData[i];
            }

            std::ofstream outputFile(this->projectFolder + filePath + ".temp", std::ios::app);
            std::streampos i = 0;
            while (i < fileSize)
            {
                if (i == currentPosition)
                {

                    outputFile.write((char *)&idSizeInt8, sizeof(idSizeInt8));
                    outputFile.write((char *)&dataSizeBytes, sizeof(dataSizeBytes));
                    outputFile.write((char *)&idBytes, sizeof(idBytes));
                    outputFile.write((char *)&dataBytes, sizeof(dataBytes));
                    i += sizeOfData + sizeOfId + 8;
                    continue;
                }
                char byte[1];
                dbFile.seekg(i);

                dbFile.read(byte, sizeof(byte));
                outputFile.write(byte, sizeof(byte));

                i += 1;
            }

            outputFile.close();
            dbFile.close();

            cppfs::FileHandle oldFile = cppfs::fs::open(this->projectFolder + filePath);
            cppfs::FileHandle newFile = cppfs::fs::open(this->projectFolder + filePath + ".temp");

            oldFile.remove();
            newFile.rename(filePath);
            return true;
        }

        currentPosition += sizeOfData + sizeOfId + 8;
    }

    dbFile.close();

    return false;
}
bool DatabaseFileManager::DeleteDocument(std::string &id, std::string &filePath)
{
    std::ifstream dbFile(this->projectFolder + filePath, std::ios::binary);

    int currentPosition = 0;
    dbFile.seekg(0, std::ios::end);
    std::streampos fileSize = dbFile.tellg();
    std::cout << "Database size on modify:" << fileSize << std::endl;
    dbFile.seekg(0);

    while (currentPosition < fileSize)
    {
        dbFile.seekg(currentPosition);

        std::uint8_t idSizeInt8[sizeof(int)];
        std::uint8_t dataSizeInt8[sizeof(int)];
        // Read id
        dbFile.read((char *)(&idSizeInt8), sizeof(idSizeInt8));

        int sizeOfId = this->bytesToInt(idSizeInt8);
        char idBytes[sizeOfId];

        dbFile.seekg(currentPosition + 8);
        dbFile.read(idBytes, sizeof(idBytes));

        std::string idString(idBytes, sizeof(idBytes));
        std::cout << idString << "   :   " << id << std::endl;

        // read the data size
        dbFile.seekg(currentPosition + 4);
        dbFile.read((char *)(&dataSizeInt8), sizeof(dataSizeInt8));

        // bytes to int
        int sizeOfData = this->bytesToInt(dataSizeInt8);

        if (strcmp(id.c_str(), idString.c_str()) == 0)
        {

            std::ofstream outputFile(this->projectFolder + filePath + ".temp", std::ios::app);
            std::streampos i = 0;
            while (i < fileSize)
            {
                if (i == currentPosition)
                {
                    i += sizeOfData + sizeOfId + 8;
                    continue;
                }
                char byte[1];
                dbFile.seekg(i);

                dbFile.read(byte, sizeof(byte));
                outputFile.write(byte, sizeof(byte));

                i += 1;
            }

            outputFile.close();
            dbFile.close();

            cppfs::FileHandle oldFile = cppfs::fs::open(this->projectFolder + filePath);
            cppfs::FileHandle newFile = cppfs::fs::open(this->projectFolder + filePath + ".temp");

            oldFile.remove();
            newFile.rename(filePath);
            return true;
        }

        currentPosition += sizeOfData + sizeOfId + 8;
    }

    dbFile.close();

    return false;
}

std::string DatabaseFileManager::readDocument(std::string &id, std::string &filePath)
{
    std::ifstream dbFile(projectFolder + filePath, std::ios::binary);

    int currentPosition = 0;
    std::cout << "Database size:" << dbFile.end << std::endl;
    dbFile.seekg(0, std::ios::end);
    std::streampos fileSize = dbFile.tellg();

    while (currentPosition < fileSize)
    {
        dbFile.seekg(currentPosition);

        std::uint8_t idSizeInt8[sizeof(int)];
        std::uint8_t dataSizeInt8[sizeof(int)];
        // Read id
        dbFile.read((char *)(&idSizeInt8), sizeof(idSizeInt8));

        int sizeOfId = this->bytesToInt(idSizeInt8);
        char idBytes[sizeOfId];

        dbFile.seekg(currentPosition + 8);
        dbFile.read(idBytes, sizeof(idBytes));

        std::string idString(idBytes, sizeof(idBytes));
        std::cout << idString << "   :   " << id << std::endl;

        // read the data size
        dbFile.seekg(currentPosition + 4);
        dbFile.read((char *)(&dataSizeInt8), sizeof(dataSizeInt8));

        // bytes to int
        int sizeOfData = this->bytesToInt(dataSizeInt8);

        if (strcmp(id.c_str(), idString.c_str()) == 0)
        {
            char dataBytes[sizeOfData];
            // Read document
            dbFile.seekg((currentPosition + 8 + sizeOfId));
            dbFile.read(dataBytes, sizeof(dataBytes));

            // To string
            std::string data(dataBytes, sizeof(dataBytes));

            dbFile.close();

            return data;
        }

        currentPosition += sizeOfData + sizeOfId + 8;
    }

    dbFile.close();

    return "-1";
}

bool DatabaseFileManager::writeToDatabaseFile(std::string &data, std::string &fileName, std::string uuidStr)
{

    unsigned int idSize = uuidStr.length();
    unsigned int dataSize = data.length();

    std::cout << uuidStr << std::endl;

    std::uint8_t idSizeBytes[4];
    std::uint8_t dataSizeBytes[4];

    this->intToBytes(idSize, idSizeBytes);
    this->intToBytes(dataSize, dataSizeBytes);

    std::cout << "Size of id: " << this->bytesToInt(idSizeBytes) << std::endl;
    std::cout << "Size of data: " << this->bytesToInt(dataSizeBytes) << std::endl;

    char totalData[8 + dataSize + idSize];

    char dataBytes[data.length()];
    char idBytes[uuidStr.length()];

    for (size_t i = 0; i < uuidStr.length(); i++)
    {
        idBytes[i] = uuidStr[i];
    }
    for (size_t i = 0; i < data.length(); i++)
    {
        dataBytes[i] = data[i];
    }

    std::ofstream file(projectFolder + fileName, std::ofstream::app);

    if (file.good())
    {
        std::cout << "Encontrado" << std::endl;
        file.write((char *)&idSizeBytes, sizeof(idSizeBytes));
        file.write((char *)&dataSizeBytes, sizeof(dataSizeBytes));
        file.write((char *)&idBytes, sizeof(idBytes));
        file.write((char *)&dataBytes, sizeof(dataBytes));
        file.close();
        return true;
    }

    file.close();
    std::ofstream outputFile(projectFolder + fileName, std::ios::binary);
    outputFile.write((char *)&dataSizeBytes, sizeof(dataSizeBytes));
    outputFile.write((char *)&idSizeBytes, sizeof(idSizeBytes));
    outputFile.write((char *)&idBytes, sizeof(idBytes));
    outputFile.write((char *)&dataBytes, sizeof(dataBytes));

    outputFile.close();

    return true;
}

DatabaseFileManager::~DatabaseFileManager()
{
}
