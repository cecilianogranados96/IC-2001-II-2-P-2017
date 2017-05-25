#include "ArrayList.h"
#include <iostream>
#include <stdexcept>
#define DEFAULT_MAX_SIZE 1024

using namespace std;

//Constructor vacío
ArrayList::ArrayList(){}

//Constructor con parámetros
ArrayList::ArrayList(int pMax = DEFAULT_MAX_SIZE){
	elements = new int[pMax];
	size = 0;
	pos = 0;
	max = pMax;
}

//Método getValue: devuelve el valor en pos
int ArrayList::getValue(){
    try
    {
        if(pos<0 || pos>size){
            throw runtime_error("La posicion esta fuera de los limites");
        }
        else if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        return elements[pos];
    }
    catch (runtime_error e)
    {
        cout << "Error: " << e.what()<<"\n\n";
    }
}

//Método getPos: devuelve pos
int ArrayList::getPos(){
	return pos;
}

//Método getSize: devuelve el tamaño de la lista
int ArrayList::getSize(){
	return size;
}

//Método getSize: devuelve el tamaño de la lista
int ArrayList::getMax(){
	return max;
}

void ArrayList::setValue(int value)
{
    elements[pos] = value;
}

//Método goToStart: situa el pos al inicio de la lista
void ArrayList::goToStart(){
	pos = 0;
}

//Método goToEnd: situa el pos al final de la lista
void ArrayList::goToEnd(){
    pos = size-1;
}

//Método goToPos: pone el pos en la posición dada como parámetro
void ArrayList::goToPos(int pos){
    try
    {
        if(pos<0 || pos>size){
            throw runtime_error("La posicion esta fuera de los limites");
        }
        this->pos = pos;
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }
}

//Método previous: pone el pos en la posición anterior
void ArrayList::previous(){
	if (pos>0){
		pos--;
	}
}

//Método next: pone el pos en la posición siguiente
void ArrayList::next(){
	if (pos+1<size){
		pos++;
	}
}

//Método append: añade un elemento al final de la lista
void ArrayList::append(int element){
    try
    {
        if(size == max){
            throw runtime_error("La cola esta llena");
        }
        elements[size] = element;
        size++;
    }
    catch (runtime_error e)
    {
     cout << "Error: " << e.what()<<"\n\n";
    }

}

//Método insert: inserta un elemento después del pos
void ArrayList::insert(int element){
    try
    {
        if(size == max){
            throw runtime_error("La cola esta llena");
        }

        for(int i=size;i>pos;i--){
            elements[i] = elements[i-1];
        }
        elements[pos] = element;
        size++;
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

//Función remove: elimina el elemento siguiente del pos
int ArrayList::remove(){
    try
    {
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }
        int deleteElement = elements[pos];

        for(int i=pos;i<size;i++){
            elements[i] = elements[i+1];
        }

        size--;
        return deleteElement;
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

//Método print: imprime la lista
void ArrayList::print(){
    try
    {
        if (size == 0){
            throw runtime_error("La cola esta vacia");
        }

        for(int i=0;i<size;i++){
            cout<<elements[i]<<"\t";
        }
        cout<<"\n\n";
    }
    catch (runtime_error e)
    {
        cout << "Error: "<< e.what()<<"\n\n";
    }
}

//Método clear: elimina la lista de arreglos
void ArrayList::clear()
{
    try
    {
        size = 0;
        pos = 0;
        delete []elements;
    }
    catch (runtime_error e)
    {
        cout << "Error: no se puede borrar"; //<< e.what();
    }
}

//Función bubble sort
void ArrayList::bubbleSort(){
    int x, y;
    for(int i = 1; i <= size; ++i) {
        for(int j = 0; j <= size-i; ++j) {
            goToPos(j);
            x = getValue();
            goToPos(j+1);
            y = getValue();
            if(x>y){
                goToPos(j);
                setValue(y);
                goToPos(j+1);
                setValue(x);
            }
        }
    }
}
//Método destructor de la clase
ArrayList::~ArrayList(){
	clear();
}
