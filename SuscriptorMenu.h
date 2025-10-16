#pragma once
#include "SuscriptorManager.h"

class SuscriptorMenu
{
private:
    int _cantidadOpciones;
    SuscriptorManager _suscriptorManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    SuscriptorMenu();
    void mostrar();
};






