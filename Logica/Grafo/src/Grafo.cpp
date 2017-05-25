#include "Grafo.h"

Grafo::Grafo()
{
    inicio = new nodo;

    inicio->etiqueta = 0;

    inicio->nodo = 1;

    inicio->ady  = 0;

    inicio->sig  = 0;
}


/*struct nodo Grafo::LocalizaLabel(const int e)
{
    struct nodo n;
    int enc=0;

    for (n=this.inicio; n!=0 && !enc; )
    {
         if (n->etiqueta == e)
            enc = 1;
         else
            n = n->sig;
    }

    return n;
}

bool Grafo::ExisteArco(nodo o, nodo  d)
{
    arco a;
    a = o->ady;
    while (a!=0)
    {
        if ((a->origen==o) && (a->destino==d))
            return true;
        else
            a = a->sig;
        }
        return false;
     }

int Grafo::GrafoVacio()
{
   return(this.inicio == 0);

}

float Grafo::EtiqArco(nodo o, nodo d)
{
    arco a;
    a=o->ady;
    while (a!=0)
    {
        if ((a->origen == o) && (a->destino == d))
            return (a->valor);
        else
            a = a->sig;
    }
    return 0;
}

void Grafo::InsertarNodo(const int dato, string nombre, int posX, int posY, string imagen)
{
    nodo aux,p;
    aux = new nodo;

    p=this.inicio;

    while(p->sig != 0)
         p = p->sig;

    aux->etiqueta = dato;
    aux->nodo = (p->nodo)+1;
    aux->ady = 0;
    aux->sig = 0;
    aux->aeropuerto = new Aeropuerto(nombre, posX, posY, imagen);
    p->sig = aux;

    (this.nnodos)++;
}

void Grafo::InsertarArco (nodo o, nodo d, int valor)
{
    arco aux;
    aux = new arco;
    aux->origen = o;
    aux->destino = d;
    aux->valor = valor;
    aux->sig = o->ady;
    o->ady = aux;

}

void Grafo::BorrarArco(nodo o, nodo d)
{
    arco a,ant;
    int enc=0;
    if (o->ady==0)
        return;
    else
        if (o->ady->destino==d)
        {

            a = o->ady;

            o->ady = a->sig;

            delete a;

        }

     else {
            ant = o->ady;
            a = ant->sig;
            while (!enc && (a!=0))
            {
                if (a->destino==d)
                    enc=1;
                 else {
                    a = a->sig;
                    ant = ant->sig;
                 }
             }

            if (a==0)
                 return;

            else {

                ant->sig = a->sig;
                delete a;

            }

  }

}

void Grafo::DesconectarNodo(nodo a_eliminar)
{
    Grafo g_nd;
    nodo n,org,dst,o,d;
    arco a;

    g_nd = new Grafo;

    for (n=this.inicio; n!=0; n=n->sig)
        g_nd.InsertarNodo(n->etiqueta);

    for (n=this.inicio; n!=0; n=n->sig)
        for (a=n->ady; a!=0; a=a->sig)
        {
            org = a->origen;
            dst = a->destino;
            o = g_nd.LocalizaLabel(org->etiqueta);
            d = g_nd.LocalizaLabel(dst->etiqueta);

           if ((org!=a_eliminar) && dst!=a_eliminar))
               g_nd.InsertarArco(o,d,a->valor);
       }
    this.CopiarGrafo(g_nd);
}

void Grafo::CopiarGrafo(Grafo gr)
{

    nodo n,org,dest,o,d;

    arco a;



    this.Destruir();

    this = new Grafo;

    for (n=gr.inicio; n!=0; n=n->sig)
        this.InsertarNodo(n->etiqueta);

    for (n=gr.inicio; n!=0; n=n->sig)
        for (a=n->ady; a!=0; a=a->sig)
        {

            org = a->origen;

            dest = a->destino;

            o = g_nd.LocalizaLabel(org->etiqueta);

            d = g_nd.LocalizaLabel(dest->etiqueta);

            this.InsertarArco(o,d,a->valor);
       }
}

Grafo::~Grafo()
{
    nodo n;
    arco aux;

    while ((this.inicio)->sig != 0)
    {

    n = (this.inicio)->sig;

            while (n->ady != 0)

        {

                 aux = n->ady;

                 n->ady = aux->sig;

        delete aux;

         }

    (this.inicio)->sig = n->sig;

    delete n;

    }

delete (this.inicio);

}

*/
