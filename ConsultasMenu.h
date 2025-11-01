#pragma once
#include "ConsultasManager.h"
#include "ListadosManager.h"
#include "DirectorArchivo.h"
#include "GeneroArchivo.h"
#include "ClasificacionArchivo.h"
#include "TipoSuscripcionArchivo.h"

class ConsultasMenu
{
private:
    int _cantidadOpciones;
    ConsultasManager _consultasManager;
    ListadosManager _listadosManager;
    DirectorArchivo _repoDirector;
    GeneroArchivo _repoGenero;
    ClasificacionArchivo _repoClasificacion;
    TipoSuscripcionArchivo _repoTipoSuscripcion;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    ConsultasMenu();
    void mostrar();
};
