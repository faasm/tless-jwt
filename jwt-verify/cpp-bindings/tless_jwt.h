#pragma once

#include <string>

extern "C" {
bool verify_jwt(const char* jwt);
bool check_property(const char* jwt, const char* property, const uint8_t* exp_value, size_t expValSize);
}

namespace tless::jwt {
bool verify(const std::string& jwt);
bool checkProperty(const std::string& jwt, const std::string& property, const uint8_t* expValPtr, size_t expValSize);
}
