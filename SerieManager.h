#pragma once
#include "SerieArchivo.h"
#include "DirectorArchivo.h"
#include "GeneroArchivo.h"
#include "ClasificacionArchivo.h"

class SerieManager
{
private:
    SerieArchivo _repoSerie;
    DirectorArchivo _repoDirector;
    GeneroArchivo _repoGenero;
    ClasificacionArchivo _repoClasificacion;
public:
    bool cargarSerie();
    bool modificarSerie();
    bool eliminarSerie();
};

