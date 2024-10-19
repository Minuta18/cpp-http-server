#ifndef __UTILS_CONSTS_H_
#define __UTILS_CONSTS_H_

#include <string>

namespace http_server {
    const std::string DEFAULT_IP = "127.0.0.1";
    const std::string DEFAULT_PORT_STR = "8000";
    const int DEFAULT_PORT = std::stoi(DEFAULT_PORT_STR);
    const int DEFAULT_MAX_CONNECTIONS = 16;
}

#endif // __UTILS_CONSTS_H_
