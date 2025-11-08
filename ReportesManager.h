#pragma once
#include "SuscriptorArchivo.h"
#include "PeliculaArchivo.h"
#include "SerieArchivo.h"
#include "GeneroArchivo.h"
#include "ConsumoArchivo.h"

class ReportesManager
{
private:
    SuscriptorArchivo _repoSuscriptor;
    PeliculaArchivo _repoPelicula;
    SerieArchivo _repoSerie;
    ConsumoArchivo _repoConsumo;
    GeneroArchivo _repoGenero;
public:
    void cantConsumosPorSuscriptor(Fecha f1, Fecha f2);
    void cantConsumosPorTitulo(Fecha f1, Fecha f2);
    void cantConsumosPorTipoContenido(Hora h1, Hora h2);
    void top5SuscriptoresMayorVisualizacion(int anio);
    void top10ContenidoMasConsumido(int anio);
    void consumosPorGenero(int anio);
    void minutosConsumidosPorTipoContenido(int anio);
    void promedioMensualMinutosConsumidosPorTipoSuscripcion(int anio);
    void promedioDiarioMinutosConsumidosPorSuscriptor(int mes, int anio);
    void porcentajeMensualTiempoConsumidoPorTipoContenido(int anio);
};

