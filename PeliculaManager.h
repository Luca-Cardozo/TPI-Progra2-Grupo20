#pragma once
#include "PeliculaArchivo.h"
#include "DirectorArchivo.h"
#include "GeneroArchivo.h"
#include "ClasificacionArchivo.h"

class PeliculaManager
{
private:
    PeliculaArchivo _repoPelicula;
    DirectorArchivo _repoDirector;
    GeneroArchivo _repoGenero;
    ClasificacionArchivo _repoClasificacion;
public:
    bool cargarPelicula();
    bool modificarPelicula();
    bool eliminarPelicula();
};
