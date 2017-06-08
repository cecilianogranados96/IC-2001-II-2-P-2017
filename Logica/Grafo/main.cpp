#include <iostream>
#include <stdlib.h>
#include "AlgorithmDijkstra.h"
#include "AlgorithmFloyd.h"
#include "Graph.h"
#include "Server.h"
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#define REQ_WINSOCK_VER 2
#include <cstdlib>
#include <stdio.h>
#include <string.h>

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
        //cout<<textline;
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
    AlgorithmFloyd* floyd = new AlgorithmFloyd(matriz);
    AlgorithmDijkstra* dijkstra = new AlgorithmDijkstra(matriz);
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
                dijkstra->getPath(destino);
                cout<<"\nDistancia minima "<<dijkstra->getDistance(destino);
                WSockServer MyServer5 = WSockServer();
                MyServer5.RunServer(tostring(dijkstra->getDistance(destino)));

            }else
            {
                floyd->Floyd();
                floyd->getPath(origen, destino);
                cout<<"\nDistancia minima "<<floyd->getDistance(origen, destino);
                WSockServer MyServer3 = WSockServer();
                MyServer3.RunServer(tostring(floyd->getDistance(origen, destino)));
            }
        }
        if(opcion == 1){
            matriz->warshall();
            matriz->printB(matriz->getWarshall());
        }
        if(opcion == 2){
            matriz->warshall();
            matriz->kruskal(matriz->getWarshall());
        }
    }
    return 0;
}
