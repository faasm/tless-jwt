#pragma once

#include <string>

extern "C" {
bool verify_jwt(const char* jwt);
bool check_property(const char* jwt, const char* property, const char* exp_value);
}

namespace tless::jwt {
bool verify(const std::string& jwt);
bool checkProperty(const std::string& jwt, const std::string& property, char* expectedValue);
}
