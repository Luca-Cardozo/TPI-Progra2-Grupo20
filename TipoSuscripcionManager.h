#pragma once
#include "TipoSuscripcionArchivo.h"
#include "ListadosManager.h"

class TipoSuscripcionManager
{
private:
    TipoSuscripcionArchivo _repoTipoSuscripcion;
    ListadosManager _listados;
    std::string validarDescripcion(TipoSuscripcion* pTiposSuscripcion,  int cant, const char* d);
public:
    bool cargarTipoSuscripcion();
    bool modificarTipoSuscripcion();
    bool eliminarTipoSuscripcion();
    bool altaTipoSuscripcion();
};

