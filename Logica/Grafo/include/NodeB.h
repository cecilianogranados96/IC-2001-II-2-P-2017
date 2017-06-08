#ifndef NODEB_H
#define NODEB_H
#include <iostream>
#include "Aeropuerto.h"

class NodeB
{
    public:
        NodeB();
        NodeB(int origen, int destino, int peso, NodeB* next);
        NodeB(NodeB* next);
        virtual ~NodeB();
        int getOrigen();
        int getDestino();
        int getPeso();
        bool getState();
        NodeB* getNext();
        void setOrigen(int origen);
        void setDestino(int destino);
        void setState(bool state);
        void setPeso(int peso);
        void setCurr(int origen, int destino, int peso);
        void setNext(NodeB* node);
        void clear();

    private:
        int origen;
        int destino;
        int peso;
        bool state;
        NodeB* next;
};

#endif // NODEB_H

