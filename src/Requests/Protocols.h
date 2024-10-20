#ifndef __REQUESTS_PROTOCOLS_H_
#define __REQUESTS_PROTOCOLS_H_

#include <string>

#include "../Utils/Macros.h"

namespace http_server {
    class HttpVersion {
    public:
        ENUM_STR V0_9 = "V0_9";
        ENUM_STR V1_0 = "V1_0";
        ENUM_STR V1_1 = "V1_1";
        ENUM_STR V2_0 = "V2_0";
    };
}

#endif // __REQUESTS__PROTOCOLS_H_
