#pragma once
#include "GeneroArchivo.h"

class GeneroManager
{
private:
    GeneroArchivo _repoGenero;
public:
    bool cargarGenero();
    bool modificarGenero();
    bool eliminarGenero();
};

