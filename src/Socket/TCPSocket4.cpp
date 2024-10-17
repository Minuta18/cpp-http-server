#include "TCPSocket4.h"
#include "../Application/Application.h"

namespace http_server {
    void TCPSocket4::setup_connection() {
        
    }

    TCPSocket4::TCPSocket4() : ip(DEFAULT_IP), port(DEFAULT_PORT) {}
    
    TCPSocket4::TCPSocket4(
        const std::string& ip, const int port
    ) : ip(ip), port(port) {}
    
    TCPSocket4::TCPSocket4(const TCPSocket4& other) {
        this->ip = other.ip;
        this->port = other.port;
    }
    
    TCPSocket4::~TCPSocket4() {};

    std::string TCPSocket4::get_ip() { return this->ip; }
    int TCPSocket4::get_port() { return this->port; }

    TCPSocket4& TCPSocket4::operator=(const TCPSocket4& other) {
        if (this != &other) {
            this->ip = other.ip;
            this->port = other.port;
        }
        return *this;
    }
}
