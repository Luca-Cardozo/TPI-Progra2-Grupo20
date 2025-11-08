#pragma once
#include "ClasificacionArchivo.h"
#include "ListadosManager.h"

class ClasificacionManager
{
private:
    ClasificacionArchivo _repoClasificacion;
    ListadosManager _listados;
    std::string validarDescripcion(Clasificacion* pClasificaciones,  int cant, const char* d);
public:
    bool cargarClasificacion();
    bool modificarClasificacion();
    bool eliminarClasificacion();
    bool altaClasificacion();
};

