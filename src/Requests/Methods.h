#ifndef __REQUESTS_METHODS_H_
#define __REQUESTS_METHODS_H_

#include <string>

#define ENUM_STR inline static const std::string 

namespace http_server {
    // Its enum, trust me
    class HttpMethod {
    public:
        ENUM_STR CONNECT = "CONNECT";
        ENUM_STR DELETE = "DELETE";
        ENUM_STR GET = "GET";
        ENUM_STR HEAD = "HEAD";
        ENUM_STR OPTIONS = "OPTIONS";
        ENUM_STR PATCH = "PATCH";
        ENUM_STR POST = "POST";
        ENUM_STR PUT = "PUT";
        ENUM_STR TRACE = "TRACE";
    };
}

#endif // __REQUESTS__METHODS_H_
