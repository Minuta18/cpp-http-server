#include "TCPSocket.h"
#include "../Application/Application.h"
#include <cstring>

namespace http_server {
    void TCPSocket::setup_connection() {
        addrinfo hints;
        std::memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        int addr_res = getaddrinfo(NULL, port.c_str(), &hints, &server_addr);
        if (addr_res != 0) {
            std::cerr << "getaddrinfo: " << gai_strerror(addr_res) << std::endl;
        }
    }

    TCPSocket::TCPSocket() : ip(DEFAULT_IP), port(DEFAULT_PORT_STR) {}
    
    TCPSocket::TCPSocket(
        const std::string& ip, const int port
    ) : ip(ip) {
        this->port = std::to_string(port);
    }
    
    TCPSocket::TCPSocket(const TCPSocket& other) {
        this->ip = other.ip;
        this->port = other.port;
    }
    
    TCPSocket::~TCPSocket() {};

    std::string TCPSocket::get_ip() { return this->ip; }
    std::string TCPSocket::get_port() { return this->port; }

    TCPSocket& TCPSocket::operator=(const TCPSocket& other) {
        if (this != &other) {
            this->ip = other.ip;
            this->port = other.port;
        }
        return *this;
    }
}
