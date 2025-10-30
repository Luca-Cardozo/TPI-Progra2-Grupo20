#pragma once
#include "DirectorArchivo.h"

class DirectorManager
{
private:
    DirectorArchivo _repoDirector;
    bool validarNombreApellido(Director* pDirectores,  int cant, const char* n, const char* a, char nombre[20], char apellido[20]);
public:
    bool cargarDirector();
    bool modificarDirector();
    bool eliminarDirector();
    bool altaDirector();
};

