#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList
{
    public:
        LinkedList(int maxSize);
        virtual ~LinkedList();
        int getSize();
        int getPos();
        Node* getCurr();
        Aeropuerto* getCurrValue();
        Node* getCurrGoTo(int pos);
        void goToStart();
        void goToEnd();
        void goToPos(int pos);
        void next();
        void previous();
        void insert(Aeropuerto* element);
        void append(Aeropuerto* element);
        void print();
        void clear();
        string remove();
        int find(string value);
        void printValue();

    protected:
        Node* first;
        Node* last;
        Node* curr;
        int maxSize;
        int size;
};

#endif // LINKEDLIST_H
