#include "utils.hpp"

#include "openssl/evp.h"
#include "openssl/sha.h"

#include <cstring>
#include <string>
using namespace std;
string utils::sha256(const string &s)
{
    const char *data = s.c_str();
    unsigned char res[SHA256_DIGEST_LENGTH] = { 0 };
    EVP_Digest(data, strlen(data), res, NULL, EVP_sha256(), NULL);
    char r[SHA256_DIGEST_LENGTH * 2 + 1] = { 0 };
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(r, "%02X", res[i]);
    return string(r);
}
string utils::pass(const string &s, const string &salt)
{
    return utils::sha256(s+salt);
}