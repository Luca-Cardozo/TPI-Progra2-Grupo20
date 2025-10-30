#pragma once
#include "ConsultasManager.h"

class ConsultasMenu
{
private:
    int _cantidadOpciones;
    ConsultasManager _consultasManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    ConsultasMenu();
    void mostrar();
};
