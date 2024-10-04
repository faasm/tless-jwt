#include <iostream>
#include <string>

namespace tless {
bool verify_jwt(const std::string& jwt)
{
    return verify_jwt(jwt.c_str());
}
}
