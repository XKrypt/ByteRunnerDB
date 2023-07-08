#ifndef STORAGE
#define STORAGE

#include <json.hpp>
#include <iostream>

class Storage
{
private:
   std::string storageName;
   std::string storageFile;
public:
    Storage();
    ~Storage();
};

#endif