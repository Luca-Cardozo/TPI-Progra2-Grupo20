#pragma once
#include "ReportesManager.h"

class ReportesMenu
{
private:
    int _cantidadOpciones;
    ReportesManager _reportesManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    ReportesMenu();
    void mostrar();
};
