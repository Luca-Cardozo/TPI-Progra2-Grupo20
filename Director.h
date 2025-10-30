#pragma once
#include "Persona.h"


class Director: public Persona
{
private:
    char _paisResidencia[20];
public:
    Director();

    void cargar();
    void mostrar();

    const char* getPaisResidencia();

    void setPaisResidencia(const char* pais);
};

