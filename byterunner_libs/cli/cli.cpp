#include <iostream>
#include "../database_manager/database_manager.h"
#include <filesystem>
#include "../csharp_handle/csharp_handle.h"
#include "cli.h"
#include "../server_runner/server_runner.h"
#include "../environment_runner/environment_runner.h"
namespace fs = std::filesystem;
using namespace CliRunner;

void CliRunner::createProject(std::string &projectName)
{
    std::string currentPath = fs::current_path().string();
    DatabaseManager::createProject(currentPath, projectName);
    CSharpHandle::generateScriptProject(currentPath, projectName);
}

void CliRunner::runDevProject(){
    EnvironmentRunner envRunner;
    envRunner.StartEnvironment();
    while (true)
    {
        /* code */
    }
    

}