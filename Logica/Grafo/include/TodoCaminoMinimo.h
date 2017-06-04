#ifndef TODOCAMINOMINIMO_H
#define TODOCAMINOMINIMO_H
#include <fstream>
#include "Graph.h"
#include <iostream>

using namespace std;

class TodoCaminoMinimo
{
    public:
        TodoCaminoMinimo(Graph* g);
        int ** Otraza();
        int ** Odistancia();
        void Floyd();
        void recuperaCamino(int i, int j);
        void recupera(int i, int j);
        virtual ~TodoCaminoMinimo();
        void print();
        void printD();

    protected:
        int **traza;
        int **D;

    private:
        int n;
        std::string textline;
        fstream myfile;
};

#endif // TODOCAMINOMINIMO_H
