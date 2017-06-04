#ifndef CAMINOMINIMO_H
#define CAMINOMINIMO_H
#include <fstream>
#include "Graph.h"
#include <iostream>

using namespace std;

class AlgorithmDijkstra
{
    public:
        AlgorithmDijkstra(Graph* g);
        ~AlgorithmDijkstra();
        int getDistance(int destination);
        void getPathAux(int destination);
        void getPath(int destination);
        void Dijkstra(Graph* g, int origen);

    protected:
        int pesoTotal;
        int origin;
        int max;
        int *last;
        int *minPath;
        std::string textline;
        fstream myfile;
        int min(bool matrix[]);
};

#endif // ALGORITHMDIJKSTRA_H
