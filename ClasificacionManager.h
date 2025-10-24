#pragma once
#include "ClasificacionArchivo.h"

class ClasificacionManager
{
private:
    ClasificacionArchivo _repoClasificacion;
public:
    bool cargarClasificacion();
    bool modificarClasificacion();
    bool eliminarClasificacion();
};

