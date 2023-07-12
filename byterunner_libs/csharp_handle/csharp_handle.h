#ifndef CSHARP_HANDLE
#define CSHARP_HANDLE
// Mono
// #include <mono-2.0/mono/jit/jit.h>
// #include <mono-2.0/mono/metadata/debug-helpers.h>
// #include <mono-2.0/mono/metadata/mono-config.h>
// #include <mono-2.0/mono/metadata/object.h>
// #include <mono/metadata/environment.h>
// #include <mono/metadata/mono-gc.h>
// end Mono

#include "csharp_handle.h"
#include "../../libs/rapidxml/rapidxml.hpp"
#include "../../libs/rapidxml/rapidxml_print.hpp"
#include <iostream>
#include <fstream>
#include <iostream>
namespace CSharpHandle
{
  class DevHandlerEvents 
  {
    DevHandlerEvents();
    ~DevHandlerEvents();
  };

  void generateScriptProject(std::string &projectFolder, std::string &projectName);
} 


#endif

