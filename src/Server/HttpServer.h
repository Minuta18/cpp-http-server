#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_

#include <string>

namespace http_server {
    class HttpServer {
        std::string addr;
        int port;
    };
}

#endif // SERVER_SERVER_H_
