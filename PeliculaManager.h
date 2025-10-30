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
    int validarDirector(int id);
    int validarGenero(int id);
    int validarClasificacion(int id);
    std::string validarTitulo(Pelicula* pPeliculas,  int cant, const char* t);
public:
    bool cargarPelicula();
    bool modificarPelicula();
    bool eliminarPelicula();
    bool altaPelicula();
};
