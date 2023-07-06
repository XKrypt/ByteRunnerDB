#include "database_runner.h"
#include <uuid_v4.h>
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
using json = nlohmann::json;

DatabaseRunner::DatabaseRunner(std::string &projectFolder)
{
    cppfs::FileHandle folder = cppfs::fs::open(projectFolder);

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


int DatabaseRunner::bytesToInt(std::uint8_t *buffer)
{
    int valorInt = static_cast<int>(buffer[0]) |
                   (static_cast<int>(buffer[1]) << 8) |
                   (static_cast<int>(buffer[2]) << 16) |
                   (static_cast<int>(buffer[3]) << 24);
    return valorInt;
}

void DatabaseRunner::intToBytes(int valorInt, unsigned char *bytes)
{
    bytes[0] = static_cast<std::uint8_t>(valorInt);
    bytes[1] = static_cast<std::uint8_t>(valorInt >> 8);
    bytes[2] = static_cast<std::uint8_t>(valorInt >> 16);
    bytes[3] = static_cast<std::uint8_t>(valorInt >> 24);
}

void DatabaseRunner::createStorage(std::string &name, std::string &rules)
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

bool DatabaseRunner::ModifySegment(std::string &id, std::string &filePath)
{
    std::ifstream dbFile(projectFolder + filePath, std::ios::binary);

    std::uint8_t idSizeInt8[sizeof(int)];
    std::uint8_t dataSizeInt8[sizeof(int)];

    dbFile.read((char *)(&idSizeInt8), sizeof(idSizeInt8));
    int sizeOfId = this->bytesToInt(idSizeInt8);
    std::cout << "Tamanho do id: " << sizeOfId << std::endl;
    char idBytes[sizeOfId];
    dbFile.seekg(8);
    dbFile.read(idBytes, sizeof(idBytes));

    std::string idString(idBytes, sizeof(idBytes) - 1);

    
    dbFile.seekg(4);
    dbFile.read((char *)(&dataSizeInt8), sizeof(dataSizeInt8));
    int sizeOfData = this->bytesToInt(dataSizeInt8);
    std::cout << "Tamanho dos dados: " << sizeOfData << std::endl;
    char dataBytes[sizeOfData];
    
    dbFile.seekg((8 + sizeOfId));
    dbFile.read(dataBytes, sizeof(dataBytes));
    std::string data(dataBytes, sizeof(dataBytes));


    
    std::cout << data << std::endl;

    dbFile.close();
    std::cout << "ID : " << idString << " Tamanho: " << sizeof(idBytes) << std::endl;
    return true;
}

bool DatabaseRunner::writeToDatabaseFile(std::string &data, std::string &fileName)
{
    UUIDv4::UUIDGenerator<std::mt19937_64> uuid_generate;
    UUIDv4::UUID uuid = uuid_generate.getUUID();
    std::string uuidStr = uuid.str();

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
    file.seekp(file.end);
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

DatabaseRunner::~DatabaseRunner()
{
}
