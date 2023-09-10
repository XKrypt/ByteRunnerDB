#include <iostream>
#include <fstream>
#include "byterunner_libs/database_file_manager/database_file_manager.h"
#include "byterunner_libs/database_manager/database_manager.h"
#include "uuid_v4.h"
#include <random>
#include <filesystem>
#include "CLI11.hpp"
#include "byterunner_libs/runner_gui/runner_gui.h"
#include "byterunner_libs/cli/cli.h"
int main(int argc, char** argv)
{

    std::cout << argv[0] << std::endl;
    CLI::App app{"ByteRunnerDB"};


    std::string projectName;
    bool runDevProject = false;
    bool runGui = false;
    app.add_option("-n, --new",projectName,"Cria um novo projeto");
    app.add_flag("-r, --run-dev",runDevProject,"Roda um projeto em modo de desenvolvimento");
    app.add_flag("-g, --run-gui", runGui, "Roda a gui");

    CLI11_PARSE(app,argc,argv);
    if (runGui) {
       runGuiWindow();
    }
    if(!projectName.empty()){
        CliRunner::createProject(projectName);
    }
    if(runDevProject){
        CliRunner::runDevProject();
    }
   
    return 0;
}