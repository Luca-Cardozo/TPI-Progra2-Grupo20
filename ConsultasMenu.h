#pragma once
#include "ConsultasManager.h"
#include "ListadosManager.h"
#include "DirectorArchivo.h"
#include "GeneroArchivo.h"
#include "ClasificacionArchivo.h"
#include "TipoSuscripcionArchivo.h"
#include "SuscriptorArchivo.h"
#include "PeliculaArchivo.h"
#include "SerieArchivo.h"

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
    SuscriptorArchivo _repoSuscriptor;
    PeliculaArchivo _repoPelicula;
    SerieArchivo _repoSerie;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    ConsultasMenu();
    void mostrar();
};
