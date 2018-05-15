#ifndef GRAPH_TYPE_H
#define GRAPH_TYPE_H 1

class Graph {

    public:
        Graph();
        Graph(int **adjacencyMatrix, int rowamount, int columnamount);
        ~Graph();
        int** getAdjacencyMatrix();
        void setAdjacencyMatrix(int **adjacencymatrix);
        inline int getColumnAmount();
        inline int getRowAmount();
        void print();

    private:
        int **adjacencyMatrix;
        int **description;
        int rowAmount;
        int columnAmount;
        int vertexAmount;
        inline void setColumnAmount(int amount);
        inline void setRowAmount(int amount);
        void makeAdjacencyMatrix();
        int getTheHighestValue(int **description, int rowamount, int columnamount);

};

#endif