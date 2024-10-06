#pragma once

#include <string>

extern "C" {
bool verify_jwt(const char* jwt);
}

namespace tless::jwt {
bool verify(const std::string& jwt);
}
