#ifndef DATABASE_MANAGER
#define DATABASE_MANAGER

#include "../database_file_manager/database_file_manager.h"
#include <iostream>
#include "storage/storage.h"


class DatabaseManager
{
private:
    std::string projectFolder;
    DatabaseFileManager databaseFileManager;
   
public:
    DatabaseManager(std::string projectFolder);
    ~DatabaseManager();

    bool WriteNewDocument();
};

#endif