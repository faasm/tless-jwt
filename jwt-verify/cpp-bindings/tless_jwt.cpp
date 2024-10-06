#include "tless_jwt.h"

#include <iostream>
#include <string>

namespace tless::jwt {
bool verify(const std::string& jwt)
{
    return verify_jwt(jwt.c_str());
}

bool checkProperty(const std::string& jwt, const std::string& property, const std::string& expVal)
{
    return check_property(jwt.c_str(), property.c_str(), expVal.c_str());
}
}
