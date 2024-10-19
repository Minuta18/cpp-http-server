#include <iostream>
#include "./Application/Application.h"

int main() {
    http_server::Application app("127.0.0.1", 3490);
    app.run();
}
