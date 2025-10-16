#pragma once
#include "Persona.h"


class Director: public Persona
{
private:
    int _idDirector;
public:
    Director();

    void cargar();
    void mostrar();

    int getIdDirector();

    void setIdDirector(int id);
};

