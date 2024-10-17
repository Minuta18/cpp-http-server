#ifndef SOCKET_TCPSOCKET_H_
#define SOCKET_TCPSOCKET_H_

#include <string>

namespace http_server {
    class TCPSocket {
        std::string ip;
        int port;

        int server_socket;

        void setup_connection();
    public:
        TCPSocket();
        TCPSocket(const std::string& ip, const int port);
        TCPSocket(const TCPSocket& other);
        ~TCPSocket();

        std::string get_ip();
        int get_port();

        TCPSocket& operator=(const TCPSocket& other);
    };
}

#endif // SOCKET_TCPSOCKET_H
