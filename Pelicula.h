#pragma once
#include "Contenido.h"

class Pelicula: public Contenido
{
private:
    int _idPelicula;
    int _duracion;
public:
    Pelicula();

    void cargar();
    void mostrar();

    int getIdPelicula();
    int getDuracion();

    void setIdPelicula(int id);
    void setDuracion(int d);
};

