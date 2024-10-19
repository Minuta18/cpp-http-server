#ifndef SOCKET_TCPSOCKET_H_
#define SOCKET_TCPSOCKET_H_

#include <string>
#include <exception>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>

namespace http_server {
    class TCPSocket {
        std::string ip;
        std::string port;

        int server_socket;
        addrinfo* server_addr;
        sockaddr_storage connections;

        void setup_connection();
    public:
        TCPSocket();
        TCPSocket(const std::string& ip, const int port);
        TCPSocket(const TCPSocket& other);
        ~TCPSocket();

        std::string get_ip();
        std::string get_port();

        void proceed();

        TCPSocket& operator=(const TCPSocket& other);
    };
}

#endif // SOCKET_TCPSOCKET_H_
