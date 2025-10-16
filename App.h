#pragma once
#include "SuscriptorMenu.h"
#include "SerieMenu.h"
#include "PeliculaMenu.h"
#include "GeneroMenu.h"
#include "ClasificacionMenu.h"
#include "TipoSuscripcionMenu.h"
#include "TipoContenidoMenu.h"
#include "DirectorMenu.h"
#include "ReportesMenu.h"

class App
{
private:
    int _cantidadOpciones;
    SuscriptorMenu _suscriptorMenu;
    SerieMenu _serieMenu;
    PeliculaMenu _peliculaMenu;
    GeneroMenu _generoMenu;
    ClasificacionMenu _clasificacionMenu;
    TipoSuscripcionMenu _tipoSuscripcionMenu;
    TipoContenidoMenu _tipoContenidoMenu;
    DirectorMenu _directorMenu;
    ReportesMenu _reportesMenu;
    void mostrarOpciones();
    int seleccionOpcion();
    void ejecutarOpcion(int opcion);
public:
    App();
    void run();
};
