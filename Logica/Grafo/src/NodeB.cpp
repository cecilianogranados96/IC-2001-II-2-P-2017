#include "NodeB.h"
#include <stdexcept>
#include <cstddef>
//################################
//#
//# OBJETIVO:
//# =========
//#
//# Contrucci�n de los nodos del grafo.
//#
//#
//# Desarrollo:
//#
//# - Silvia Calder�n
//#
//#
//################################
using namespace std;

//Constructor de un nodo vac�o con referencia al siguiente
NodeB::NodeB(NodeB* next){
    this->next=next;
}

//Constructor de un nodo
NodeB::NodeB(int origen, int destino, int peso, NodeB* next){
    this->origen = origen;
    this->destino = destino;
    this->peso = peso;
    this->next = next;
    state = false;
}

//Funci�n getValue: devuelve el valor del nodo
int NodeB::getOrigen(){
    return origen;
}

//Funci�n getValue: devuelve el valor del nodo
int NodeB::getDestino(){
    return destino;
}

//Funci�n getValue: devuelve el valor del nodo
int NodeB::getPeso(){
    return peso;
}

//Funci�n getNext: devuelve el nodo siguiente
NodeB* NodeB::getNext(){
    return next;
}

//Funci�n getState: devuelve el nodo siguiente
bool NodeB::getState(){
    return state;
}
//M�todo setValue: le asigna el par�metro como valor del nodo
void NodeB::setOrigen(int origen){
    this->origen = origen;
}

//M�todo setValue: le asigna el par�metro como valor del nodo
void NodeB::setDestino(int destino){
    this->origen = destino;
}

//M�todo setValue: le asigna el par�metro como valor del nodo
void NodeB::setPeso(int peso){
    this->peso = peso;
}

//M�todo setNext: le asigna el par�metro como siguiente del nodo
void NodeB::setNext(NodeB* next){
    this->next = next;
}

//M�todo setState
void NodeB::setState(bool state){
    this->state = state;
}

//M�todo setCurr
void NodeB::setCurr(int origen, int destino, int peso){
    this->origen = origen;
    this->destino = destino;
    this->peso = peso;
}

//M�todo clear: elimina el nodo
void NodeB::clear(){
    delete next;
}

//Destructor del nodo
NodeB::~NodeB()
{
    clear();
}
