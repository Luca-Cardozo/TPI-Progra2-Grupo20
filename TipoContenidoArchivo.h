#pragma once
#include <string>
#include "TipoContenido.h"

class TipoContenidoArchivo
{
private:
    std::string _nombreArchivo;
public:
    TipoContenidoArchivo(std::string nombreArchivo = "tipos_contenido.dat");
    int getCantidadRegistros();
    int getNuevoID();
    int buscar(int id);
    TipoContenido leer(int pos);
    int leer(TipoContenido tiposContenido[], int cantidad);
    bool guardar(TipoContenido reg);
    bool guardar(int pos, TipoContenido reg);
    bool eliminar(int pos);
};

