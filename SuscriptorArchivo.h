#pragma once
#include <string>
#include "Suscriptor.h"

class SuscriptorArchivo
{
private:
    std::string _nombreArchivo;
public:
    SuscriptorArchivo(std::string nombreArchivo = "suscriptores.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    Suscriptor leer(int pos);
    int leer(Suscriptor suscriptores[], int cantidad);
    bool guardar(Suscriptor reg);
    bool guardar(int pos, Suscriptor reg);
    bool eliminar(int pos);
};
