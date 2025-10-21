#pragma once
#include <string>
#include "Clasificacion.h"

class ClasificacionArchivo
{
private:
    std::string _nombreArchivo;
public:
    ClasificacionArchivo(std::string nombreArchivo = "clasificaciones.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    Clasificacion leer(int pos);
    int leer(Clasificacion clasificaciones[], int cantidad);
    bool guardar(Clasificacion reg);
    bool guardar(int pos, Clasificacion reg);
    bool eliminar(int pos);
};

