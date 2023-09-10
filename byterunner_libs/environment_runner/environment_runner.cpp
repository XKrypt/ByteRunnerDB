
#include "environment_runner.h"
#include "../database_manager/database_manager.h"
#include "../csharp_handle/csharp_handle.h"
#include "../server_runner/server_runner.h"
#include "../../libs/nlhoman/json.hpp"
#include <filesystem>
#include <iostream>
#include <evpp/tcp_conn.h>
#include <evpp/buffer.h>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/mono-config.h>
#include <mono/metadata/object.h>
#include <mono/metadata/environment.h>
#include <mono/metadata/mono-gc.h>
#include <locale>
#include <codecvt>
#include <vector>
#include <sstream>

namespace fs = std::filesystem;
using json = nlohmann::json;

EnvironmentRunner::EnvironmentRunner()
{
	this->projectFolder = fs::current_path().string();
	cppfs::FilePath configPath(this->projectFolder + "/runner-project.json");
	std::cout << configPath.path() << std::endl;
	std::ifstream config(configPath.path());
	json jConfigs = json::parse(config);
	this->configs = jConfigs;


	void (*functionPtr)(int32_t) = &DisconnectClient;

	const void* constFunctionPtr = reinterpret_cast<const void*>(functionPtr);
	projectEnvironment.AddInternalMethod("RunnerBehaviour::DisconnectClient", constFunctionPtr);
}

void DisconnectClient(int32_t id)
{
	if (Server::connections == nullptr)
	{
		std::cout << "null pointer " << std::endl;
		return;
	}
	for (const auto& element : *Server::connections)
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

void EnvironmentRunner::EventsHandler(const evpp::TCPConnPtr& conn, Server::Buffer buffer)
{

	std::string data = buffer.allString;
	std::cout << data << "  DATA" << std::endl;
	try
	{
		json jsonData = json::parse(data);

		std::string operation = jsonData["operation"];
		std::string storage = jsonData["storage"];

		if (operation == "INSERT")
		{
			databaseManager.WriteNewDocument(storage.c_str(), jsonData["data"]);
		}

		if (operation == "OVERRIDE")
		{
			std::string docId = jsonData["id"];
			databaseManager.OverrideDocument(docId.c_str(), storage.c_str(), jsonData["data"]);
		}

		if (operation == "DELETE")
		{
			std::string docId = jsonData["id"];
			databaseManager.DeleteDocument(docId.c_str(), storage.c_str());
		}
	}
	catch (const json::parse_error& e)
	{
		std::cerr << "LINE 77: Environment runner" << '\n';
		std::cerr << e.what() << '\n';

		return;
	}
}



void EnvironmentRunner::StartEnvironment()
{
	this->projectEnvironment.StartWatch();
	this->serverRunner.OnNewConnectEventRegister([this](const evpp::TCPConnPtr& conn)
		{ this->OnNewConnection(conn); });
	this->serverRunner.OnReceiveDataEventRegister([this](const evpp::TCPConnPtr& conn, Server::Buffer buf)
		{ this->OnReceiveData(conn, buf); });
	this->serverRunner.StartHost();
}

void EnvironmentRunner::OnNewConnection(const evpp::TCPConnPtr& conn)
{
	std::cout << "Conectado: " << conn->AddrToString() << std::endl;
}

void EnvironmentRunner::OnReceiveData(const evpp::TCPConnPtr& conn, Server::Buffer buf)
{
	EventsHandler(conn, buf);

	std::string message = buf.allString;
	std::cout << "\n \n Message Received ------------------------ \n" << message << "\n ------------------- \n \n" << std::endl;
	this->RunOnReceiveDataBehaviours(conn, message);


}

void EnvironmentRunner::RunOnReceiveDataBehaviours(const evpp::TCPConnPtr& conn, std::string data)
{

	std::string methodName = "OnReceiveData";


	void* args[1];
	mono_jit_thread_attach(mono_get_root_domain());
	MonoString* messageMono = mono_string_new(mono_get_root_domain(), data.c_str());

	MonoObject* runnerDataClass = projectEnvironment.CreateClassInstance("DataRunner", "Runner", projectEnvironment.thirdPartyAssembles["RunnerLib"]);
	if (runnerDataClass == nullptr)
	{
		return;
	}
	MonoClass* runnerDataClassType = mono_object_get_class(runnerDataClass);
	MonoClassField* ipAddress = mono_class_get_field_from_name(runnerDataClassType, "ipAddress");
	MonoClassField* id = mono_class_get_field_from_name(runnerDataClassType, "id");
	MonoClassField* dataField = mono_class_get_field_from_name(runnerDataClassType, "data");

	std::ostringstream oss;
	oss << conn->id();
	std::string idString = oss.str();
	MonoString* ipAddresValue = mono_string_new(mono_get_root_domain(), conn->remote_addr().c_str());
	MonoString* idValue = mono_string_new(mono_get_root_domain(), idString.c_str());
	MonoString* dataValue = mono_string_new(mono_get_root_domain(), data.c_str());

	mono_field_set_value(runnerDataClass, ipAddress, ipAddresValue);
	mono_field_set_value(runnerDataClass, id, idValue);
	mono_field_set_value(runnerDataClass, dataField, dataValue);

	args[0] = runnerDataClass;
	projectEnvironment.RunMethodFromBehaviours(methodName, args, 1);
}

void EnvironmentRunner::RunOnWriteDataBehaviours(const evpp::TCPConnPtr& conn, std::string data)
{
	std::string methodName = "OnReceiveData";


	void* args[1];
	mono_jit_thread_attach(mono_get_root_domain());
	MonoString* messageMono = mono_string_new(mono_get_root_domain(), data.c_str());

	MonoObject* runnerDataClass = projectEnvironment.CreateClassInstance("DataRunner", "Runner", projectEnvironment.thirdPartyAssembles["RunnerLib"]);
	if (runnerDataClass == nullptr)
	{
		return;
	}
	MonoClass* runnerDataClassType = mono_object_get_class(runnerDataClass);
	MonoClassField* ipAddress = mono_class_get_field_from_name(runnerDataClassType, "ipAddress");
	MonoClassField* id = mono_class_get_field_from_name(runnerDataClassType, "id");
	MonoClassField* dataField = mono_class_get_field_from_name(runnerDataClassType, "data");

	std::ostringstream oss;
	oss << conn->id();
	std::string idString = oss.str();
	MonoString* ipAddresValue = mono_string_new(mono_get_root_domain(), conn->remote_addr().c_str());
	MonoString* idValue = mono_string_new(mono_get_root_domain(), idString.c_str());
	MonoString* dataValue = mono_string_new(mono_get_root_domain(), data.c_str());

	mono_field_set_value(runnerDataClass, ipAddress, ipAddresValue);
	mono_field_set_value(runnerDataClass, id, idValue);
	mono_field_set_value(runnerDataClass, dataField, dataValue);

	args[0] = runnerDataClass;
	projectEnvironment.RunMethodFromBehaviours(methodName, args, 1);
	
}

void EnvironmentRunner::RunOnUpdateDataBehaviours(const evpp::TCPConnPtr& conn, std::string data)
{
}

void EnvironmentRunner::RunOnConnectDataBehaviours(const evpp::TCPConnPtr& conn, std::string data)
{
}
