#include "../../include/model/file_handler.hpp"
#include <iostream>

FileHandler::FileHandler(const char *filename) {
    this->currentLine = 0;
    this->buffer = new std::vector<char*>();
    this->readFile(filename);
}

FileHandler::~FileHandler() {
    unsigned long bufferSize = this->buffer->size();
    for (unsigned long i = 0 ; i < bufferSize ; i++) {
        this->buffer->erase(this->buffer->begin(), this->buffer->end());
    }
}

bool FileHandler::hasNextLine() {
    return (this->currentLine < this->buffer->size());
}

char* FileHandler::getNextLine() {
    if (hasNextLine())
        return this->buffer->at(this->currentLine++);
    return NULL;
}

void FileHandler::readFile(const char *filename) {
    this->file.open(filename);
    std::cout << filename;
    std::string line;
    if (this->file.is_open()) {
        std::cout << "niceindinao";
    } else {
        std::cout << "karai";
    }
    while (std::getline(this->file, line)) {
        if (line.size() == 0)
            continue;
        char *lineBuffer = new char[line.size()];
        line.copy(lineBuffer, line.size(), 0);
        lineBuffer[line.size()] = '\0';
        this->buffer->push_back(lineBuffer);
    }
    this->file.close();
}

