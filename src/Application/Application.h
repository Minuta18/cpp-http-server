#ifndef APPLICATION_APPLICATION_
#define APPLICATION_APPLICATION_

#include <string>

namespace http_server {
    const std::string DEFAULT_IP = "127.0.0.1";
    const int DEFAULT_PORT = 8000;

    class Application {
        std::string ip;
        int port;
    public:
        Application();
        Application(std::string ip, int port);
        Application(const Application& other);
        ~Application();

        Application& operator=(const Application& other);
    };
}

#endif // APPLICATION_APPLICATION_
