#pragma once
#include "TipoContenidoManager.h"

class TipoContenidoMenu
{
private:
    int _cantidadOpciones;
    TipoContenidoManager _tipoContenidoManager;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    TipoContenidoMenu();
    void mostrar();
};

