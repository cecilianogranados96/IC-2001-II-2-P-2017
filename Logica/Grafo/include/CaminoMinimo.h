#ifndef CAMINOMINIMO_H
#define CAMINOMINIMO_H
#include <fstream>
#include "Graph.h"
#include <iostream>

using namespace std;

class CaminoMinimo
{
    public:
        CaminoMinimo(Graph* g);
        void Dijkstra(Graph* g, int origen);
        void recuperaCamino(int v);
        void recuperaCaminoAux(int v);
        int *OdistanciaMinima();
        int *Oultimo();
        virtual ~CaminoMinimo();

    private:
        int s, n;
        int minimo(bool F[]);

    protected:
        int *ultimo;
        int *D;
        std::string textline;
        fstream myfile;
        int pesoTotal;
};

#endif // CAMINOMINIMO_H
