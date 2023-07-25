// Mono
#include <mono-2.0/mono/jit/jit.h>
#include <mono-2.0/mono/metadata/assembly.h>
#include <mono-2.0/mono/metadata/debug-helpers.h>
#include <mono-2.0/mono/metadata/mono-debug.h>
#include <mono-2.0/mono/metadata/mono-config.h>
#include <mono-2.0/mono/metadata/exception.h>
#include <mono-2.0/mono/metadata/object.h>
#include <mono/metadata/environment.h>
#include <mono-2.0/mono/metadata/mono-gc.h>
#include <efsw/efsw.h>
// end Mono

// NCurses
#include <ncurses.h>

#include "csharp_handle.h"
#include <sstream>
#include "../../libs/rapidxml/rapidxml.hpp"
#include "../../libs/rapidxml/rapidxml_print.hpp"
#include <iostream>
#include <fstream>
#include <boost/filesystem.hpp>
#include <../../libs/nlhoman/json.hpp>
#include <boost/filesystem.hpp>
#include <vector>
namespace xml = rapidxml;
namespace fs = boost::filesystem;
using json = nlohmann::json;
CSharpHandle::ProjectEnvironment::ProjectEnvironment()
{
    std::string currentPath = fs::current_path().string();
    this->projectFolder = currentPath;
    this->isDev = true;

    cppfs::FilePath configPath(projectFolder + "/runner-project.json");
    std::cout << configPath.path() << std::endl;
    std::ifstream configFile(configPath.path());

    this->config = json::parse(configFile);

    mono_set_dirs("/lib", "/etc");
    mono_config_parse("/etc/mono/config");
    MonoDomain *domain = mono_jit_init("Dominio");
    this->projectDomain = domain;
    mono_debug_init(MONO_DEBUG_FORMAT_MONO);
    mono_debug_domain_create(projectDomain);
    setenv("MONO_DEBUG", "casts,gc,loader,exception,security,alloc", 1);
}
CSharpHandle::ProjectEnvironment::~ProjectEnvironment()
{
    mono_jit_cleanup(this->projectDomain);
}

void CSharpHandle::ProjectEnvironment::AddInternalMethod(const char *name, const void *method)
{
    mono_add_internal_call(name, method);
}

void CSharpHandle::ProjectEnvironment::StartWatch()
{

    this->CompileScripts();
    this->LoadAssembles();
    this->LoadClasses();
}

void CSharpHandle::ProjectEnvironment::CompileScripts()
{
    // Comando para compilar o projeto .csproj usando o compilador C# (csc)
    if (this->config == NULL)
    {
        std::cout << "config não inicializada" << std::endl;
        return;
    }
    else
    {
        std::cout << "config inicializada" << this->config["project-name"] << std::endl;
    }
    std::string command;
    std::string projectName = config["project-name"];
    if (this->isDev)
    {
        command = "dotnet build \"" + projectName + ".csproj\" --configuration Debug";
    }
    else
    {
        command = "dotnet build \"" + projectName + ".csproj\" --configuration Release";
    }
    std::cout << "Comando: " << command << std::endl;

    // Executa o comando de compilação do .csproj
    int result = std::system(command.c_str());

    if (result == 0)
    {
        std::cout << "Compilação bem sucedida" << std::endl;
    }
    else
    {
        std::cout << "Erro de compilação" << std::endl;
    }
}

void CSharpHandle::ProjectEnvironment::LoadClasses()
{
    MonoImage *image = mono_assembly_get_image(projectAssembly);

    const MonoTableInfo *tableInfo = mono_image_get_table_info(image, MONO_TABLE_TYPEDEF);

    int rows = mono_table_info_get_rows(tableInfo);

    for (size_t i = 0; i < rows; i++)
    {
        MonoClass *klass;

        uint32_t cols[MONO_TYPEDEF_SIZE];

        mono_metadata_decode_row(tableInfo, i, cols, MONO_TYPEDEF_SIZE);
        const char *name = mono_metadata_string_heap(image, cols[MONO_TYPEDEF_NAME]);
        MonoType *monoType = mono_reflection_type_from_name((char *)name, image);
        if (monoType == nullptr)
        {
            continue;
        }
        klass = mono_class_from_mono_type(monoType);

        MonoClass *superClass = mono_class_get_parent(klass);

        if (superClass == nullptr)
        {
            continue;
        }
        std::string superClassName = mono_class_get_name(superClass);

        if (superClassName == "RunnerBehaviour")
        {
            this->runnerBehaviours.push_back(klass);
        }
    }
    std::cout << "Loaded " << runnerBehaviours.size() << "classes" << std::endl;
}

MonoDomain *CSharpHandle::ProjectEnvironment::GetDomain()
{
    return this->projectDomain;
}

