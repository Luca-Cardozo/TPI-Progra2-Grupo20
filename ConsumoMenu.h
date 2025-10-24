#pragma once
#include "ConsumoManager.h"

class ConsumoMenu
{
private:
    int _cantidadOpciones;
    ConsumoManager _consumoManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    ConsumoMenu();
    void mostrar();
};


