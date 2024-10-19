#ifndef APPLICATION_APPLICATION_H_
#define APPLICATION_APPLICATION_H_

#include <string>
#include "../Utils/Consts.h"
#include "../Server/HttpServer.h"

namespace http_server {
    class Application {
        std::string ip;
        int port;

        HttpServer* server;
    public:
        Application();
        Application(const std::string& ip, int port);
        Application(const Application& other);
        ~Application();

        void run();

        Application& operator=(const Application& other);
    };
}

#endif // APPLICATION_APPLICATION_H_
