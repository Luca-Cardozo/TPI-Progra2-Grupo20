#pragma once
#include "DirectorArchivo.h"
#include "ListadosManager.h"

class DirectorManager
{
private:
    DirectorArchivo _repoDirector;
    ListadosManager _listados;
    bool validarNombreApellido(Director* pDirectores,  int cant, const char* n, const char* a, char nombre[20], char apellido[20], int idActual = -1);
public:
    bool cargarDirector();
    bool modificarDirector();
    bool eliminarDirector();
    bool altaDirector();
};

