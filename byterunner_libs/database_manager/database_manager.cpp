#include "../database_file_manager/database_file_manager.h"
#include "database_manager.h"
#include "storage/storage.h"
#include <iostream>


DatabaseManager::DatabaseManager(std::string projectFolder)
{
    this->projectFolder = projectFolder;
    this->databaseFileManager(projectFolder);
}

DatabaseManager::~DatabaseManager()
{
}