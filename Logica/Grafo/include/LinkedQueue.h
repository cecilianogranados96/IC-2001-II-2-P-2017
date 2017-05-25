#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#include "LinkedListB.h"

class LinkedQueue: public LinkedList
{
    public:
        LinkedQueue();
        ~LinkedQueue();
        void insert(bool element);
        int remove();
        bool isEmpty();
        bool getFront();
        bool removeAscendant();
        bool removeDescendant();
        int getBiggest();
        int getSmallest();

    protected:
        int pos;
};

#endif // LINKEDQUEUE_H
