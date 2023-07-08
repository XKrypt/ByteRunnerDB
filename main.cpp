#include <iostream>
#include <mono-2.0/mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>
#include <fstream>
#include "byterunner_libs/database_file_manager/database_file_manager.h"
#include "byterunner_libs/database_manager/database_manager.h"
#include "uuid_v4.h"
#include <random>

int main()
{   
    UUIDv4::UUIDGenerator<std::mt19937_64> uuid_generate;
    UUIDv4::UUID uuid = uuid_generate.getUUID();
    std::string uuidStr = uuid.str();
    
    std::string folder = "ProjectFolder/";
    DatabaseFileManager* database = new DatabaseFileManager(folder);
    std::string test = "fewfewfewfeewfwfwf";
    std::string testFile = "fewfewfew.byte";
    database->writeToDatabaseFile(test,testFile,uuidStr);
    std::string storageName = "My_Storage";
    std::string storageRules = "";
    database->createStorage(storageName, storageRules);

    
    std::string data =  database->readDocument(uuidStr,testFile);

    std::cout  << "Data :" << data <<  std::endl;
    std::string newData = "NEEEWWW DATA";
  if(!database->ModifyDocument(uuidStr, testFile, newData)){
        std::cout << "Error modifing." << std::endl;
    }

    if (!database->DeleteDocument(uuidStr,testFile))
    {
        std::cout << "Error on deleting." << std::endl;
    }

    std::string projectFolder = "/home/fhayha";
    std::string projectName = "Teste";
    DatabaseManager::createProject(projectFolder, projectName);


    
    
    return 0;
}