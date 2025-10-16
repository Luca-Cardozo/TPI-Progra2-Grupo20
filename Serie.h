#pragma once
#include "Contenido.h"

class Serie: public Contenido
{
private:
    int _idSerie;
    int _temporadas;
    int _capitulos;
public:
    Serie();

    void cargar();
    void mostrar();

    int getIdSerie();
    int getTemporadas();
    int getCapitulos();

    void setIdSerie(int id);
    void setTemporadas(int t);
    void setCapitulos(int c);
};



