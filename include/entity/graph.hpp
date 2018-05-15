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
        int rowAmount;
        int columnAmount;
        inline void setColumnAmount(int amount);
        inline void setRowAmount(int amount);

};

#endif