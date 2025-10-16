#pragma once
#include "ClasificacionManager.h"

class ClasificacionMenu
{
private:
    int _cantidadOpciones;
    ClasificacionManager _clasificacionManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    ClasificacionMenu();
    void mostrar();
};
