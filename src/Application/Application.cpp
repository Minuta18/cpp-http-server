#include "Application/Application.h"

namespace http_server {
    Application::Application(const std::string& ip, int port) : 
        ip(ip), port(port) {
        server = new HttpServer(ip, port);
    }

    Application::Application(const Application& other) {
        ip = other.ip;
        port = other.port;
        delete server;
        server = new HttpServer(ip, port);
    }
    
    Application::~Application() {
        delete server;
    }

    void Application::run() {
        server->run();
    }

    Application& Application::operator=(const Application& other) {
        if (this != &other) {
            this->ip = other.ip;
            this->port = other.port;
            delete server;
            server = new HttpServer(ip, port);
        }
        return *this;
    }
}
