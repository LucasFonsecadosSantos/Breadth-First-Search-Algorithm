#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H 1

#include <fstream>
#include <vector>

class FileHandler {

    public:
        FileHandler(const char *filename);
        ~FileHandler();
        char* getNextLine();
        bool hasNextLine();

    private:
        unsigned long currentLine;
        std::fstream file;
        std::vector<char*> buffer;
        void readFile(const char *filename);

};

#endif