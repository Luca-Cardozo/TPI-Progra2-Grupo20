#pragma once
#include "PeliculaManager.h"

class PeliculaMenu
{
private:
    int _cantidadOpciones;
    PeliculaManager _peliculaManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    PeliculaMenu();
    void mostrar();
};
