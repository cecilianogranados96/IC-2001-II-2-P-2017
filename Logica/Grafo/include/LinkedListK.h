#ifndef LINKEDLISTK_H
#define LINKEDLISTK_H
#include "NodeK.h"

class NodeK;
class LinkedListK
{
    public:
        LinkedListK(int maxSize);
        virtual ~LinkedListK();
        int getSize();
        int getPos();
        NodeK* getCurr();
        NodeK* getCurrGoTo(int pos);
        void goToStart();
        void goToEnd();
        void goToPos(int pos);
        void next();
        void previous();
        void insert();
        void append();
        void print();
        void clear();
        void remove();
        void printValue();

    protected:
        NodeK* first;
        NodeK* last;
        NodeK* curr;
        int maxSize;
        int size;
};

#endif // LINKEDLIST_H
