#pragma once
#include "openssl/evp.h"
#include "openssl/sha.h"

#include <cstring>
#include <string>
namespace utils
{
    std::string sha256(const std::string &s);
    std::string pass(const std::string &pass, const std::string &salt);
} // namespace utils
