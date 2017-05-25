#include "Node.h"
#include <stdexcept>
#include <cstddef>
using namespace std;

//Constructor de un nodo vac�o con referencia al siguiente
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

//Funci�n getValue: devuelve el valor del nodo
Aeropuerto* Node::getValue(){
    return value;
}

//Funci�n getListaAd: devuelve el valor del nodo
ArrayList* Node::getListaAd(){
    return listaAd;
}

//Funci�n getListaAd: devuelve el valor del nodo
ArrayList* Node::getListaAdB(){
    return listaAdB;
}

//Funci�n getNext: devuelve el nodo siguiente
Node* Node::getNext(){
    return next;
}

//M�todo setNext: le asigna el par�metro como siguiente del nodo
void Node::setNext(Node* next){
    this->next= next;
}

//M�todo setValue: le asigna el par�metro como valor del nodo
void Node::setValue(Aeropuerto* value){
    this->value=value;
}

//M�todo setListaAd: le asigna el par�metro como valor del nodo
void Node::setListaAd(ArrayList* listaAd){
    this->listaAd = listaAd;
}

//M�todo clear: elimina el nodo
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
