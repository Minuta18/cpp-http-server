#include "HttpRequest.h"
#include "Methods.h"
#include "Protocols.h"

namespace http_server {
    HttpRequest::HttpRequest() : method(HttpMethod::GET), uri("/"), 
        protocol(HttpVersion::V2_0), body("") {}

    HttpRequest::HttpRequest(const HttpRequest& other) {
        method = other.method;
        uri = other.uri;
        protocol = other.protocol;
        body = other.body;
        headers = other.headers;
    }

    HttpRequest::HttpRequest(const std::string& request) {
        *this = HttpRequest::parse(request);
    }

    HttpRequest& HttpRequest::operator=(const HttpRequest& other) {
        if (this != &other) {
            this->method = other.method;
            this->uri = other.uri;
            this->protocol = other.protocol;
            this->body = other.body;
            this->headers = other.headers;
        }
        return *this;
    }

    static HttpRequest parse(const std::string& request) {
        
    }
}
