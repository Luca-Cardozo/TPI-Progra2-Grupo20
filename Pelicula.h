#pragma once
#include "Contenido.h"

class Pelicula: public Contenido
{
private:
    int _duracion;
public:
    Pelicula();

    void cargar();
    void mostrar();

    int getDuracion();

    void setDuracion(int d);
};

