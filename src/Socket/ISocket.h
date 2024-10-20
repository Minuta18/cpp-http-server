#ifndef SOCKET_ISOCKET_H_
#define SOCKET_ISOCKET_H_

#include <string>
#include <functional>

namespace http_server {
    typedef std::function<std::string(int)> socket_reply_handler;

    class ISocket {
    public:
        ISocket() {}
        ISocket(const std::string& ip, const int port) {}
        ISocket(const ISocket& other) {}
        virtual ~ISocket() {};
        
        virtual std::string get_ip() = 0;
        virtual std::string get_port() = 0;
        virtual socket_reply_handler get_reply_handler() = 0;
        virtual void set_reply_handler(socket_reply_handler handler) = 0;
        virtual void proceed() = 0;

        ISocket& operator=(const ISocket& other) { return *this; }
    };
}

#endif // SOCKET_ISOCKET_H