std::vector<MonoObject *> CSharpHandle::ProjectEnvironment::RunMethodFromBehaviours(std::string &methodName, void **args, int paramsCount)
{

    // Attach thread
    mono_jit_thread_attach(mono_get_root_domain());
    // Ger result of behaviour if they return something;
    std::vector<MonoObject *> behavioursReturns;

    for (int i = 0; i < runnerBehaviours.size(); i++)
    {
        // Get behaviour class;
        MonoClass *klass = runnerBehaviours[i];

        // Get behaviour method;
        MonoMethod *method = mono_class_get_method_from_name(klass, methodName.c_str(), paramsCount);

        // if class have the method
        if (method != nullptr)
        {

            // Variable to store exception if happen
            MonoObject *ex = nullptr;

            // Instantiate the class (Will be removed in future)
            MonoObject *obj = mono_object_new(projectDomain, klass);

            // Get return value
            MonoObject *returnValue = mono_runtime_invoke(method, obj, args, &ex);

            // Verify if has an exception
            if (ex != nullptr)
            {
                // Get the ExceptionClass
                MonoClass *exceptionClass = mono_object_get_class(ex);

                // Get ExceptionClassName
                const char *exceptionClassName = mono_class_get_name(exceptionClass);

                // Get exception stack
                char *exceptionStack = mono_debug_print_stack_frame(method, 0, projectDomain);

                // Get method address
                uint32_t addrs = mono_method_get_token(method);

                // Get source location
                MonoDebugSourceLocation *loc = mono_debug_lookup_source_location(method, addrs, projectDomain);

                if (loc != nullptr)
                {
                    std::cout << std::endl;
                    std::cout << "-------------" << std::endl;
                    std::cout << "Error on: " << loc->source_file << std::endl;
                    std::cout << "RuntimeException : " << exceptionClassName << std::endl;
                    std::cout << "Line: " << loc->row << std::endl;
                    std::cout << "Column: " << loc->column << std::endl;
                    std::cout << "--------------" << std::endl;
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Error loading MonoDebugSourceLocation" << std::endl;
                }
            }
            else
            {
                behavioursReturns.push_back(returnValue);
            }
        }
    }

    return behavioursReturns;
}

void CSharpHandle::ProjectEnvironment::LoadAssembles()
{

    std::string projectName = config["project-name"];
    std::ifstream file(projectName + ".csproj");

    std::string csprojContent((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    std::cout << &csprojContent[0] << std::endl;

    xml::xml_document<> csprojXml;

    csprojXml.parse<0>(&csprojContent[0]);
    xml::xml_node<> *netTarget = csprojXml.first_node()->first_node("PropertyGroup")->first_node("TargetFramework");
    std::cout << netTarget->value() << std::endl;

    std::string targetFolder(netTarget->value());
    std::string dllPath = "bin/Release/" + targetFolder + "/" + projectName + ".dll";
    if (isDev)
    {
        dllPath = "bin/Debug/" + targetFolder + "/" + projectName + ".dll";
    }
    std::cout << "Carregando assembly " << dllPath << std::endl;

    projectAssembly = mono_domain_assembly_open(this->projectDomain, dllPath.c_str());

    if (!projectAssembly)
    {
        std::cout << "Inicialização falhou" << std::endl;
    }
    else
    {
        std::cout << "Carregado com sucesso" << std::endl;
    }
}

void CSharpHandle::ProjectEnvironment::SearchForScripts()
{
}

void CSharpHandle::generateScriptProject(std::string &projectFolder, std::string &projectName)
{
    xml::xml_document<> doc;

    xml::xml_node<char> *projectNode = doc.allocate_node(xml::node_element, "Project");
    xml::xml_node<char> *propertyGroupNode = doc.allocate_node(xml::node_element, "PropertyGroup");
    xml::xml_node<char> *outputType = doc.allocate_node(xml::node_element, "OutputType");
    xml::xml_node<char> *nullable = doc.allocate_node(xml::node_element, "Nullable");
    xml::xml_node<char> *outputPath = doc.allocate_node(xml::node_element, "OutputPath");
    xml::xml_node<char> *implicitUsings = doc.allocate_node(xml::node_element, "ImplicitUsings");
    xml::xml_node<char> *targetFramework = doc.allocate_node(xml::node_element, "TargetFramework");

    char *outputTypeValue = doc.allocate_string("Library");
    outputType->value(outputTypeValue);

    char *targetFrameworkValue = doc.allocate_string("net7.0");
    targetFramework->value(targetFrameworkValue);

    char *outputPathValue = doc.allocate_string("Build");
    outputPath->value(outputPathValue);

    char *nullableValue = doc.allocate_string("enable");
    nullable->value(nullableValue);

    char *implicitUsingsValue = doc.allocate_string("enable");
    implicitUsings->value(implicitUsingsValue);

    projectNode->append_attribute(doc.allocate_attribute("Sdk", "Microsoft.NET.Sdk"));

    propertyGroupNode->append_node(outputType);
    propertyGroupNode->append_node(targetFramework);
    propertyGroupNode->append_node(outputPath);
    propertyGroupNode->append_node(nullable);
    propertyGroupNode->append_node(implicitUsings);

    projectNode->append_node(propertyGroupNode);

    doc.append_node(projectNode);

    std::ofstream csprojectFile(projectFolder + "/" + projectName + "/" + projectName + ".csproj");

    csprojectFile << doc;

    csprojectFile.close();
    std::string defaultGlobalClassName = "defaultClassGlobal";
    std::string defaultStorageClassName = "defaultStorageClass";
    std::string pathGlobal = projectFolder + "/" + projectName + "/global" + "/scripts/" + defaultGlobalClassName;
    std::string pathDefaultStorage = projectFolder + "/" + projectName + "/default" + "/scripts/" + defaultStorageClassName;
}
