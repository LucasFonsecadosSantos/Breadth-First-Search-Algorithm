#include "../../include/model/file_handler.hpp"
#include "../../include/entity/graph.hpp"
#include "../../include/util/parser.hpp"
#include <iostream>
#include <vector>

void paddingAdjacencyMatrix(int **adjacencymatrix, std::vector<int*> *values) {
    unsigned long size = values->size();
    for (unsigned long i = 0 ; i < size ; i++) {
        adjacencymatrix[i] = new int[2];
        int *payload = values->at(i);
        adjacencymatrix[i][0] = payload[0];
        adjacencymatrix[i][1] = payload[1];
    }
}

int main(int argc, char **argv) {

    if (argc < 2) {
        return 1;
    }

    FileHandler *fileHandler = new FileHandler(argv[1]);
    std::vector<int*> *filepayload = new std::vector<int*>();
    
    unsigned int counter = 0;
    while (fileHandler->hasNextLine()) {
        char *line = fileHandler->getNextLine();
        int *pair =  Parser::getTokens(line);
        filepayload->push_back(pair);
        ++counter;
    }

    int** adjacencymatrix = new int*[filepayload->size()];
    paddingAdjacencyMatrix(adjacencymatrix, filepayload);
    Graph *graph = new Graph(adjacencymatrix,counter,2);
    

    return 0;
}
