#ifndef __UTILS_EXC_Р_
#define __UTILS_EXC_Р_

#include <exception>

namespace http_server {
    class SocketException : public std::exception {
        char* message;
    public:
        SocketException() : message("Socket exception") {}
        SocketException(char* msg) : message(msg) {}

        char* what() {
            return message;
        }
    };
}

#endif // __UTILS_EXC_Р_

