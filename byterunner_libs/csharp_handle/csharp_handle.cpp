// Mono
#include <mono-2.0/mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono-2.0/mono/metadata/debug-helpers.h>
#include <mono-2.0/mono/metadata/mono-config.h>
#include <mono-2.0/mono/metadata/object.h>
#include <mono/metadata/environment.h>
#include <mono-2.0/mono/metadata/mono-gc.h>
//end Mono

#include "csharp_handle.h"
#include "../../libs/rapidxml/rapidxml.hpp"
#include "../../libs/rapidxml/rapidxml_print.hpp"
#include <iostream>
#include <fstream>
namespace xml = rapidxml;

void CSharpHandle::generateScriptProject(std::string &projectFolder, std::string &projectName)
{
    xml::xml_document<> doc;

    xml::xml_node<char> *projectNode = doc.allocate_node(xml::node_element, "Project");

    xml::xml_node<char> *propertyGroupNode = doc.allocate_node(xml::node_element, "PropertyGroup");
    xml::xml_node<char> *outputType = doc.allocate_node(xml::node_element, "OutputType");
    xml::xml_node<char> *targetFramework = doc.allocate_node(xml::node_element, "TargetFramework");
    xml::xml_node<char> *itemGroup = doc.allocate_node(xml::node_element, "ItemGroup");
    xml::xml_node<char> *compileNode = doc.allocate_node(xml::node_element, "Compile");
    xml::xml_node<char> *compileNodeDefaultStorage = doc.allocate_node(xml::node_element, "Compile");

    char *outputTypeValue = doc.allocate_string("Library");
    outputType->value(outputTypeValue);

    char *targetFrameworkValue = doc.allocate_string("net5.0");
    targetFramework->value(targetFrameworkValue);
    compileNode->append_attribute(doc.allocate_attribute("Include", "global/scripts/*.cs"));
    compileNodeDefaultStorage->append_attribute(doc.allocate_attribute("Include", "default/scripts/*.cs"));
    projectNode->append_attribute(doc.allocate_attribute("Sdk", "Microsoft.NET.Sdk"));

    propertyGroupNode->append_node(outputType);
    propertyGroupNode->append_node(targetFramework);

    itemGroup->append_node(compileNode);
    itemGroup->append_node(compileNodeDefaultStorage);

    projectNode->append_node(propertyGroupNode);
    projectNode->append_node(itemGroup);

    doc.append_node(projectNode);

    std::ofstream csprojectFile(projectFolder + "/" + projectName + "/" + projectName + ".csproj");

    

    csprojectFile << doc;

    csprojectFile.close();
    std::string defaultGlobalClassName = "defaultClassGlobal";
    std::string defaultStorageClassName = "defaultStorageClass";
    std::string pathGlobal = projectFolder + "/" + projectName + "/global" + "/scripts/" + defaultGlobalClassName;
    std::string pathDefaultStorage = projectFolder + "/" + projectName + "/default" + "/scripts/" + defaultStorageClassName;

}
