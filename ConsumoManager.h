#pragma once
#include "ConsumoArchivo.h"
#include "SuscriptorArchivo.h"
#include "SerieArchivo.h"
#include "PeliculaArchivo.h"
#include "ListadosManager.h"

class ConsumoManager
{
private:
    ConsumoArchivo _repoConsumo;
    SuscriptorArchivo _repoSuscriptor;
    SerieArchivo _repoSerie;
    PeliculaArchivo _repoPelicula;
    ListadosManager _listados;

    int validarSuscriptor(int id);
    int validarPelicula(int id);
    int validarSerie(int id);
    int validarDuracion(int id, int dv);
    void validarFechaAltaConsumo(Fecha &fechaConsumo, int idSuscriptor, int idContenido, int idTipoContenido);
    bool existeConsumoDuplicado(Consumo nuevo);
    bool existeConsumoDuplicado(int pos, Consumo nuevo);

public:
    bool cargarConsumo();
    bool modificarConsumo();
    bool eliminarConsumo();
    bool altaConsumo();
};

