#include <iostream>
#include <mono-2.0/mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-config.h>
#include <fstream>
#include "byterunner_libs/database_file_manager/database_file_manager.h"
#include "byterunner_libs/database_manager/database_manager.h"
#include "uuid_v4.h"
#include <random>
#include <filesystem>
#include "CLI11.hpp"
#include "byterunner_libs/cli/cli.h"
#include "byterunner_libs/runner_gui/runner_gui.h"
int main(int argc, char** argv)
{   
    LoadWindow();

    CLI::App app{"ByteRunnerDB"};


    std::string projectName;
    bool runDevProject;
    app.add_option("-n, --new",projectName,"Cria um novo projeto");
    app.add_flag("-r, --run-dev",runDevProject,"Roda um projeto em modo de desenvolvimento");

    CLI11_PARSE(app,argc,argv);

    if(!projectName.empty()){
        CliRunner::createProject(projectName);
    }
    if(runDevProject){
        CliRunner::runDevProject();
    }
   
    return 0;
}