#include "HttpRequest.h"
#include "Methods.h"
#include "Protocols.h"
#include "../Utils/Exc.h"

namespace http_server {
    void HttpRequest::parse_and_write_to_this(
        const std::string& request
    ) {
        // Parsing will be there
    }

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
        parse_and_write_to_this(request);
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
        return HttpRequest(request);
    }
}
