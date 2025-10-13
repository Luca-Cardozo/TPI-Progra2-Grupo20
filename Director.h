#pragma once
#include "Persona.h"


class Director: public Persona
{
private:
    int _idDirector;
    bool _eliminado;
public:
    Director();

    void cargar();
    void mostrar();

    int getIdDirector();
    bool getEliminado();

    void setIdDirector(int id);
    void setEliminado(bool e);
};

