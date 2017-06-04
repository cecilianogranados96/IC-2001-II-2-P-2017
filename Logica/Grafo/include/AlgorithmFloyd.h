#ifndef TODOCAMINOMINIMO_H
#define TODOCAMINOMINIMO_H
#include <fstream>
#include "Graph.h"
#include <iostream>

using namespace std;

class AlgorithmFloyd
{
    public:
        AlgorithmFloyd(Graph* g);
        void Floyd();
        int getDistance(int origen, int destino);
        void getPath(int i, int j);
        void getPathAux(int i, int j);
        ~AlgorithmFloyd();
        void print();
        void printD();

    private:
        std::string textline;
        fstream myfile;
        int max;
        int **pathM;
        int **dM;
};

#endif // ALGORITHMFLOYD_H
