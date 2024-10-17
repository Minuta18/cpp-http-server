#ifndef SOCKET_TCPSocket4_H_
#define SOCKET_TCPSocket4_H_

#include <string>

namespace http_server {
    class TCPSocket4 {
        std::string ip;
        int port;

        int server_socket;

        void setup_connection();
    public:
        TCPSocket4();
        TCPSocket4(const std::string& ip, const int port);
        TCPSocket4(const TCPSocket4& other);
        ~TCPSocket4();

        std::string get_ip();
        int get_port();

        TCPSocket4& operator=(const TCPSocket4& other);
    };
}

#endif // SOCKET_TCPSocket4_H
