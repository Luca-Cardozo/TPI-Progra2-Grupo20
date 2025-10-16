#pragma once
#include "GeneroManager.h"

class GeneroMenu
{
private:
    int _cantidadOpciones;
    GeneroManager _generoManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    GeneroMenu();
    void mostrar();
};
