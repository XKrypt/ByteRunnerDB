#include <iostream>
#include "../database_manager/database_manager.h"
#include <boost/filesystem.hpp>
#include "../csharp_handle/csharp_handle.h"
#include "cli.h"
namespace fs = boost::filesystem;
using namespace CliRunner;

void CliRunner::createProject(std::string &projectName)
{
    std::string currentPath = fs::current_path().string();
    DatabaseManager::createProject(currentPath, projectName);
    //CSharpHandle::generateScriptProject(currentPath, projectName);
}
