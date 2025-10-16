#pragma once
#include "SerieManager.h"

class SerieMenu
{
private:
    int _cantidadOpciones;
    SerieManager _serieManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    SerieMenu();
    void mostrar();
};
