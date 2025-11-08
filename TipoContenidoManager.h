#pragma once
#include "TipoContenidoArchivo.h"
#include "ListadosManager.h"

class TipoContenidoManager
{
private:
    TipoContenidoArchivo _repoTipoContenido;
    ListadosManager _listados;
    std::string validarDescripcion(TipoContenido* pTiposContenido,  int cant, const char* d);
public:
    bool cargarTipoContenido();
    bool modificarTipoContenido();
    bool eliminarTipoContenido();
    bool altaTipoContenido();
};

