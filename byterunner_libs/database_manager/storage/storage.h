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
   json configs;
public:
    Storage();
    ~Storage();
};

#endif