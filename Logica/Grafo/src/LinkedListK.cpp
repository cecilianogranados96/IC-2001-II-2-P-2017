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

//Funci�n getSize: devuelve el tama�o
int LinkedListK::getSize(){
    return size;
}

//Funci�n getPos devuelve la posici�n del current
int LinkedListK::getPos(){
    int pos=0;
    NodeK* temp= first;
    while(temp!=curr){
        pos++;
        temp=temp->getNext();
    }
    return pos;
}

//M�todo goToStart: pone el current en el primer nodo
void LinkedListK::goToStart(){
    curr=first;
}

//M�todo goToStart: pone el current en el �ltimo nodo
void LinkedListK::goToEnd(){
    curr=last;
}

//M�todo goToPos: pone el current el posici�n del par�metro
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

//M�todo next: situa el current en la siguiente posici�n
void LinkedListK::next(){
    if(curr->getNext()!=last){
        curr = curr->getNext();
    }
}

//M�todo append: a�ade el par�metro al final de la lista
void LinkedListK::append(){
    NodeK* newNode = new NodeK(NULL, maxSize);
    last->setNext(newNode);
    last = newNode;
    size++;
}

//M�todo insert: inserta un elemento al final de la lista
void LinkedListK::insert(){
    NodeK* newNode = new NodeK(NULL, maxSize);
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
    if (curr == last){
        last = last->getNext();
    }
    size++;
}

//Funci�n remove: elimina el nodo siguiente al current
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

//M�todo clear: elimina la lista
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

//M�todo print: imprime la lista
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

