#pragma once
#include "ConsumoArchivo.h"
#include "SuscriptorArchivo.h"
#include "SerieArchivo.h"
#include "PeliculaArchivo.h"
#include "TipoContenidoArchivo.h"

class ConsumoManager
{
private:
    ConsumoArchivo _repoConsumo;
    SuscriptorArchivo _repoSuscriptor;
    SerieArchivo _repoSerie;
    PeliculaArchivo _repoPelicula;
    TipoContenidoArchivo _repoTipoContenido;
public:
    bool cargarConsumo();
    bool modificarConsumo();
    bool eliminarConsumo();
};

