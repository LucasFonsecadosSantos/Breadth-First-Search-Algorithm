#include "../../include/entity/graph.hpp"
#include <cstddef>
#include <iostream>

Graph::Graph() {
    this->adjacencyMatrix = NULL;
    this->columnAmount = 0;
    this->rowAmount = 0;
}

Graph::Graph(int **adjacencymatrix, int rowamount, int columnamount) {
    this->adjacencyMatrix = adjacencymatrix;
    this->rowAmount = rowamount;
    this->columnAmount = columnamount;
}

Graph::~Graph() {

}

int** Graph::getAdjacencyMatrix() {
    return this->adjacencyMatrix;
}

inline void Graph::setColumnAmount(int amount) {
    this->columnAmount = amount;
}

inline void Graph::setRowAmount(int amount) {
    this->rowAmount = amount;
}

inline int Graph::getRowAmount() {
    return this->rowAmount;
}

inline int Graph::getColumnAmount() {
    return this->columnAmount;
}

void Graph::print() {
    for (unsigned long i = 0 ; i < this->rowAmount ; i++) {
        for (unsigned long j = 0 ; j < this->columnAmount ; j++) {
            std::cout << this->adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}