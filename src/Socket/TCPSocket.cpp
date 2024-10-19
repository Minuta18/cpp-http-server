#include "TCPSocket.h"
#include "../Application/Application.h"
#include "../Utils/Exc.h"
#include "../Utils/Consts.h"

#include <cstring>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void sigchld_handler(int s) {
    int saved_errno = errno;
    while (waitpid(-1, nullptr, WNOHANG) > 0) {}
    errno = saved_errno;
}

void* get_in_addr(sockaddr* sa) {
    if (sa->sa_family == AF_INET) {
        return &(((sockaddr_in*) sa)->sin_addr);
    }
    return &(((sockaddr_in6*) sa)->sin6_addr);
}

namespace http_server {
    void TCPSocket::setup_connection() {
        addrinfo hints;
        std::memset(&hints, 0, sizeof hints);
        hints.ai_family = AF_UNSPEC;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_PASSIVE;

        int addr_res = getaddrinfo(NULL, port.c_str(), &hints, &server_addr);
        if (addr_res != 0) {
            std::cerr << "getaddrinfo: " << gai_strerror(addr_res) 
                << std::endl;
            throw SocketException("getaddrinfo failed");
        }

        addrinfo *p;
        for (p = server_addr; p != nullptr; p = p->ai_next) {
            std::cout << "Trying to bind " << p->ai_canonname << std::endl;
            server_socket = socket(
                p->ai_family, p->ai_socktype, p->ai_protocol);
            if (server_socket == -1) {
                std::cerr << "server: socket" << std::endl;
                continue;
            }

            int yes = 1;
            if (setsockopt(
                server_socket, SOL_SOCKET, SO_REUSEADDR, 
                &yes, sizeof(int)) == -1
            ) {
                std::cerr << "server: setsockopt failed" << std::endl;
                throw SocketException("setsockopt failed");
            }

            if (bind(server_socket, p->ai_addr, p->ai_addrlen) == -1) {
                close(server_socket);
                std::cerr << "server: bind failed" << std::endl;
                continue;
            }
        }

        if (p == nullptr) {
            std::cerr << "server: bind failed" << std::endl;
            throw SocketException("bind failed");
        }

        if (listen(server_socket, DEFAULT_MAX_CONNECTIONS) == -1) {
            std::cerr << "server: listen failed" << std::endl;
            throw SocketException("listen failed");
        }

        struct sigaction sa;
        sa.sa_handler = sigchld_handler;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = SA_RESTART;
        if (sigaction(SIGCHLD, &sa, nullptr) == -1) {
            std::cerr << "server: sigaction failed" << std::endl;
            throw SocketException("sigaction failed");
        }

        std::cout << "server: waiting for connections..." << std::endl;
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
    
    TCPSocket::~TCPSocket() {
        freeaddrinfo(server_addr);
    };

    std::string TCPSocket::get_ip() { return this->ip; }
    std::string TCPSocket::get_port() { return this->port; }

    void TCPSocket::proceed() {
        socklen_t sin_size = sizeof connections;
        int conn = accept(
            server_socket, (struct sockaddr*)&connections, &sin_size
        );
        if (conn == -1) return;

        char buff[INET6_ADDRSTRLEN];
        inet_ntop(connections.ss_family,
            get_in_addr((sockaddr*)&connections),
            buff, sizeof buff
        );
        std::cout << "server: got connection from " << buff << std::endl;

        if (!fork()) {
            close(server_socket);
            if (send(conn, 
                "HTTP/1.1 200 OK\nServer: CppHttpServer\n"
                "Content-Type: text/html\nContent-Length: 23\n\n" 
                "<h1>Hello, world!</h1>\n", 106, 0) == -1) {
                std::cerr << "server: send failed" << std::endl;
            }
            close(conn);
            exit(0);
        }

        close(conn);
    }

    TCPSocket& TCPSocket::operator=(const TCPSocket& other) {
        if (this != &other) {
            this->ip = other.ip;
            this->port = other.port;
        }
        return *this;
    }
}
