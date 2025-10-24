#pragma once
#include "TipoContenidoArchivo.h"

class TipoContenidoManager
{
private:
    TipoContenidoArchivo _repoTipoContenido;
public:
    bool cargarTipoContenido();
    bool modificarTipoContenido();
    bool eliminarTipoContenido();
};

