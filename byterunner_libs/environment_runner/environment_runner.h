#ifndef ENVIRONMENT_RUNNER
#define ENVIRONMENT_RUNNER

#include "../database_manager/database_manager.h"
#include "../csharp_handle/csharp_handle.h"
#include "../server_runner/server_runner.h"
#include <iostream>
#include <evpp/tcp_conn.h>
#include <evpp/buffer.h>
#include "../../libs/nlhoman/json.hpp"

using json = nlohmann::json;
class EnvironmentRunner
{
private:
    CSharpHandle::ProjectEnvironment projectEnvironment;
    DatabaseManager databaseManager;
    Server::ServerRunner serverRunner;
    std::string projectFolder;
    json configs;

    void OnReceiveData(const evpp::TCPConnPtr& conn, evpp::Buffer *buf);
    void OnNewConnection(const evpp::TCPConnPtr& conn);


    void EventsHandler(const evpp::TCPConnPtr& conn, evpp::Buffer *buf);

public:
    EnvironmentRunner(/* args */);
    ~EnvironmentRunner();
    void StartEnvironment();
};

    static void DisconnectClient(int32_t id);



#endif