#include <iostream>
#include "LinkedListB.h"
#include <stdexcept>
#include <cstddef>
//################################
//#
//# OBJETIVO:
//# =========
//#
//# Construcción de la Linked list modificada para manejas aristas.
//#
//#
//# Desarrollo:
//#
//# - Silvia Calderón
//#
//#
//################################
using namespace std;

//Constructor de la clase
LinkedListB::LinkedListB(){
    first = new NodeB(NULL);
    last = first;
    curr = first;
    size = 0;
}

NodeB* LinkedListB::getCurr()
{
    return curr;
}

int LinkedListB::getCurrPeso()
{
    return curr->getPeso();
}

NodeB* LinkedListB::getCurrGoTo(int pos)
{
    goToPos(pos);
    return curr;
}

//Función getSize: devuelve el tamaño
int LinkedListB::getSize(){
    return size;
}

//Función getPos devuelve la posición del current
int LinkedListB::getPos(){
   int pos=0;
   NodeB* temp= first;
   while(temp!=curr){
    pos++;
    temp = temp->getNext();
   }
   return pos;
}

//Método goToStart: pone el current en el primer nodo
void LinkedListB::goToStart(){
    curr = first;
}

//Método goToStart: pone el current en el último nodo
void LinkedListB::goToEnd(){
    curr = last;
}

//Método goToPos: pone el current el posición del parámetro
void LinkedListB::goToPos(int pos){
    if(pos<size && pos>=0){
        int i = 0;
        goToStart();
        curr = curr->getNext();
        for(i=0;i<pos;i++){
            curr = curr->getNext();
        }
    }
}

//Método next: situa el current en la siguiente posición
void LinkedListB::next(){
    if(curr->getNext()!=last){
        curr = curr->getNext();
    }
}

//Método append: añade el parámetro al final de la lista
void LinkedListB::append(int origen, int destino, int peso){
    NodeB* newNode = new NodeB(origen, destino, peso, NULL);
    last->setNext(newNode);
    last=newNode;
    size++;
}

//Método insert: inserta un elemento al final de la lista
void LinkedListB::insert(int origen, int destino, int peso){
    NodeB* newNode = new NodeB(origen, destino, peso, NULL);
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
    if (curr == last){
        last = last->getNext();
    }
    size++;
}

//Función remove: elimina el nodo siguiente al current
int LinkedListB::remove(){
    try
    {
        if(curr->getNext()==NULL){
            throw runtime_error("No existe un elemento que borrar");
        }
        int value = curr->getNext()->getPeso();
        NodeB* temp = curr->getNext();
        curr->setNext(temp->getNext());
        if (temp == last){
            last = curr;
        }
        return value;
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//Método clear: elimina la lista
void LinkedListB::clear(){
    try
    {
        goToStart();
        for(int i=0; i<size;i++){
            NodeB* temp=curr;
            next();
            //delete temp;
        }
        first = new NodeB(NULL);
        last= first;
        curr= first;
        size = 0;
    }
    catch (runtime_error e)
    {
     cout << "Error: no se puede borrar " << e.what()<<"\n\n";
    }
}

//Método print: imprime la lista
void LinkedListB::print(){
    try
    {
        NodeB *temp = first->getNext();
        if (size!=0){
            cout<<"Lista de aristas\n";
            while(temp!=NULL){
                cout<<"Origen: "<<temp->getOrigen()<<", Destino: "<<temp->getDestino()<<", Peso: "<<temp->getPeso()<<", Estado: "<<temp->getState()<< "\n";
                temp = temp->getNext();
            }
            cout<<"\n \n";
            delete temp;
        }
        else{
            throw runtime_error("La lista esta vacia");
        }
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//Método printValue: imprime el valor del current
void LinkedListB::printValue(){
    try
    {
        if (size!=0){
            if (curr==first)
                next();
            cout<<"Current: "<<curr->getPeso()<< "\n \n";
        }
        else{
            throw runtime_error("La lista esta vacia");
        }
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//Función bubble sort
void LinkedListB::bubbleSort(){
  int x, y;
  int oX, dX, oY, dY;
  for(int i = 1; i<=size; ++i) {
    for(int j = 0; j<=size-i; ++j) {
        goToPos(j);
        x = curr->getPeso();
        oX = curr->getOrigen();
        dX = curr->getDestino();

        goToPos(j+1);
        y = curr->getPeso();
        oY = curr->getOrigen();
        dY = curr->getDestino();

        if(x>y){
            goToPos(j);
            curr->setCurr(oY, dY, y);

            goToPos(j+1);
            curr->setCurr(oX, dX, x);
        }
    }
  }
}

//Destructor de la clase
LinkedListB::~LinkedListB(){
    clear();
}

