#include "../../include/model/file_handler.hpp"
#include <iostream>

int main(int argc, char **argv) {

    if (argc < 2) {
        exit(1);
    }

    FileHandler *fileHandler = new FileHandler(argv[1]);
    std::vector<char*> *filepayload = new std::vector<char*>();

    while (fileHandler->hasNextLine()) {
        std::cout << fileHandler->getNextLine();
    }

    return 0;
}