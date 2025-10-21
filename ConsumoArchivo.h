#pragma once
#include <string>
#include "Consumo.h"

class ConsumoArchivo
{
private:
    std::string _nombreArchivo;
public:
    ConsumoArchivo(std::string nombreArchivo = "consumos.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    Consumo leer(int pos);
    int leer(Consumo consumos[], int cantidad);
    bool guardar(Consumo reg);
    bool guardar(int pos, Consumo reg);
    bool eliminar(int pos);
};
