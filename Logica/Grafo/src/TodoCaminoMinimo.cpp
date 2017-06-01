#include "TodoCaminoMinimo.h"

typedef int * pint;

TodoCaminoMinimo::TodoCaminoMinimo(Graph* g)
{
    n = g->getMaxSize();
    D = new pint[n];
    traza = new pint[n];
    for(int i = 0; i < n; i++)
    {
        D[i] = new int[n];
        traza[i] = new int[n];
        for(int j = 0; j < n; j++)
        {
            D[i][j] = g->getPeso(i, j);
            traza[i][j] = -1;
        }
    }
}

int **TodoCaminoMinimo::Otraza()
{
    return traza;
}

int **TodoCaminoMinimo::Odistancia()
{
    return D;
}

void TodoCaminoMinimo::Floyd()
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        D[i][i] = 0;
    }

    for(k = 0; k < n; k++)
    {
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if((D[i][k] + D[k][j]) < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    traza[i][j] = k;
                }

            }
        }

    }
}

void TodoCaminoMinimo::recuperaCamino(int i, int j)
{
    myfile.open ("rutas_cal.txt", ios::out | ios::trunc);

    cout<<"V"<<i+1<<"->";
    myfile <<i<<"\n";
    if(traza[i][j]!=-1)
        recupera(i, j);
    myfile <<j<<"\n";
    cout<<"V"<<j+1;
    myfile.close();

}

void TodoCaminoMinimo::recupera(int i, int j)
{
    int k = traza[i][j];
    if(k != -1)
    {
        recupera(i, k);
        myfile <<k<<"\n";
        cout<<"V"<<k+1<<"->";
        recupera(k, j);
    }
}

void TodoCaminoMinimo::print()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<traza[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

void TodoCaminoMinimo::printD()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<D[i][j]<<"\t";
        }
        cout<<"\n";
    }
}
TodoCaminoMinimo::~TodoCaminoMinimo()
{

}
