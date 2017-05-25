#include <iostream>
#ifndef NODE_H
#define NODE_H
#include "Aeropuerto.h"
#include "ArrayList.h"

class Node
{
    public:
        Node();
        Node(Aeropuerto* value, Node* next, int maxSize);
        Node(Node* next);
        virtual ~Node();
        Aeropuerto* getValue();
        Node* getNext();
        ArrayList* getListaAd();
        ArrayList* getListaAdB();
        void setValue(Aeropuerto* value);
        void setListaAd(ArrayList* listaAd);
        void setNext(Node* node);
        void clear();

    private:
        Aeropuerto* value;
        ArrayList* listaAd;
        ArrayList* listaAdB;
        Node* next;
};

#endif // NODE_H
