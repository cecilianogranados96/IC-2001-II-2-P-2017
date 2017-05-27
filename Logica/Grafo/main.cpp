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
    while (getline(file, textline))
    {
        string comma_string;
        std::istringstream text_stream(textline);
        text_stream >> nombre;
        getline(text_stream, comma_string, ',');
        text_stream >> posX;
        getline(text_stream, comma_string, ',');
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
    ifstream fileR ("rutas.txt");
    while (getline(fileR, textline))
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
    fileR.close();
}
int numberLines()
{
    int lines = 0;
    std::string line;
    ifstream fileA ("aeropuertos.txt");
    while(getline(fileA, line))
        ++lines;
}

int main(void)
{
    cout<<"\t\t\t Aeropuertos \n"<<endl;
    int lines = 0;
    std::string line;
    ifstream fileA ("aeropuertos.txt");
    while(getline(fileA, line))
        ++lines;
    fileA.close();
    Graph* matriz = new Graph(lines);
    float posX,posY;
    string nombre, imagen;
    std::string textline;
    ifstream file ("aeropuertos.txt");
    while (getline(file, textline))
    {
        string comma_string;
        std::istringstream text_stream(textline);
        text_stream >> nombre;
        getline(text_stream, comma_string, ',');
        text_stream >> posX;
        getline(text_stream, comma_string, ',');
        text_stream >> posY;
        getline(text_stream, comma_string, ',');
        getline(text_stream, imagen, '\n');
        matriz->addVertex(new Aeropuerto(nombre, posX, posY, imagen));
    }
    file.close();
    int origen, destino, peso;
    std::string textlineR;
    ifstream fileR ("rutas.txt");

    while (getline(fileR, textlineR))
    {
       string comma_string;
       std::istringstream text_stream(textlineR);
       text_stream >> origen;
       getline(text_stream, comma_string, ',');
       text_stream >> destino;
       getline(text_stream, comma_string, ',');
       text_stream >> peso;
       matriz->addEdge(origen, destino, peso);
    }
    fileR.close();
    TodoCaminoMinimo* floyd = new TodoCaminoMinimo(matriz);
    CaminoMinimo* dijkstra = new CaminoMinimo(matriz);
    matriz->print(matriz->getGraph());
    int opcion = 0;
    while(true)
    {
        cout<<"\t\t\tAeropuertos\n\nMenu\n\n0. Elegir ruta mas corta\n1. Crear archivos con Warshall(n)\n2. Crear archivos con Kruskal\n\nDigite su eleccion: ";
        //cin>>opcion;
        WSockServer MyServer = WSockServer();
        opcion = toint(MyServer.RunServer("Opcion OK"));
        if(opcion == 0){
            int algoritmo;
            int origen;
            int destino;

            cout<<"Digite el algoritmo [1.Dijkstra - 2.Floyd]: ";
            //cin>>algoritmo;
            WSockServer MyServer = WSockServer();
            algoritmo = toint(MyServer.RunServer("Algoritmo"));

            cout<<"Digite el aeropuerto de origen: ";
            //cin>>origen;
            WSockServer MyServer2 = WSockServer();
            origen = toint(MyServer2.RunServer("Origen"));

            cout<<"Digite el aeropuerto de destino: ";
            //cin>>destino;
            WSockServer MyServer3 = WSockServer();
            destino = toint(MyServer3.RunServer("Destino"));

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
        if(opcion == 2){
            matriz->warshall();
            matriz->printB(matriz->getWarshall());
        }
    }
    return 0;
}
