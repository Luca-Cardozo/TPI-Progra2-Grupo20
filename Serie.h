#pragma once
#include "Contenido.h"

class Serie: public Contenido
{
private:
    int _temporadas;
    int _capitulos;
public:
    Serie();

    void cargar();
    void mostrar();

    int getTemporadas();
    int getCapitulos();

    void setTemporadas(int t);
    void setCapitulos(int c);
};



