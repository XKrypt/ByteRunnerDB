
#include "environment_runner.h"
#include "../database_manager/database_manager.h"
#include "../csharp_handle/csharp_handle.h"
#include "../server_runner/server_runner.h"
#include "../../libs/nlhoman/json.hpp"
#include <boost/filesystem.hpp>
#include <iostream>
#include <evpp/tcp_conn.h>
#include <evpp/buffer.h>
#include <mono-2.0/mono/jit/jit.h>
#include <mono-2.0/mono/metadata/assembly.h>
#include <mono-2.0/mono/metadata/debug-helpers.h>
#include <mono-2.0/mono/metadata/mono-config.h>
#include <mono-2.0/mono/metadata/object.h>
#include <mono/metadata/environment.h>
#include <mono-2.0/mono/metadata/mono-gc.h>
#include <locale>
#include <codecvt>
#include <iconv.h>
#include <vector>
#include <sstream>

namespace fs = boost::filesystem;
using json = nlohmann::json;

EnvironmentRunner::EnvironmentRunner()
{
    this->projectFolder = fs::current_path().string();
    cppfs::FilePath configPath(this->projectFolder + "/runner-project.json");
    std::cout << configPath.path() << std::endl;
    std::ifstream config(configPath.path());
    json jConfigs = json::parse(config);
    this->configs = jConfigs;

    // Ponteiro para a função MyFunction
    void (*functionPtr)(int32_t) = &DisconnectClient;
    // Converter o ponteiro para const void*
    const void *constFunctionPtr = reinterpret_cast<const void *>(functionPtr);
    projectEnvironment.AddInternalMethod("RunnerBehaviour::DisconnectClient", constFunctionPtr);
}

void DisconnectClient(int32_t id)
{
    if (Server::connections == nullptr)
    {
        std::cout << "null pointer " << std::endl;
        return;
    }
    for (const auto &element : *Server::connections)
    {
        if (element->id() == static_cast<int64_t>(id))
        {
            std::cout << "Disconnecting id :" << element->id() << std::endl;
            element->Close();
            break;
        }
    }
}

EnvironmentRunner::~EnvironmentRunner()
{
}

void EnvironmentRunner::EventsHandler(const evpp::TCPConnPtr &conn, evpp::Buffer *buff)
{
    std::string data = buff->NextAllString();

    json jsonData;

    try
    {
        jsonData = json::parse(data);
    }
    catch (const json::parse_error &e)
    {
        std::cerr << e.what() << '\n';

        return;
    }

    std::string operation = jsonData["operation"];

}

void EnvironmentRunner::StartEnvironment()
{
    this->projectEnvironment.StartWatch();
    this->serverRunner.OnNewConnectEventRegister([this](const evpp::TCPConnPtr &conn)
                                                 { this->OnNewConnection(conn); });
    this->serverRunner.OnReceiveDataEventRegister([this](const evpp::TCPConnPtr &conn, evpp::Buffer *buf)
                                                  { this->OnReceiveData(conn, buf); });
    this->serverRunner.StartHost();
}

void EnvironmentRunner::OnNewConnection(const evpp::TCPConnPtr &conn)
{
    std::cout << "Conectado: " << conn->AddrToString() << std::endl;
}

void EnvironmentRunner::OnReceiveData(const evpp::TCPConnPtr &conn, evpp::Buffer *buf)
{
    std::string methodName = "OnReceiveData";

    std::string message = buf->NextAllString();
    void *args[1];
    mono_jit_thread_attach(mono_get_root_domain());
    MonoString *messageMono = mono_string_new(mono_get_root_domain(), message.c_str());

    MonoObject *runnerDataClass = projectEnvironment.CreateClassInstance("RunnerData", "", projectEnvironment.thirdPartyAssembles["RunnerLib"]);
    if (runnerDataClass == nullptr)
    {
        return;
    }
    MonoClass *runnerDataClassType = mono_object_get_class(runnerDataClass);
    MonoClassField *ipAddress = mono_class_get_field_from_name(runnerDataClassType, "ipAddress");
    MonoClassField *id = mono_class_get_field_from_name(runnerDataClassType, "id");
    MonoClassField *data = mono_class_get_field_from_name(runnerDataClassType, "data");

    std::ostringstream oss;
    oss << conn->id();
    std::string idString = oss.str();
    MonoString *ipAddresValue = mono_string_new(mono_get_root_domain(), conn->remote_addr().c_str());
    MonoString *idValue = mono_string_new(mono_get_root_domain(), idString.c_str());
    MonoString *dataValue = mono_string_new(mono_get_root_domain(), message.c_str());

    mono_field_set_value(runnerDataClass, ipAddress, ipAddresValue);
    mono_field_set_value(runnerDataClass, id, idValue);
    mono_field_set_value(runnerDataClass, data, dataValue);

    args[0] = runnerDataClass;
    projectEnvironment.RunMethodFromBehaviours(methodName, args, 1);

    std::cout << message << std::endl;
}