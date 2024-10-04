#pragma once

#include <string>

extern "C" {
bool verify_jwt(const char* jwt);
}

namespace tless {
bool verify_jwt(const std::string& jwt);
}
