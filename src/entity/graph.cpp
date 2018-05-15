#include "../../include/entity/graph.hpp"
#include <cstddef>
#include <iostream>

Graph::Graph() {
    this->adjacencyMatrix = NULL;
    this->description = NULL;
    this->columnAmount = 0;
    this->rowAmount = 0;
}

Graph::Graph(int **description, int rowamount, int columnamount) {
    this->description = description;
    this->rowAmount = rowamount;
    this->columnAmount = columnamount;
    this->vertexAmount = 0;
    makeAdjacencyMatrix();
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
            std::cout << this->description[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl << std::endl;

    for (unsigned long i = 0 ; i < this->vertexAmount ; i++) {
        for (unsigned long j = 0 ; j < this->vertexAmount ; j++) {
            std::cout << this->adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::makeAdjacencyMatrix() {
    int highestValue = getTheHighestValue(this->description, this->rowAmount, this->columnAmount);
    
    this->adjacencyMatrix = new int*[highestValue];

    for (unsigned long i = 0 ; i < highestValue ; i++)
        this->adjacencyMatrix[i] = new int[highestValue];
    //ERRO TA AQUI
    for (unsigned long i = 0 ; i < this->rowAmount ; i++ )
        this->adjacencyMatrix[description[i][0]][description[i][1]] = 1;

}

int Graph::getTheHighestValue(int **description, int rowamount, int columnamount) {
    int highestValue = 0;
    for (int i = 0 ; i < this->rowAmount ; i++) {
        for (int j = 0 ; j < 2; j++) {
            if (description[i][j] > highestValue) {
                highestValue = description[i][j];
            }
        }
    }
    this->vertexAmount = highestValue;
    return highestValue;
}