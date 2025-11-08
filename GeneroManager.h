#pragma once
#include "GeneroArchivo.h"
#include "ListadosManager.h"

class GeneroManager
{
private:
    GeneroArchivo _repoGenero;
    ListadosManager _listados;
    std::string validarDescripcion(Genero* pGeneros,  int cant, const char* d);
public:
    bool cargarGenero();
    bool modificarGenero();
    bool eliminarGenero();
    bool altaGenero();
};

