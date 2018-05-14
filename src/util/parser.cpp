#include "../../include/util/parser.hpp"
#include <string>
#include <iostream>

int* Parser::getTokens(std::string line) {
    std::string token;
    int *information = new int[2];

    for (unsigned i = 0 ; i < line.size() ; i++) {
        if (line[i] != ' ')
            token += line[i];
        else {
            information[0] = std::stoi(token);
            token = "";
        }
    }
    information[1] = std::stoi(token);
    std::cout << information[0] << "asopkkopas";
    return information;
}