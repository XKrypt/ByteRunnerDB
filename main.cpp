#include <iostream>
#include <mono-2.0/mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>
#include <fstream>
#include "byterunner_libs/database_runner/database_runner.h"

bool fileExists(const std::string &filename)
{
    std::ifstream file(filename);
    return file.good();
}

int main()
{
    std::string folder = "ProjectFolder/";
    DatabaseRunner* database = new DatabaseRunner(folder);
    std::string test = "fewfewfew";
    std::string testFile = "fewfewfew.byte";
    database->writeToDatabaseFile(test,testFile);
    std::string storageName = "My_Storage";
    std::string storageRules = "";
    database->createStorage(storageName, storageRules);

    std::string id = "1811d15d-55f4-425b-8a3e-122bd097ca6a";
    if(!database->ModifySegment(id, testFile)){
        std::cout << "error" << std::endl;
    }
    

    return 0;
}