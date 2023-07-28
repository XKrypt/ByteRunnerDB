#include <fstream>
#include "server_runner.h"
#include <iostream>
#include <../../libs/nlhoman/json.hpp>
#include "../database_manager/database_manager.h"
#include <evpp/tcp_server.h>
#include <evpp/tcp_conn.h>
#include <evpp/buffer.h>
#include <unordered_set>
#include <boost/filesystem.hpp>
using json = nlohmann::json;
using namespace Server;
namespace fs = boost::filesystem;
Server::ServerRunner::ServerRunner()
{
    std::string currentPath = fs::current_path().string();
    this->projectFolder = currentPath;
    cppfs::FilePath configPath(projectFolder + "/runner-project.json");
    std::cout << configPath.path() << std::endl;
    std::ifstream config(configPath.path());

    json configs = json::parse(config);

    this->configs = configs;
    this->projectFolder = projectFolder;
    this->port = configs["port"];

    std::cout << "Port set to " << this->port << std::endl;
    std::cout << "Folder Path : " << this->projectFolder << std::endl;
    config.close();

    Server::connections = &connections;
}

Server::ServerRunner::~ServerRunner()
{
}
void Server::ServerRunner::OnNewConnectEventRegister(std::function<void(const evpp::TCPConnPtr &)> func)
{
    onNewConnection.push_back(func);
}

void Server::ServerRunner::OnReceiveDataEventRegister(std::function<void(const evpp::TCPConnPtr &,  Buffer)> func)
{
    onReceiveData.push_back(func);
}

void Server::ServerRunner::StartHost()
{
    evpp::EventLoop loop;
    std::cout << "Port set to " << this->port << std::endl;
    std::string addr = "127.0.0.1:4848";
    std::cout << "Address is : " << addr << std::endl;
    evpp::TCPServer server(&loop, addr, "Dev Runner Server", 4);

    this->server = &server;
    this->loop = &loop;
    this->server->SetConnectionCallback([this](const evpp::TCPConnPtr &conn)
                                        { this->OnConnection(conn); });
    this->server->SetMessageCallback([this](const evpp::TCPConnPtr &conn, evpp::Buffer *buf)
                                     { this->OnMessage(conn, buf); });
    this->server->Init();
    this->server->Start();
    this->loop->Run();
}

void Server::ServerRunner::OnConnection(const evpp::TCPConnPtr &connection)
{

    if (connection.get()->IsConnected())
    {
        std::cout << "Nova conexão estabelecida: " << connection->remote_addr() << " id:" << connection->id() << std::endl;

        // Adicionar a conexão ao contêiner
        this->connections.insert(connection);
    }
    else
    {
        std::cout << "Conexão encerrada: " << connection->remote_addr() << std::endl;

        connections.erase(connection);
    }
}
void Server::ServerRunner::OnMessage(const evpp::TCPConnPtr &conn, evpp::Buffer *buf)
{
    std::string message = buf->NextAllString();
    std::cout << "Mensagem recebida de " << conn->remote_addr() << ": " << message << std::endl;
    std::cout << "Size of events" << onReceiveData.size() << std::endl;
    Buffer buff;

    buff.allString = message;
    buff.buffer = buf;
    for (int i = 0; i < onReceiveData.size(); i++)
    {
        onReceiveData[i](conn, buff);
    }
}