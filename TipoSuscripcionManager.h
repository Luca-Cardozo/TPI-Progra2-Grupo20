#pragma once
#include "TipoSuscripcionArchivo.h"

class TipoSuscripcionManager
{
private:
    TipoSuscripcionArchivo _repoTipoSuscripcion;
public:
    bool cargarTipoSuscripcion();
    bool modificarTipoSuscripcion();
    bool eliminarTipoSuscripcion();
};

