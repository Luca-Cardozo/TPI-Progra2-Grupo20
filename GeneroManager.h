#pragma once
#include "GeneroArchivo.h"

class GeneroManager
{
private:
    GeneroArchivo _repoGenero;
    std::string validarDescripcion(Genero* pGeneros,  int cant, const char* d);
public:
    bool cargarGenero();
    bool modificarGenero();
    bool eliminarGenero();
    bool altaGenero();
};

