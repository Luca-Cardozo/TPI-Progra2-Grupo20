#pragma once
#include <string>
#include "Pelicula.h"

class PeliculaArchivo
{
private:
    std::string _nombreArchivo;
public:
    PeliculaArchivo(std::string nombreArchivo = "peliculas.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    Pelicula leer(int pos);
    int leer(Pelicula peliculas[], int cantidad);
    bool guardar(Pelicula reg);
    bool guardar(int pos, Pelicula reg);
    bool eliminar(int pos);
    bool alta(int pos);
};
