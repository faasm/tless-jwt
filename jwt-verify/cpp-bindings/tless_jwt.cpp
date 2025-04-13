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

bool getProperty(const std::string& jwt, const std::string& property, std::string& propertyOut)
{
    char* result = get_property(jwt.c_str(), property.c_str());
    if (!result) {
        return "";
    }

    propertyOut = std::string(result);
    // Release Rust-side memory
    free_string(result);

    return propertyOut;
}
}
