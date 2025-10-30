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
    int validarDirector(int id);
    int validarGenero(int id);
    int validarClasificacion(int id);
    std::string validarTitulo(Serie* pSeries,  int cant, const char* t);
public:
    bool cargarSerie();
    bool modificarSerie();
    bool eliminarSerie();
    bool altaSerie();
};

