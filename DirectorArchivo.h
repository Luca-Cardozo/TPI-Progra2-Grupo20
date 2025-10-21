#pragma once
#include <string>
#include "Director.h"

class DirectorArchivo
{
private:
    std::string _nombreArchivo;
public:
    DirectorArchivo(std::string nombreArchivo = "directores.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    Director leer(int pos);
    int leer(Director directores[], int cantidad);
    bool guardar(Director reg);
    bool guardar(int pos, Director reg);
    bool eliminar(int pos);
};
