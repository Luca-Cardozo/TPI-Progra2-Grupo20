#pragma once
#include "SerieArchivo.h"
#include "DirectorArchivo.h"
#include "GeneroArchivo.h"
#include "ClasificacionArchivo.h"
#include "ListadosManager.h"

class SerieManager
{
private:
    SerieArchivo _repoSerie;
    DirectorArchivo _repoDirector;
    GeneroArchivo _repoGenero;
    ClasificacionArchivo _repoClasificacion;
    ListadosManager _listados;

    int validarDirector(int id);
    int validarGenero(int id);
    int validarClasificacion(int id);
    std::string validarTitulo(Serie* pSeries,  int cant, const char* t, int idActual = -1);
public:
    bool cargarSerie();
    bool modificarSerie();
    bool eliminarSerie();
    bool altaSerie();
};

