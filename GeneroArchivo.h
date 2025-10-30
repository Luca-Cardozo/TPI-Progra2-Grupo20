#pragma once
#include <string>
#include "Genero.h"

class GeneroArchivo
{
private:
    std::string _nombreArchivo;
public:
    GeneroArchivo(std::string nombreArchivo = "generos.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    Genero leer(int pos);
    int leer(Genero generos[], int cantidad);
    bool guardar(Genero reg);
    bool guardar(int pos, Genero reg);
    bool eliminar(int pos);
    bool alta(int pos);
};

