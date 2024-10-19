#ifndef __UTILS_EXC_Р_
#define __UTILS_EXC_Р_

#include <exception>
#include <string>

namespace http_server {
    class SocketException : public std::exception {
        std::string message;
    public:
        SocketException() : message("Socket exception") {}
        SocketException(std::string msg) : message(msg) {}

        const char* what() {
            return message.c_str();
        }
    };
}

#endif // __UTILS_EXC_Р_

