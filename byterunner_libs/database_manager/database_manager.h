#ifndef DATABASE_MANAGER
#define DATABASE_MANAGER

#include "../database_file_manager/database_file_manager.h"
#include <iostream>
#include "storage/storage.h"
#include "../../libs/nlhoman/json.hpp"
using json = nlohmann::json;
class DatabaseManager
{
private:
    std::string projectFolder;
    DatabaseFileManager databaseFileManager;
    std::vector<Storage> storages;
    int maxFileSize;
    int pagination;
    json config;

public:
    DatabaseManager();
    ~DatabaseManager();

    bool WriteNewDocument(const char *storageName, json data);
    bool UpdateDocument(json data);
    bool DeleteDocument(json data);
    bool GetDocument(json data);

    std::string GetFileToWrite(Storage* storage);
    static void createProject(std::string &folder, std::string &projectName);
};

#endif