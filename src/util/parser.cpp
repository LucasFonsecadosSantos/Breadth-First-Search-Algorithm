#include "../../include/util/parser.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

int* Parser::getTokens(std::string line) {
    std::string token;
    int *information = new int[2];

    for (unsigned i = 0 ; i < line.size() ; i++) {
        if (line[i] != ' ')
            token += line[i];
        else {
            information[0] = atoi(token.c_str());
            token = "";
        }
    }
    information[1] = atoi(token.c_str());
    return information;
}
