#ifndef GRAPH_H
#define GRAPH_H
#include "LinkedList.h"
#include <fstream>

class Graph
{
    public:
        Graph(int maxSize);
        ~Graph();
        int getMaxSize();
        LinkedList* getGraph();
        LinkedList* getGraphB();
        LinkedList* getWarshall();
        LinkedList* getKruskal();
        void addVertex(Aeropuerto* aeropuerto);
        void addEdge(int origen, int destino, int peso);
        int getPeso(int origen, int destino);
        bool adjacent(int origen, int destino);
        void print(LinkedList* grafo);
        void printB(LinkedList* grafo);
        void warshall();
        void kruskal();

    private:
        LinkedList* grafo;
        LinkedList* mWarshall;
        LinkedList* mKruskal;
        int maxSize;
        std::string textline;
        fstream myfile;
};

#endif // GRAPH_H
