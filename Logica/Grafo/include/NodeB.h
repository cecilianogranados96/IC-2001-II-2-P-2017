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
        NodeB* getNext();
        void setOrigen(int origen);
        void setDestino(int destino);
        void setPeso(int peso);
        void setNext(NodeB* node);
        void clear();
    protected:

    private:
        int origen;
        int destino;
        int peso;
        NodeB* next;
};

#endif // NODEB_H

