#pragma once
#include "SuscriptorArchivo.h"
#include "PeliculaArchivo.h"
#include "SerieArchivo.h"
#include "DirectorArchivo.h"
#include "GeneroArchivo.h"
#include "ClasificacionArchivo.h"
#include "TipoSuscripcionArchivo.h"
#include "ConsumoArchivo.h"

class ConsultasManager
{
private:
    SuscriptorArchivo _repoSuscriptor;
    PeliculaArchivo _repoPelicula;
    SerieArchivo _repoSerie;
    DirectorArchivo _repoDirector;
    ConsumoArchivo _repoConsumo;
    GeneroArchivo _repoGenero;
    ClasificacionArchivo _repoClasificacion;
    TipoSuscripcionArchivo _repoTipoSuscripcion;
public:
    void consultarSuscriptorEmail(const char* email);
    void consultarSuscriptorTelefono(const char* tel);
    void consultarSuscriptorTipoSuscripcion(int id);
    void consultarPeliculaTitulo(const char* titulo);
    void consultarPeliculaDirector(int id);
    void consultarPeliculaGenero(int id);
    void consultarPeliculaClasificacion(int id);
    void consultarSerieTitulo(const char* titulo);
    void consultarSerieDirector(int id);
    void consultarSerieGenero(int id);
    void consultarSerieClasificacion(int id);
    void consultarDirectorNombreApellido(const char* nom, const char* ape);
    void consultarConsumosPorSuscriptor(int id);
    void consultarConsumosPorPelicula(int id);
    void consultarConsumosPorSerie(int id);
};
