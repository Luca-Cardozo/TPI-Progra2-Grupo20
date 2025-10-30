#pragma once
#include "TipoSuscripcionArchivo.h"

class TipoSuscripcionManager
{
private:
    TipoSuscripcionArchivo _repoTipoSuscripcion;
    std::string validarDescripcion(TipoSuscripcion* pTiposSuscripcion,  int cant, const char* d);
public:
    bool cargarTipoSuscripcion();
    bool modificarTipoSuscripcion();
    bool eliminarTipoSuscripcion();
    bool altaTipoSuscripcion();
};

