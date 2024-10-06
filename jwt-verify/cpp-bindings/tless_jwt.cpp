#include "tless_jwt.h"

#include <iostream>
#include <string>

namespace tless::jwt {
bool verify(const std::string& jwt)
{
    return verify_jwt(jwt.c_str());
}

bool checkProperty(const std::string& jwt, const std::string& property, char* expectedValue)
{
    return check_property(jwt.c_str(), property.c_str(), expectedValue);
}
}
