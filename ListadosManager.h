#pragma once
#include "SuscriptorArchivo.h"
#include "PeliculaArchivo.h"
#include "SerieArchivo.h"
#include "DirectorArchivo.h"
#include "GeneroArchivo.h"
#include "ClasificacionArchivo.h"
#include "TipoContenidoArchivo.h"
#include "TipoSuscripcionArchivo.h"

class ListadosManager
{
private:
    SuscriptorArchivo _repoSuscriptor;
    PeliculaArchivo _repoPelicula;
    SerieArchivo _repoSerie;
    DirectorArchivo _repoDirector;
    GeneroArchivo _repoGenero;
    ClasificacionArchivo _repoClasificacion;
    TipoContenidoArchivo _repoTipoContenido;
    TipoSuscripcionArchivo _repoTipoSuscripcion;
public:
    void listarSuscriptoresApellido();
    void listarSuscriptoresFechaAlta(bool criterio(Fecha, Fecha));
    void listarPeliculasTitulo();
    void listarPeliculasFechaEstreno(bool criterio(Fecha, Fecha));
    void listarPeliculasDuracion(bool criterio(int, int));
    void listarSeriesTitulo();
    void listarSeriesFechaEstreno(bool criterio(Fecha, Fecha));
    void listarSeriesCapitulos(bool criterio(int, int));
    void listarDirectoresApellido();
    void listarGeneros();
    void listarClasificaciones();
    void listarTiposContenido();
    void listarTiposSuscripcion();
};
