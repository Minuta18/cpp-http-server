#ifndef __REQUESTS_REQUESTS_H_
#define __REQUESTS_REQUESTS_H_

#include <string>
#include <unordered_map>

namespace http_server {
    typedef std::unordered_map<std::string, std::string> HeaderList; 

    class HttpRequest {
    public:
        std::string method;
        std::string uri;
        std::string protocol;
        std::string body;
        HeaderList headers;

        HttpRequest();
        HttpRequest(const std::string& request);
        HttpRequest(const HttpRequest& other);
        virtual ~HttpRequest();

        HttpRequest& operator=(const HttpRequest& other);

        static HttpRequest parse(const std::string& request);
    };
}

#endif // __REQUESTS_REQUESTS_H_
