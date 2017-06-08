#include "NodeB.h"
#include <stdexcept>
#include <cstddef>
using namespace std;

//Constructor de un nodo vacío con referencia al siguiente
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

//Función getValue: devuelve el valor del nodo
int NodeB::getOrigen(){
    return origen;
}

//Función getValue: devuelve el valor del nodo
int NodeB::getDestino(){
    return destino;
}

//Función getValue: devuelve el valor del nodo
int NodeB::getPeso(){
    return peso;
}

//Función getNext: devuelve el nodo siguiente
NodeB* NodeB::getNext(){
    return next;
}

//Función getState: devuelve el nodo siguiente
bool NodeB::getState(){
    return state;
}
//Método setValue: le asigna el parámetro como valor del nodo
void NodeB::setOrigen(int origen){
    this->origen = origen;
}

//Método setValue: le asigna el parámetro como valor del nodo
void NodeB::setDestino(int destino){
    this->origen = destino;
}

//Método setValue: le asigna el parámetro como valor del nodo
void NodeB::setPeso(int peso){
    this->peso = peso;
}

//Método setNext: le asigna el parámetro como siguiente del nodo
void NodeB::setNext(NodeB* next){
    this->next = next;
}

//Método setState
void NodeB::setState(bool state){
    this->state = state;
}

//Método setCurr
void NodeB::setCurr(int origen, int destino, int peso){
    this->origen = origen;
    this->destino = destino;
    this->peso = peso;
}

//Método clear: elimina el nodo
void NodeB::clear(){
    delete next;
}

//Destructor del nodo
NodeB::~NodeB()
{
    clear();
}
