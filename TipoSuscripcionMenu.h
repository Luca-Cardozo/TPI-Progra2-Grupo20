#pragma once
#include "TipoSuscripcionManager.h"

class TipoSuscripcionMenu
{
private:
    int _cantidadOpciones;
    TipoSuscripcionManager _tipoSuscripcionManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    TipoSuscripcionMenu();
    void mostrar();
};

