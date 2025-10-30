#pragma once
#include <string>
#include "TipoSuscripcion.h"

class TipoSuscripcionArchivo
{
private:
    std::string _nombreArchivo;
public:
    TipoSuscripcionArchivo(std::string nombreArchivo = "tipos_suscripcion.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    TipoSuscripcion leer(int pos);
    int leer(TipoSuscripcion tiposSuscripcion[], int cantidad);
    bool guardar(TipoSuscripcion reg);
    bool guardar(int pos, TipoSuscripcion reg);
    bool eliminar(int pos);
    bool alta(int pos);
};

