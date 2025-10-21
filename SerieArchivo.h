#pragma once
#include <string>
#include "Serie.h"

class SerieArchivo
{
private:
    std::string _nombreArchivo;
public:
    SerieArchivo(std::string nombreArchivo = "series.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    Serie leer(int pos);
    int leer(Serie series[], int cantidad);
    bool guardar(Serie reg);
    bool guardar(int pos, Serie reg);
    bool eliminar(int pos);
};
