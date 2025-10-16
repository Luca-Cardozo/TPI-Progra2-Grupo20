#pragma once
#include "DirectorManager.h"

class DirectorMenu
{
private:
    int _cantidadOpciones;
    DirectorManager _directorManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    DirectorMenu();
    void mostrar();
};
