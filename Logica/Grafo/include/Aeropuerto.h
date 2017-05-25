#ifndef AEROPUERTO_H
#define AEROPUERTO_H
#include <stdexcept>
#include <cstddef>

using namespace std;

class Aeropuerto
{
    public:
        Aeropuerto(string nombre, float posX, float posY, string imagen);
        string getNombre();
        float getPosX();
        float getPosY();
        string getImagen();
        int getId();
        void setNombre(string nombre);
        void setPosX(float posX);
        void setPosY(float posY);
        void setImagen(string imagen);
        void setId(int id);
        virtual ~Aeropuerto();

    private:
        string nombre;
        float posX;
        float posY;
        string imagen;
        int id;
};

#endif // AEROPUERTO_H
