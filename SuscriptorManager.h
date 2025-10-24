#pragma once
#include "SuscriptorArchivo.h"
#include "TipoSuscripcionArchivo.h"

class SuscriptorManager
{
private:
    SuscriptorArchivo _repoSuscriptor;
    TipoSuscripcionArchivo _repoTipoSuscripcion;
public:
    bool cargarSuscriptor();
    bool modificarSuscriptor();
    bool eliminarSuscriptor();
};

