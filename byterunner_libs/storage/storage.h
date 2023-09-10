#ifndef STORAGE
#define STORAGE

#include "../../libs/nlhoman/json.hpp"
#include <iostream>

using json = nlohmann::json;
class Storage
{
private:
public:
   std::string storageName;
   std::string storageFile;
   std::string storageFolder;
    Storage();
    ~Storage();
};

#endif