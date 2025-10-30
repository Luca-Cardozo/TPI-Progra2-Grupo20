#pragma once
#include "TipoContenidoArchivo.h"

class TipoContenidoManager
{
private:
    TipoContenidoArchivo _repoTipoContenido;
    std::string validarDescripcion(TipoContenido* pTiposContenido,  int cant, const char* d);
public:
    bool cargarTipoContenido();
    bool modificarTipoContenido();
    bool eliminarTipoContenido();
    bool altaTipoContenido();
};

