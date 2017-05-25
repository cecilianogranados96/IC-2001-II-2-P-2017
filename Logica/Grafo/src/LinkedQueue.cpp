#include "LinkedQueue.h"
#include <stdexcept>
#include <cstddef>

using namespace std;

//Constructor de la cola
LinkedQueue::LinkedQueue()
{
    first = last = new Node(NULL);
    size = 0;
    pos = 0;
}

//Destructor de la cola
LinkedQueue::~LinkedQueue()
{
    size = 0;
    pos = 0;
    delete first;
    delete last;
}

//Método insert: añade al final de la cola
void LinkedQueue::insert(int element)
{
    append(element);
}

//Función remove: elimina el primer elemento
int LinkedQueue::remove()
{
    goToStart();
    int deQueueValue = LinkedList::remove();
    return deQueueValue;
}

//Función getFront: devuelve el primer elemento en la cola
int LinkedQueue::getFront()
{
    goToStart();
    int frontValue = curr->getNext()->getValue();
    return frontValue;
}

//Función isEmpty: devuelve true si está vacía la cola
bool LinkedQueue::isEmpty()
{
    if(size==0)
        return true;
    else
        return false;
}

//Función getBiggest: devuelve el elemento mayor de la lista
int LinkedQueue::getBiggest()
{
    try
    {
        if(!isEmpty()){
            goToStart();
            next();
            int mayor = curr->getValue();

            while(curr!=NULL){
                if (curr->getValue() > mayor){
                     mayor = curr->getValue();
                }
                curr=curr->getNext();
            }
            return mayor;
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

//Función getSmallest: devuelve el elemento menor de la cola
int LinkedQueue::getSmallest()
{
    try
    {
        if(!isEmpty()){

            goToStart();
            next();
            int menor = curr->getValue();

            while(curr!=NULL){
                if (curr->getValue() < menor){
                     menor = curr->getValue();
                }
                curr=curr->getNext();
            }
            return menor;
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

//Función removeAscendant: elimina el menor de la cola
int LinkedQueue::removeAscendant()
{
    try
    {
        if(!isEmpty()){
            int small = find(getSmallest());
            if (small == 0)
                goToStart();
            else
                goToPos(small-1);
            int deQueueValue = LinkedList::remove();
            return deQueueValue;
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

//Función removeDescendant: elimina el mayor de la cola
int LinkedQueue::removeDescendant()
{
    try
    {
        if(!isEmpty()){
            int big = find(getBiggest());
            if (big == 0)
                goToStart();
            else
                goToPos(big-1);
            int deQueueValue = LinkedList::remove();
            return deQueueValue;
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
