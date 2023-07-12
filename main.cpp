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
int main(int argc, char** argv)
{   
        // Inicialize o ambiente Mono
    mono_set_dirs("/lib", "/etc");
    mono_config_parse("/etc/mono/config");
    MonoDomain *domain = mono_jit_init("projectName");
        // Libere os recursos
    mono_jit_cleanup(domain);
    CLI::App app{"ByteRunnerDB"};


    std::string projectName;
    app.add_option("-n, --new",projectName,"Cria um novo projeto");

    CLI11_PARSE(app,argc,argv);

    if(!projectName.empty()){
        CliRunner::createProject(projectName);
    }
    
    return 0;
}