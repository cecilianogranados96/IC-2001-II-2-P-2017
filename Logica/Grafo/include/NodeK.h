#include <iostream>
#ifndef NODEK_H
#define NODEK_H
#include "ArrayList.h"

class NodeK
{
    public:
        NodeK();
        NodeK(NodeK* next, int maxSize);
        NodeK(NodeK* next);
        virtual ~NodeK();
        NodeK* getNext();
        ArrayList* getListaAd();
        void setListaAd(ArrayList* listaAd);
        void setNext(NodeK* node);
        void clear();

    private:
        ArrayList* listaAd;
        NodeK* next;
};

#endif // NODE_H
