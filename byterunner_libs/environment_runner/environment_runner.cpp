
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

    //Ponteiro para a função MyFunction
    void (*functionPtr)(int32_t) = &DisconnectClient;
    // Converter o ponteiro para const void*
    const void *constFunctionPtr = reinterpret_cast<const void *>(functionPtr);
    projectEnvironment.AddInternalMethod("RunnerBehaviour::DisconnectClient", constFunctionPtr);
}

void DisconnectClient(int32_t id){
  if(Server::connections == nullptr){
    std::cout << "null pointer " <<  std::endl;
    return;
  }
    for (const auto& element : *Server::connections) {
        if(element->id() == static_cast<int64_t>(id)){
            std::cout << "Disconnecting id :" << element->id() << std::endl;
            element->Close();
            break;
        }
    }
    
}

EnvironmentRunner::~EnvironmentRunner()
{
}

void EnvironmentRunner::StartEnvironment()
{
    this->projectEnvironment.StartWatch();
    this->serverRunner.OnNewConnectEventRegister([this](const evpp::TCPConnPtr &conn)
                                                 { this->OnNewConnection(conn); });
    this->serverRunner.OnReceiveDataEventRegister([this](const evpp::TCPConnPtr &conn, std::string &message)
                                                  { this->OnReceiveData(conn, message); });
    this->serverRunner.StartHost();
}

void EnvironmentRunner::OnNewConnection(const evpp::TCPConnPtr &conn)
{
    std::cout << "Conectado: " << conn->AddrToString() << std::endl;
}

void EnvironmentRunner::OnReceiveData(const evpp::TCPConnPtr &conn, std::string &message)
{
    std::string methodName = "OnMessage";
    void *args[1];
    mono_jit_thread_attach(mono_get_root_domain());
    MonoString *messageMono = mono_string_new(mono_get_root_domain(), message.c_str());
    args[0] = messageMono;
    projectEnvironment.RunMethodFromBehaviours(methodName, args, 1);

    std::cout << message << std::endl;
}