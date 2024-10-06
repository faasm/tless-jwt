#include "tless_jwt.h"

#include <iostream>
#include <string>

namespace tless::jwt {
bool verify(const std::string& jwt)
{
    return verify_jwt(jwt.c_str());
}
}
