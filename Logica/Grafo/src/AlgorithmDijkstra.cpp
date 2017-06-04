#include "AlgorithmDijkstra.h"

//Constructor de la clase
AlgorithmDijkstra::AlgorithmDijkstra(Graph* g)
{
    max = g->getMaxSize();
    minPath = new int[max];
    last = new int[max];

}

//Devuelve el valor menor
int AlgorithmDijkstra::min(bool matrix[])
{
    double infinite = 0xFFFF;
    int minValue;
    for(int j = 0; j < max; j++)
    {
        if(!matrix[j] && (infinite >= minPath[j]))
        {
            infinite = minPath[j];
            minValue = j;
        }
    }
    return minValue;
}

//Escribe los nodos por visitar  en un archivo
void AlgorithmDijkstra::getPath(int destination)
{
    myfile.open ("rutas_cal.txt", ios::out | ios::trunc);
    getPathAux(destination);
    myfile.close();
}


//Imprime y escribe de manera recursiva la ruta a seguir
void AlgorithmDijkstra::getPathAux(int destination)
{
    int lastDestination = last[destination];
    if(destination != origin)
    {
        getPathAux(lastDestination);
        myfile <<destination<<"\n";
        cout<<destination+1<<"V-->";
    }
    else
    {
        myfile <<origin<<"\n";
        cout<<origin+1<<"V-->";

    }
}

//Retorna el peso de la ruta
int AlgorithmDijkstra::getDistance(int destination)
{
    return minPath[destination];
}

//Ejecuta el algoritmo de Dijkstra con el vértice de origen como parámetro
void AlgorithmDijkstra::Dijkstra(Graph* g, int origen)
{
    origin = origen;
    bool *matrix;
    matrix = new bool[max];

    for(int i = 0; i < max; i++)
    {
        matrix[i] = false;
        minPath[i] = g->getPeso(origin, i);
        last[i] = origin;
    }

    matrix[origin] = true;
    minPath[origin] = 0;
    for(int i = 1; i < max; i++)
    {
        int minValue = min(matrix);
        //cout<<minValue<<"-";
        matrix[minValue] = true;
        for( int w = 0; w < max; w++)
        {
            if(!matrix[w])
            {

                if(minPath[minValue] + g->getPeso(minValue, w) < minPath[w])
                {
                    minPath[w] = minPath[minValue] + g->getPeso(minValue, w);
                    last[w] = minValue;
                }
            }
        }
    }
}

//Destructor de la clase
AlgorithmDijkstra::~AlgorithmDijkstra()
{
   delete last;
   delete minPath;
}
