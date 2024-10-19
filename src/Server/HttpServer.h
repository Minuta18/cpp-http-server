#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include <string>
#include <memory>
#include "../Utils/Consts.h"
#include "../Socket/TCPSocket.h"

namespace http_server {
    class HttpServer {
        std::string addr;
        int port;

        TCPSocket* socket;

        void init_socket();
    public:
        HttpServer();
        HttpServer(const std::string& addr, int port);

        virtual ~HttpServer();

        void run();
    };
}

#endif // SERVER_SERVER_H_
