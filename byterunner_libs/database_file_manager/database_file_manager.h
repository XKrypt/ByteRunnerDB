#ifndef DATABASE_FILE_MANAGER
#define DATABASE_FILE_MANAGER

#include <iostream>
#include <iostream>
#include <vector>
#include <bitset>
#include <cstddef>
#include <json.hpp>
#include <fstream>
#include <cstdint>
#include <filesystem>
class DatabaseFileManager
{
private:
    std::string projectFolder;
    void intToBytes(int valorInt, unsigned char *bytes);
    int bytesToInt(std::uint8_t* buffer);

    void LoadDatabaseFiles();

    

public:
    DatabaseFileManager();
    ~DatabaseFileManager();
    void createStorage(std::string &name, std::string &rules);
    bool ModifyDocument(std::string &id, std::string &filePath, std::string &newData);
    bool DeleteDocument(std::string &id, std::string &filePath);
    std::string readDocument(std::string &id, std::string &filePath);

    

    bool writeToDatabaseFile(std::string &data, std::string &fileName, std::string uuidStr);
};
#endif