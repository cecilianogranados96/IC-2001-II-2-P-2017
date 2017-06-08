#include <iostream>
#include "LinkedListK.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

//Constructor de la clase
LinkedListK::LinkedListK(int maxSize){
    first = new NodeK(NULL);
    last = first;
    curr = first;
    size = 0;
    this->maxSize = maxSize;
}

NodeK* LinkedListK::getCurr()
{
    return curr;
}

NodeK* LinkedListK::getCurrGoTo(int pos)
{
    goToPos(pos);
    return curr;
}

//Función getSize: devuelve el tamaño
int LinkedListK::getSize(){
    return size;
}

//Función getPos devuelve la posición del current
int LinkedListK::getPos(){
    int pos=0;
    NodeK* temp= first;
    while(temp!=curr){
        pos++;
        temp=temp->getNext();
    }
    return pos;
}

//Método goToStart: pone el current en el primer nodo
void LinkedListK::goToStart(){
    curr=first;
}

//Método goToStart: pone el current en el último nodo
void LinkedListK::goToEnd(){
    curr=last;
}

//Método goToPos: pone el current el posición del parámetro
void LinkedListK::goToPos(int pos){
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
void LinkedListK::next(){
    if(curr->getNext()!=last){
        curr = curr->getNext();
    }
}

//Método append: añade el parámetro al final de la lista
void LinkedListK::append(){
    NodeK* newNode = new NodeK(NULL, maxSize);
    last->setNext(newNode);
    last = newNode;
    size++;
}

//Método insert: inserta un elemento al final de la lista
void LinkedListK::insert(){
    NodeK* newNode = new NodeK(NULL, maxSize);
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
    if (curr == last){
        last = last->getNext();
    }
    size++;
}

//Función remove: elimina el nodo siguiente al current
void LinkedListK::remove(){
    try
    {
        if(curr->getNext()==NULL){
            throw runtime_error("No existe un elemento que borrar");
        }

        NodeK* temp = curr->getNext();
        curr->setNext(temp->getNext());
        if (temp==last){
            last=curr;
        }
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//Método clear: elimina la lista
void LinkedListK::clear(){
    try
    {
        goToStart();
        for(int i=0; i<size;i++){
            NodeK* temp=curr;
            next();
            //delete temp;
        }
        first= new NodeK(NULL);
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
void LinkedListK::print(){
    try
    {
        NodeK *temp = first->getNext();
        if (size!=0){
            cout<<"Lista";
            while(temp!=NULL){
                temp->getListaAd()->print();
                temp = temp->getNext();
            }
            cout<<"\n \n";
            delete temp;
        }
        else{
            throw runtime_error("El grafo esta vacio");
        }
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}


//Destructor de la clase
LinkedListK::~LinkedListK(){
    clear();
}

