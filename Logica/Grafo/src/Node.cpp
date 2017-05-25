#include "Node.h"
#include <stdexcept>
#include <cstddef>
using namespace std;

//Constructor de un nodo vacío con referencia al siguiente
Node::Node(Node* next){
    this->next=next;
}

//Constructor de un nodo
Node::Node(Aeropuerto* value, Node* next, int maxSize){
    this->value=value;
    this->next=next;
    listaAd = new ArrayList(maxSize);
    listaAdB = new ArrayList(maxSize);
    for(int i=0; i < maxSize; i++)
        listaAd->append(0xFFFFFFF);

    for(int j=0; j < maxSize; j++)
        listaAdB->append(0);
}

//Función getValue: devuelve el valor del nodo
Aeropuerto* Node::getValue(){
    return value;
}

//Función getListaAd: devuelve el valor del nodo
ArrayList* Node::getListaAd(){
    return listaAd;
}

//Función getListaAd: devuelve el valor del nodo
ArrayList* Node::getListaAdB(){
    return listaAdB;
}

//Función getNext: devuelve el nodo siguiente
Node* Node::getNext(){
    return next;
}

//Método setNext: le asigna el parámetro como siguiente del nodo
void Node::setNext(Node* next){
    this->next= next;
}

//Método setValue: le asigna el parámetro como valor del nodo
void Node::setValue(Aeropuerto* value){
    this->value=value;
}

//Método setListaAd: le asigna el parámetro como valor del nodo
void Node::setListaAd(ArrayList* listaAd){
    this->listaAd = listaAd;
}

//Método clear: elimina el nodo
void Node::clear(){
    delete value;
    delete listaAd;
    delete next;
}

//Destructor del nodo
Node::~Node()
{
    clear();
}
