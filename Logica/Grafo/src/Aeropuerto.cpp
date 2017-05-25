#include "Aeropuerto.h"

Aeropuerto::Aeropuerto(string nombre, float posX, float posY, string imagen)
{
    this->nombre = nombre;
    this->posX = posX;
    this->posY = posY;
    this->imagen = imagen;
    id = 0;
}

Aeropuerto::~Aeropuerto()
{

}
string Aeropuerto::getNombre()
{
    return nombre;
}

float Aeropuerto::getPosX()
{
    return posX;
}

float Aeropuerto::getPosY()
{
    return posY;
}

string Aeropuerto::getImagen()
{
    return imagen;
}

int Aeropuerto::getId()
{
    return id;
}

void Aeropuerto::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Aeropuerto::setPosX(float posX)
{
    this->posX = posX;
}

void Aeropuerto::setPosY(float posY)
{
    this->posY = posY;
}

void Aeropuerto::setImagen(string imagen)
{
    this->imagen = imagen;
}

void Aeropuerto::setId(int id)
{
    this->id = id;
}
