#pragma once
#include "SuscriptorMenu.h"
#include "PeliculaMenu.h"
#include "SerieMenu.h"
#include "GeneroMenu.h"
#include "ClasificacionMenu.h"
#include "TipoSuscripcionMenu.h"
#include "TipoContenidoMenu.h"
#include "DirectorMenu.h"
#include "ConsumoMenu.h"
#include "ListadosMenu.h"
#include "ConsultasMenu.h"
#include "ReportesMenu.h"

class App
{
private:
    int _cantidadOpciones;
    SuscriptorMenu _suscriptorMenu;
    PeliculaMenu _peliculaMenu;
    SerieMenu _serieMenu;
    GeneroMenu _generoMenu;
    ClasificacionMenu _clasificacionMenu;
    TipoSuscripcionMenu _tipoSuscripcionMenu;
    TipoContenidoMenu _tipoContenidoMenu;
    DirectorMenu _directorMenu;
    ConsumoMenu _consumoMenu;
    ListadosMenu _listadosMenu;
    ConsultasMenu _consultasMenu;
    ReportesMenu _reportesMenu;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    App();
    void run();
};
