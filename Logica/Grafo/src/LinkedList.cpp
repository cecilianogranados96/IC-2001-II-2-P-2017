#include <iostream>
#include "LinkedList.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

//Constructor de la clase
LinkedList::LinkedList(int maxSize){
    first = new Node(NULL);
    last = first;
    curr = first;
    size = 0;
    this->maxSize = maxSize;
}

Node* LinkedList::getCurr()
{
    return curr;
}

Aeropuerto* LinkedList::getCurrValue()
{
    return curr->getValue();
}

Node* LinkedList::getCurrGoTo(int pos)
{
    goToPos(pos);
    return curr;
}

//Funci�n getSize: devuelve el tama�o
int LinkedList::getSize(){
    return size;
}

//Funci�n getPos devuelve la posici�n del current
int LinkedList::getPos(){
    int pos=0;
    Node* temp= first;
    while(temp!=curr){
        pos++;
        temp=temp->getNext();
    }
    return pos;
}

//M�todo goToStart: pone el current en el primer nodo
void LinkedList::goToStart(){
    curr=first;
}

//M�todo goToStart: pone el current en el �ltimo nodo
void LinkedList::goToEnd(){
    curr=last;
}

//M�todo goToPos: pone el current el posici�n del par�metro
void LinkedList::goToPos(int pos){
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
void LinkedList::next(){
    if(curr->getNext()!=last){
        curr = curr->getNext();
    }
}

//M�todo append: a�ade el par�metro al final de la lista
void LinkedList::append(Aeropuerto* element){
    element->setId(size);
    Node* newNode = new Node(element, NULL, maxSize);
    last->setNext(newNode);
    last = newNode;
    size++;
}

//M�todo insert: inserta un elemento al final de la lista
void LinkedList::insert(Aeropuerto* element){
    element->setId(size);
    Node* newNode = new Node(element, NULL, maxSize);
    newNode->setNext(curr->getNext());
    curr->setNext(newNode);
    if (curr == last){
        last = last->getNext();
    }
    size++;
}

//Funci�n find: devuelve la posici�n donde se encuentra un valor
int LinkedList::find(string value){
    try
    {
        if (size!=0){
            goToStart();
            curr = curr->getNext();
            int i = 0;
            while(curr!=NULL){
                if (curr->getValue()->getNombre() == value){
                     return i;
                }
                i++;
                curr = curr->getNext();
            }
            throw runtime_error("El valor no esta");
        }
        else{
            throw runtime_error("La cola esta vacia");
        }
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//Funci�n remove: elimina el nodo siguiente al current
string LinkedList::remove(){
    try
    {
        if(curr->getNext()==NULL){
            throw runtime_error("No existe un elemento que borrar");
        }
        string value = curr->getNext()->getValue()->getNombre();
        Node* temp = curr->getNext();
        curr->setNext(temp->getNext());
        if (temp==last){
            last=curr;
        }
        return value;
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//M�todo clear: elimina la lista
void LinkedList::clear(){
    try
    {
        goToStart();
        for(int i=0; i<size;i++){
            Node* temp=curr;
            next();
            //delete temp;
        }
        first= new Node(NULL);
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
void LinkedList::print(){
    try
    {
        Node *temp = first->getNext();
        if (size!=0){
            cout<<"Lista";
            while(temp!=NULL){
                cout<<temp->getValue()->getNombre()<< " \t";
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

//M�todo printValue: imprime el valor del current
void LinkedList::printValue(){
    try
    {
        if (size!=0){
            if (curr==first)
                next();
            cout<<"Current: "<<curr->getValue()->getNombre()<< "\n \n";
        }
        else{
            throw runtime_error("La cola esta vacia");
        }
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//Destructor de la clase
LinkedList::~LinkedList(){
    clear();
}

