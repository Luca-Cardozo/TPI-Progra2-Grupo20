#pragma once
#include "ConsumoArchivo.h"
#include "SuscriptorArchivo.h"
#include "SerieArchivo.h"
#include "PeliculaArchivo.h"

class ConsumoManager
{
private:
    ConsumoArchivo _repoConsumo;
    SuscriptorArchivo _repoSuscriptor;
    SerieArchivo _repoSerie;
    PeliculaArchivo _repoPelicula;
    int validarSuscriptor(int id);
    int validarContenido(int id);
    int validarPelicula(int id);
    int validarSerie(int id);
    int validarDuracion(int id, int dv);
public:
    bool cargarConsumo();
    bool modificarConsumo();
    bool eliminarConsumo();
    bool altaConsumo();
};

