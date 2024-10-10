#include "./Application.h"

namespace http_server {
    Application::Application() : ip(DEFAULT_IP), port(DEFAULT_PORT) {}
    Application::Application(std::string ip, int port) : ip(ip), port(port) {}
    Application::Application(const Application& other) {
        ip = other.ip;
        port = other.port;
    }
    Application::~Application() {}

    Application& Application::operator=(const Application& other) {
        if (this != &other) {
            this->ip = other.ip;
            this->port = other.port;
        }
        return *this;
    }
}
