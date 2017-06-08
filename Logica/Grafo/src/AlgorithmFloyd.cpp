#include "AlgorithmFloyd.h"

typedef int * matrix;
//################################
//#
//# OBJETIVO:
//# =========
//#
//# Implementación del alogoritmo de Floyd al grafo contrustruido anterioemente.
//#
//#
//# Desarrollo:
//#
//# - Silvia Calderón
//#
//#
//################################
//
AlgorithmFloyd::AlgorithmFloyd(Graph* g)
{
    max = g->getMaxSize();
    dM = new matrix[max];
    pathM = new matrix[max];
    for(int i = 0; i < max; i++)
    {
        dM[i] = new int[max];
        pathM[i] = new int[max];
        for(int j = 0; j < max; j++)
        {
            dM[i][j] = g->getPeso(i, j);
            pathM[i][j] = -1;
        }
    }
}

//Devuelve el valor de la ruta
int AlgorithmFloyd::getDistance(int origen, int destino)
{
    return dM[origen][destino];
}

//Ejecuta el algoritmo de Floyd
void AlgorithmFloyd::Floyd()
{
    int i, j, k;
    for(i = 0; i < max; i++)
    {
        dM[i][i] = 0;
    }

    for(k = 0; k < max; k++)
    {
        for(i = 0; i < max; i++)
        {
            for(j = 0; j < max; j++)
            {
                if((dM[i][k] + dM[k][j]) < dM[i][j])
                {
                    dM[i][j] = dM[i][k] + dM[k][j];
                    pathM[i][j] = k;
                }

            }
        }

    }
}

//Devuelve la ruta
void AlgorithmFloyd::getPath(int origen, int destino)
{
    myfile.open ("rutas_cal.txt", ios::out | ios::trunc);

    cout<<"V"<<origen+1<<"->";
    myfile <<origen<<"\max";
    if(pathM[origen][destino]!=-1)
        getPathAux(origen, destino);
    myfile <<destino<<"\max";
    cout<<"V"<<destino+1;
    myfile.close();

}

//Devuelve la ruta de una manera recursiva
void AlgorithmFloyd::getPathAux(int origen, int destino)
{
    int k = pathM[origen][destino];
    if(k != -1)
    {
        getPathAux(origen, k);
        myfile <<k<<"\n";
        cout<<"V"<<k+1<<"->";
        getPathAux(k, destino);
    }
}

//Imprime la tabla de rutas
void AlgorithmFloyd::print()
{
    for(int i=0; i<max; i++){
        for(int j=0; j<max; j++){
            cout<<pathM[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

//Imprime la última tabla de pesos creada
void AlgorithmFloyd::printD()
{
    for(int i=0; i<max; i++){
        for(int j=0; j<max; j++){
            cout<<dM[i][j]<<"\t";
        }
        cout<<"\n";
    }
}

//Destructor de la clase
AlgorithmFloyd::~AlgorithmFloyd()
{
    delete pathM;
    delete dM;
}
