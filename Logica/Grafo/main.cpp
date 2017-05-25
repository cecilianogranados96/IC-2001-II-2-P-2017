#include <iostream>
#include <conio.h>
#include <stdexcept>
#include <cstddef>
#include <stdlib.h>
#include "Aeropuerto.h"
#include "CaminoMinimo.h"
#include "TodoCaminoMinimo.h"
#include "Graph.h"
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int main(void)
{
    float posX,posY;
    string nombre, imagen;
    int origen, destino, peso;

    std::string textline;
    ifstream fileA ("aeropuertos.txt");
    ifstream file ("aeropuertos.txt");
    ifstream fileR ("rutas.txt");

    int lines = 0;
    std::string line;
    while(getline(file, line))
        ++lines;
    file.close();

    Graph* matriz = new Graph(lines);

    //Lee los aeropuertos y crea cada nodo
    while (getline(fileA, textline))
    {
       string comma_string;
       std::istringstream text_stream(textline);
       text_stream >> nombre;
       //getline(text_stream, nombre, ',');
       getline(text_stream, comma_string, ','); // Read characters after number until comma.
       text_stream >> posX;
       getline(text_stream, comma_string, ','); // Read characters after number until comma.
       text_stream >> posY;
       getline(text_stream, comma_string, ',');
       getline(text_stream, imagen, '\n');

       matriz->addVertex(new Aeropuerto(nombre, posX, posY, imagen));
    }

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

    matriz->print(matriz->getGraph());

    /*TodoCaminoMinimo* algoritmo = new TodoCaminoMinimo(matriz);

    algoritmo->Floyd();
    algoritmo->recuperaCamino(2,3);
    cout<<"\nDistancia minima "<<algoritmo->Odistancia()[2][3];
    cout<<endl;*/
    matriz->warshall();
    matriz->printB(matriz->getWarshall());

    /*std::string textline;
    int numero;
    fstream myfile;
    myfile.open ("rutas_cal.txt", ios::out | ios::trunc);
    for(int i=0; i<6; i++)
        myfile << i<<"\n";
    myfile.close();

    myfile.open("rutas_cal.txt", ios::in);
    while(getline(myfile, textline)){
        std::istringstream text_stream(textline);
        text_stream >> numero;
        cout<<"Vertice: "<<numero<<"\t";
    }*/


    //Debe leer el maximo del numero de lineas del archivo
    /*Graph* matriz = new Graph(5);

    matriz->addVertex(new Aeropuerto("V1",0,0,"0"));
    matriz->addVertex(new Aeropuerto("V2",0,0,"0"));
    matriz->addVertex(new Aeropuerto("V3",0,0,"0"));
    matriz->addVertex(new Aeropuerto("V4",0,0,"0"));
    matriz->addVertex(new Aeropuerto("V5",0,0,"0"));

    matriz->addEdge(0, 1, 6);
    matriz->addEdge(0, 4, 7);
    matriz->addEdge(0, 3, 4);

    matriz->addEdge(1, 0, 9);
    matriz->addEdge(1, 2, 7);

    matriz->addEdge(2, 1, 5);
    matriz->addEdge(2, 4, 14);

    matriz->addEdge(3, 0, 8);
    matriz->addEdge(3, 1, 1);
    matriz->addEdge(3, 4, 15);

    matriz->addEdge(4, 0, 2);
    matriz->addEdge(4, 2, 2);
    matriz->addEdge(4, 3, 19);

    matriz->print(matriz->getGraph());

    TodoCaminoMinimo* algoritmo = new TodoCaminoMinimo(matriz);

    algoritmo->Floyd();
    algoritmo->recuperaCamino(2, 3);
    cout<<endl;
    /*algoritmo->recuperaCamino(1);
    cout<<endl;
    algoritmo->recuperaCamino(2);
    cout<<endl;
    algoritmo->recuperaCamino(3);
    cout<<endl;
    algoritmo->recuperaCamino(4);
    cout<<endl;
    algoritmo->recuperaCamino(5);
    cout<<endl;
    cout<<algoritmo->OdistanciaMinima()[4]<<endl;*/

    /*int op;     // opcion del menu

    system("color 0b");

    do
    {
        cout<<"\n\tREPRESENTACION DE GRAFOS DIRIGIDOS\n\n";
        cout<<" 1. INSERTAR UN NODO                 "<<endl;
        cout<<" 2. INSERTAR UNA ARISTA              "<<endl;
        cout<<" 3. CONOCER ADYACENCIA               "<<endl;
        cout<<" 4. MOSTRAR  GRAFO                   "<<endl;
        cout<<" 5. MOSTRAR  MATRIZ WARSHALL         "<<endl;
        cout<<" 6. SALIR                            "<<endl;

        cout<<"\n INGRESE OPCION: ";

        cin>>op;

        switch(op)
        {
            case 1:
                {
                    string nombre, imagen;
                    int posX, posY;
                    cout<<"INGRESE EL NOMBRE DEL AEROPUERTO:";
                    cin>>nombre;
                    cout<<"INGRESE LA POSX:";
                    cin>>posX;
                    cout<<"INGRESE LA POSY:";
                    cin>>posY;
                    cout<<"INGRESE LA IMAGEN:";
                    cin>>imagen;

                    grafo->addVertex(new Aeropuerto(nombre, posX, posY, imagen));

                    if(grafo->getGraph()->getSize()==1)
                    {
                        cout<<"PRIMER NODO...!!!";
                    }
                    else
                    {
                        cout<<"NODO INGRESADO...!!!";
                    }

                }
                break;
            case 2:
                {
                    int ini, fin;
                    int peso;
                    if(grafo->getGraph()->getSize()<2)
                    {
                        cout<<"NO HAY SUFICIENTES VERTICES";
                        break;
                    }
                    cout<<"INGRESE NODO DE INICIO:";
                    cin>>ini;
                    cout<<"INGRESE NODO FINAL:";
                    cin>>fin;
                    cout<<"INGRESE EL PESO:";
                    cin>>peso;
                    grafo->addEdge(ini, fin, peso);
                    cout<<"ARISTA INSERTADA";
                }
                    break;
            case 3:
                {
                    int ini, fin;
                    if(grafo->getGraph()->getSize()<2)
                    {
                        cout<<"NO HAY SUFICIENTES VERTICES";
                        break;
                    }
                    cout<<"INGRESE NODO DE INICIO:";
                    cin>>ini;
                    cout<<"INGRESE NODO FINAL:";
                    cin>>fin;

                    if(grafo->adjacent(ini, fin))
                        cout<<"SON ADYACENTES";
                    else
                        cout<<"NO SON ADYACENTES";
                }
                    break;
            case 4:
                {
                    grafo->print(grafo->getGraph());
                }
                    break;

            case 5:
                {
                    grafo->warshall();
                    grafo->print(grafo->getWarshall());
                }
                    break;

            default: cout<<"OPCION NO VALIDA...!!!";
                     break;


        }

        cout<<endl<<endl;
        system("pause");  system("cls");

    }while(op!=6);
    getch();*/
    return 0;
}

