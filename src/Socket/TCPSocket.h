#ifndef __SOCKET_TCPSOCKET_H_
#define __SOCKET_TCPSOCKET_H_

#include <string>
#include <exception>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <functional>

#include "ISocket.h"

namespace http_server {
    class TCPSocket : ISocket {
        std::string ip;
        std::string port;

        int server_socket;
        addrinfo* server_addr;
        sockaddr_storage connections;
        socket_reply_handler reply_handler;

        void setup_connection();
    public:
        TCPSocket();
        TCPSocket(const std::string& ip, const int port);
        TCPSocket(const TCPSocket& other);
        ~TCPSocket();

        std::string get_ip();
        std::string get_port();
        socket_reply_handler get_reply_handler();
        void set_reply_handler(socket_reply_handler handler);
        void proceed();

        TCPSocket& operator=(const TCPSocket& other);
    };
}

#endif // _SOCKET_TCPSOCKET_H_
