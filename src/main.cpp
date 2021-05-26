#include "openssl/evp.h"
#include "openssl/sha.h"

#include <cstring>
#include <drogon/HttpAppFramework.h>
#include <iostream>
#include <texcaller.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    char opt;
    while ((opt = getopt(argc, argv, "c:h")) != -1)
        switch (opt)
        {
            case 'c':
                drogon::app().loadConfigFile(optarg);
                drogon::app().run();
                break;
            case 'h':
            default:
                std::cout << "Usage: \n"
                          << "./QABuilder -c ./config.json" << std::endl;
                break;
        }
}