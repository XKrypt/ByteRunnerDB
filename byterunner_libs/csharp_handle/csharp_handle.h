#ifndef CSHARP_HANDLE
#define CSHARP_HANDLE

// Mono
#include <mono-2.0/mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono-2.0/mono/metadata/debug-helpers.h>
#include <mono-2.0/mono/metadata/mono-debug.h>
#include <mono-2.0/mono/metadata/mono-config.h>
#include <mono-2.0/mono/metadata/object.h>
#include <mono/metadata/environment.h>
#include <mono-2.0/mono/metadata/mono-gc.h>
#include <vector>
// end Mono

#include "csharp_handle.h"
#include <sstream>
#include "../../libs/rapidxml/rapidxml.hpp"
#include "../../libs/rapidxml/rapidxml_print.hpp"
#include <iostream>
#include <fstream>
#include <cppfs/FilePath.h>
#include <../../libs/nlhoman/json.hpp>

using json = nlohmann::json;
namespace CSharpHandle
{
  class ProjectEnvironment
  {
  private:
    bool isDev = false;
    std::string projectFolder;
    MonoDomain *projectDomain;
    MonoAssembly *projectAssembly;
    std::vector<MonoClass *> runnerBehaviours;
    json config;
    void LoadAssembles();
    void CompileScripts();
    void SearchForScripts();
    void LoadClasses();

  public:
    std::unordered_map<std::string, MonoAssembly*> thirdPartyAssembles;
    ProjectEnvironment();
    ~ProjectEnvironment();
    void StartWatch();

    std::vector<MonoObject *> RunMethodFromBehaviours(std::string &methodName, void **args, int paramsCount);
    MonoObject *CreateClassInstance(const char *className, const char *classNamespace, MonoAssembly *assembly);
    void AddInternalMethod(const char *name, const void *method);
    MonoDomain *GetDomain();
    MonoAssembly *GetProjectAssemble();
  };

  void generateScriptProject(std::string &projectFolder, std::string &projectName);
}

#endif
