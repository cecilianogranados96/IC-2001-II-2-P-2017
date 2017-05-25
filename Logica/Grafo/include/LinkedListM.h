#ifndef LINKEDLISTM_H
#define LINKEDLISTM_H
#include "NodeM.h"


class LinkedListB
{
    public:
        LinkedListB();
        virtual ~LinkedListB();
        int getSize();
        int getPos();
        NodeB* getCurr();
        Aeropuerto* getCurrValue();
        int getCurrPeso();
        NodeB* getCurrGoTo(int pos);
        void goToStart();
        void goToEnd();
        void goToPos(int pos);
        void next();
        void previous();
        void insert(Aeropuerto* element, int peso);
        void append(Aeropuerto* element, int peso);
        void print();
        void clear();
        string remove();
        bool findB(Aeropuerto* aeropuerto);
        int find(Aeropuerto* aeropuerto);
        void printValue();
    protected:
        NodeB* first;
        NodeB* last;
        NodeB* curr;
        int size;
};

#endif // LINKEDLIST_H


#endif // LINKEDLISTM_H
