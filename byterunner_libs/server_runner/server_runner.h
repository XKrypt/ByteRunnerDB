#ifndef SERVER_RUNNER
#define SERVER_RUNNER

#include <iostream>
#include <../../libs/nlhoman/json.hpp>
#include "../database_manager/database_manager.h"
#include <evpp/tcp_server.h>
#include <evpp/buffer.h>
#include <unordered_set>
#include <vector>
using json = nlohmann::json;
namespace Server
{

    struct Buffer
    {
        evpp::Buffer* buffer;

        std::string allString;
    };
    

    std::unordered_set<evpp::TCPConnPtr> *connections = nullptr;
    class ServerRunner
    {
    private:
        std::string projectFolder;
        int port;
        json configs;
        evpp::TCPServer *server;
        std::vector<std::function<void(const evpp::TCPConnPtr &)>> onNewConnection;
        std::vector<std::function<void(const evpp::TCPConnPtr &, Buffer)>> onReceiveData;
        evpp::EventLoop *loop;
        std::unordered_set<evpp::TCPConnPtr> connections;
        void OnConnection(const evpp::TCPConnPtr &conn);
        void OnMessage(const evpp::TCPConnPtr &conn, evpp::Buffer *buf);

    public:
        ServerRunner();
        ~ServerRunner();

        void StartHost();

        void OnNewConnectEventRegister(std::function<void(const evpp::TCPConnPtr &)>);
        void OnReceiveDataEventRegister(std::function<void(const evpp::TCPConnPtr &, Buffer)> func);
    };


}
#endif