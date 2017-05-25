#ifndef LINKEDLISTB_H
#define LINKEDLISTB_H
#include "NodeB.h"


class LinkedListB
{
    public:
        LinkedListB();
        virtual ~LinkedListB();
        int getSize();
        int getPos();
        NodeB* getCurr();
        int getCurrPeso();
        NodeB* getCurrGoTo(int pos);
        void goToStart();
        void goToEnd();
        void goToPos(int pos);
        void next();
        void previous();
        void insert(int origen, int destino, int peso);
        void append(int origen, int destino, int peso);
        void print();
        void clear();
        int remove();
        void printValue();
    protected:
        NodeB* first;
        NodeB* last;
        NodeB* curr;
        int size;
};

#endif // LINKEDLIST_H
