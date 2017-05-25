#include <iostream>
#include <stdlib.h>
#include "CaminoMinimo.h"
#include "TodoCaminoMinimo.h"
#include "Graph.h"
#include "Server.h"
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#define REQ_WINSOCK_VER 2
#include <cstdlib>

using namespace std;

int toint(string val){
    stringstream geek(val);
    int x = 0;
    geek >> x;
    return x;
}

string tostring(int val){
    stringstream ss;
    ss << val;
    string str = ss.str();
    return str;
}

void readVertex(Graph* matriz)
{
    float posX,posY;
    string nombre, imagen;
    std::string textline;
    ifstream file ("aeropuertos.txt");

    //Lee los aeropuertos y crea cada nodo
    while (getline(file, textline))
    {
       string comma_string;
       std::istringstream text_stream(textline);
       text_stream >> nombre;
       getline(text_stream, comma_string, ','); // Read characters after number until comma.
       text_stream >> posX;
       getline(text_stream, comma_string, ','); // Read characters after number until comma.
       text_stream >> posY;
       getline(text_stream, comma_string, ',');
       getline(text_stream, imagen, '\n');

       matriz->addVertex(new Aeropuerto(nombre, posX, posY, imagen));
    }

    file.close();
}

void readEdge(Graph* matriz)
{
    int origen, destino, peso;
    std::string textline;
    ifstream file ("rutas.txt");

    while (getline(file, textline))
    {
       string comma_string;
       std::istringstream text_stream(textline);
       text_stream >> origen;
       getline(text_stream, comma_string, ',');
       text_stream >> destino;
       getline(text_stream, comma_string, ',');
       text_stream >> peso;

       matriz->addEdge(origen, destino, peso);
    }

    file.close();

}
int numberLines()
{
    int lines = 0;
    std::string line;
    ifstream file ("aeropuertos.txt");

    while(getline(file, line))
        ++lines;
    file.close();
}

int main(void)
{
    cout<<"\t\t\t Aeropuertos \n"<<endl;
    Graph* matriz = new Graph(numberLines());
    readVertex(matriz);
    readEdge(matriz);

    TodoCaminoMinimo* floyd = new TodoCaminoMinimo(matriz);
    CaminoMinimo* dijkstra = new CaminoMinimo(matriz);

    WSockServer MyServer(REQ_WINSOCK_VER);
    MyServer.RunServer(1500,"INICIAL");

    int opcion = 0;
    while(true)
    {
        WSockServer MyServer(REQ_WINSOCK_VER);
        cout<<"\t\t\tAeropuertos\n\nMenu\n\n0. Elegir ruta mas corta\n1. Crear archivos con Warshall(n)\n2. Crear archivos con Kruskal\n\nDigite su eleccion: ";
        //cin>>opcion;
        opcion = toint(MyServer.RunServer(1500,"Opcion OK"));

        if(opcion == 0){
            int algoritmo;
            int origen;
            int destino;

            WSockServer MyServer(REQ_WINSOCK_VER);
            cout<<"Digite el algoritmo [1.Dijkstra - 2.Floyd]: ";
            algoritmo = toint(MyServer.RunServer(1500,"Opcion OK"));

            cout<<"Digite el aeropuerto de origen: ";
            origen = toint(MyServer.RunServer(1500,"Opcion OK"));

            cout<<"Digite el aeropuerto de destino: ";
            destino = toint(MyServer.RunServer(1500,"Opcion OK"));

            if(algoritmo == 1){
                dijkstra->Dijkstra(matriz, origen);
                dijkstra->recuperaCaminoAux(destino);
                cout<<"\nDistancia minima "<<dijkstra->OdistanciaMinima()[destino];
            }else
            {
                floyd->Floyd();
                floyd->recuperaCamino(origen, destino);
                cout<<"\nDistancia minima "<<floyd->Odistancia()[origen][destino];
            }
        }

        if(opcion == 1){
            matriz->warshall();
            matriz->printB(matriz->getWarshall());
        }
    }
    return 0;
}

