#pragma once
#include "ClasificacionArchivo.h"

class ClasificacionManager
{
private:
    ClasificacionArchivo _repoClasificacion;
    std::string validarDescripcion(Clasificacion* pClasificaciones,  int cant, const char* d);
public:
    bool cargarClasificacion();
    bool modificarClasificacion();
    bool eliminarClasificacion();
    bool altaClasificacion();
};

