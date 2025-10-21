#pragma once
#include "ConsumoManager.h"

class ConsumoMenu
{
private:
    int _cantidadOpciones;
    ConsumoManager _peliculaManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    ConsumoMenu();
    void mostrar();
};


