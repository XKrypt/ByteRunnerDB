#ifndef STORAGE
#define STORAGE

#include "../../../libs/nlhoman/json.hpp"
#include <iostream>

using json = nlohmann::json;
class Storage
{
private:
   std::string storageName;
   std::string storageFile;
   std::string storageFolder;
   std::string storageScripts;
   json rules;
public:
    Storage();
    ~Storage();
};

#endif