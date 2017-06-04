#include "CaminoMinimo.h"

CaminoMinimo::CaminoMinimo(Graph* g)
{
    n = g->getMaxSize();
    ultimo = new int[n];
    D = new int[n];
}

void CaminoMinimo::Dijkstra(Graph* g, int origen)
{
    s = origen;
    bool *F;
    F = new bool[n];
    for(int i = 0; i < n; i++)
    {
        F[i] = false;
        D[i] = g->getPeso(s, i);
        ultimo[i] = s;
    }
    F[s] = true;
    D[s] = 0;
    for(int i = 1; i < n; i++)
    {
        int v = minimo(F);
        //cout<<v<<"-";
        F[v] = true;
        for( int w = 0; w < n; w++)
        {
            if(!F[w])
            {

                if(D[v] + g->getPeso(v, w) < D[w])
                {
                    D[w] = D[v] + g->getPeso(v, w);
                    ultimo[w] = v;
                }
            }
        }
    }
}

int CaminoMinimo::minimo(bool F[])
{
    double mx = 0xFFFF;
    int v;
    for(int j = 0; j < n; j++)
    {
        if(!F[j] && (mx >= D[j]))
        {
            mx = D[j];
            v = j;
        }
    }
    return v;
}

void CaminoMinimo::recuperaCaminoAux(int v)
{
    myfile.open ("rutas_cal.txt", ios::out | ios::trunc);
    recuperaCamino(v);
    myfile.close();
}


void CaminoMinimo::recuperaCamino(int v)
{
    int anterior = ultimo[v];
    if(v != s)
    {
        recuperaCamino(anterior);
        myfile <<v<<"\n";
        cout<<v+1<<"V-->";
    }
    else
    {
        myfile <<s<<"\n";
        cout<<s+1<<"V-->";

    }
}

int *CaminoMinimo::OdistanciaMinima()
{
    return D;
}

int *CaminoMinimo::Oultimo()
{
    return ultimo;
}

CaminoMinimo::~CaminoMinimo()
{
    //dtor
}
