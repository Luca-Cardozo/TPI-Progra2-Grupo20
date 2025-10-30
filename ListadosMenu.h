#pragma once
#include "ListadosManager.h"

class ListadosMenu
{
private:
    int _cantidadOpciones;
    ListadosManager _listadosManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    ListadosMenu();
    void mostrar();
};
