#include "TCPSocket.h"
#include "../Application/Application.h"

namespace http_server {
    void TCPSocket::setup_connection() {
        
    }

    TCPSocket::TCPSocket() : ip(DEFAULT_IP), port(DEFAULT_PORT) {}
    
    TCPSocket::TCPSocket(
        const std::string& ip, const int port
    ) : ip(ip), port(port) {}
    
    TCPSocket::TCPSocket(const TCPSocket& other) {
        this->ip = other.ip;
        this->port = other.port;
    }
    
    TCPSocket::~TCPSocket() {};

    std::string TCPSocket::get_ip() { return this->ip; }
    int TCPSocket::get_port() { return this->port; }

    TCPSocket& TCPSocket::operator=(const TCPSocket& other) {
        if (this != &other) {
            this->ip = other.ip;
            this->port = other.port;
        }
        return *this;
    }
}
