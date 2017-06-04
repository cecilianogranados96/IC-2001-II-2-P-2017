#include "Graph.h"

//Clase constructora
Graph::Graph(int maxSize)
{
    grafo = new LinkedList(maxSize);
    this->maxSize = maxSize;
}

LinkedList* Graph::getGraph()
{
    return grafo;
}

int Graph::getMaxSize()
{
    return maxSize;
}

LinkedList* Graph::getWarshall()
{
    return mWarshall;
}
//Añade un nuevo vértice
void Graph::addVertex(Aeropuerto* aeropuerto)
{
    grafo->append(aeropuerto);
}

//Añade una nueva arista
void Graph::addEdge(int origen, int destino, int peso)
{
    if(origen >= 0 && destino >= 0 && origen < grafo->getSize() && destino < grafo->getSize()){
        grafo->goToPos(origen);
        grafo->getCurr()->getListaAd()->goToPos(destino);
        grafo->getCurr()->getListaAd()->setValue(peso);
        grafo->getCurr()->getListaAdB()->goToPos(destino);
        grafo->getCurr()->getListaAdB()->setValue(peso);
    }
}

//Indica el peso de la arista entre el origen y el destino
int Graph::getPeso(int origen, int destino)
{
    if(origen >= 0 && destino >= 0 && origen < grafo->getSize() && destino < grafo->getSize()){
        grafo->goToPos(origen);
        if(destino >= 0 && destino < grafo->getCurr()->getListaAd()->getSize()){
            grafo->getCurr()->getListaAd()->goToPos(destino);
            return grafo->getCurr()->getListaAd()->getValue();
        }
        return -1;
    }
}

//Indica si son adyacentes los vertices
bool Graph::adjacent(int origen, int destino)
{
    if(origen >= 0 && destino >= 0 && origen < grafo->getSize() && destino < grafo->getSize()){
        grafo->goToPos(origen);
        if(destino >= 0 && destino < grafo->getCurr()->getListaAd()->getSize()){
            grafo->getCurr()->getListaAd()->goToPos(destino);
            if(grafo->getCurr()->getListaAd()->getValue() != 0)
                return true;
        }
        return false;
    }
}

//Imprime el grafo
void Graph::print(LinkedList* grafo)
{
    grafo->goToPos(0);
    cout<<"Grafo\n";
    for(int i = 0; i < grafo->getSize(); i++){
        grafo->goToPos(i);
        cout<<"Vertice: "<<grafo->getCurrValue()->getNombre()<<"\t|||\t Adyacentes: \t";
        if(grafo->getCurr()->getListaAd()->getSize()){
            for(int j = 0; j < grafo->getCurr()->getListaAd()->getMax(); j++){
                grafo->getCurr()->getListaAd()->goToPos(j);
                cout<<grafo->getCurr()->getListaAd()->getValue()<<"\t";
            }
        }
        cout<<"\n";
    }
}

void Graph::printB(LinkedList* grafo)
{
    myfile.open ("warshall.txt", ios::out | ios::trunc);
    myfile <<"Cerradura transitiva por algoritmo de Warshall\n";
    myfile <<"Aerpuerto:\t";
    grafo->goToPos(0);
    for(int i = 0; i < grafo->getSize(); i++){
        grafo->goToPos(i);
        myfile <<grafo->getCurrValue()->getId()<<"\t";
    }
    myfile <<"\n";
    for(int i = 0; i < grafo->getSize(); i++){
        grafo->goToPos(i);
        myfile <<grafo->getCurrValue()->getId()<<"-"<<grafo->getCurrValue()->getNombre()<<":\t";
        if(grafo->getCurr()->getListaAdB()->getSize()){
            for(int j = 0; j < grafo->getCurr()->getListaAdB()->getMax(); j++){
                grafo->getCurr()->getListaAdB()->goToPos(j);

                myfile <<grafo->getCurr()->getListaAdB()->getValue()<<"\t";
            }
        }
        myfile <<"\n";
    }
    myfile.close();
}
//Implementa el algoritmo de Warshall
void Graph::warshall()
{
    mWarshall = new LinkedList(maxSize);
    LinkedList* aux = new LinkedList(maxSize);;
    for(int i = 0; i < maxSize; i++){
        grafo->goToPos(i);
        mWarshall->append(grafo->getCurr()->getValue());
        mWarshall->goToPos(i);
        aux->append(grafo->getCurr()->getValue());
        aux->goToPos(i);
        for(int j = 0; j < maxSize; j++){
            grafo->getCurr()->getListaAdB()->goToPos(j);
            mWarshall->getCurr()->getListaAdB()->goToPos(j);
            aux->getCurr()->getListaAdB()->goToPos(j);

            if(grafo->getCurr()->getListaAdB()->getValue() != 0){
                aux->getCurr()->getListaAdB()->setValue(1);
                mWarshall->getCurr()->getListaAdB()->setValue(1);
            }
        }
    }


    for(int k = 0; k < maxSize; k++){
        for(int i = 0; i < maxSize; i++){
            aux->goToPos(i);
            mWarshall->goToPos(i);
            for(int j = 0; j < maxSize; j++){
                aux->getCurr()->getListaAdB()->goToPos(j);
                mWarshall->getCurr()->getListaAdB()->goToPos(j);
                if(aux->getCurr()->getListaAdB()->getValue() == 1)
                    mWarshall->getCurr()->getListaAdB()->setValue(1);
                else{
                    aux->getCurr()->getListaAdB()->goToPos(k);
                    mWarshall->getCurr()->getListaAdB()->goToPos(k);

                    if(aux->getCurr()->getListaAdB()->getValue() == 1){
                        aux->goToPos(k);
                        aux->getCurr()->getListaAdB()->goToPos(j);

                        if(aux->getCurr()->getListaAdB()->getValue() == 1){
                            mWarshall->goToPos(i);
                            mWarshall->getCurr()->getListaAdB()->goToPos(j);
                            mWarshall->getCurr()->getListaAdB()->setValue(1);
                        }
                    }
                }
            }
        }

        for(int i = 0; i < maxSize; i++){
            mWarshall->goToPos(i);
            aux->goToPos(i);
            for(int j = 0; j < maxSize; j++){
                mWarshall->getCurr()->getListaAdB()->goToPos(j);
                aux->getCurr()->getListaAdB()->goToPos(j);
                if(mWarshall->getCurr()->getListaAdB()->getValue() != 0){
                    aux->getCurr()->getListaAdB()->setValue(1);
                }
            }
        }
    }

}


//Algoritmo de Kruskal
void Graph::kruskal()
{
    //ArrayList
}

//Clase destructora
Graph::~Graph()
{
    delete grafo;
}
