#ifndef DATABASE_RUNNER
#define DATABASE_RUNNER
#endif
#include <uuid_v4.h>
#include <iostream>
#include <cppfs/fs.h>
#include <cppfs/FileHandle.h>
#include <cppfs/FilePath.h>
#include "uuid/uuid.h"
#include "endianness.h"
#include <iostream>
#include <vector>
#include <bitset>
#include <cstddef>
#include <json.hpp>
#include <fstream>
#include <cstdint>

class DatabaseRunner
{
private:
    std::string projectFolder;
    void intToBytes(int valorInt, unsigned char *bytes);
    int bytesToInt(std::uint8_t* buffer);

    

public:
    DatabaseRunner(std::string &projectFolder);
    ~DatabaseRunner();

    void createStorage(std::string &name, std::string &rules);
    bool ModifySegment(std::string &id, std::string &filePath);

    void readDocument(std::string &id, std::string &filePath);

    

    bool writeToDatabaseFile(std::string &data, std::string &fileName);
};


class Storage
{
    private:
    DatabaseRunner* database;
    public:
    Storage();
    ~Storage();
};