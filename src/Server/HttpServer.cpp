#include "HttpServer.h"

namespace http_server {
    void HttpServer::init_socket() {
        socket = new TCPSocket(addr, port);
    }

    HttpServer::HttpServer() : addr(DEFAULT_IP), port(DEFAULT_PORT) {
        init_socket();
    }

    HttpServer::HttpServer(const std::string& addr, int port) : 
        addr(addr), port(port) {
        init_socket();
    }

    HttpServer::~HttpServer() {
        delete socket;
    }

    void HttpServer::run() {
        while (true) {
            socket->proceed();
        }
    }
}
