#include <iostream>
#include "ClasificacionArchivo.h"

using namespace std;

ClasificacionArchivo::ClasificacionArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int ClasificacionArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Clasificacion);
    fclose(pArchivo);
    return cantidad;
}

int ClasificacionArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}

int ClasificacionArchivo::buscar(int id)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    Clasificacion reg;
    int pos = 0;
    while(fread(&reg, sizeof(Clasificacion), 1, pArchivo))
    {
        if(reg.getIdClasificacion() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Clasificacion ClasificacionArchivo::leer(int pos)
{
    Clasificacion reg;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr)
    {
        reg.setIdClasificacion(-1);
        return reg;
    }
    fseek(pArchivo, sizeof(Clasificacion) * pos, SEEK_SET);
    fread(&reg, sizeof(Clasificacion), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int ClasificacionArchivo::leer(Clasificacion clasificaciones[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(clasificaciones, sizeof(Clasificacion), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool ClasificacionArchivo::guardar(Clasificacion reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(Clasificacion), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool ClasificacionArchivo::guardar(int pos, Clasificacion reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(Clasificacion) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(Clasificacion), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool ClasificacionArchivo::eliminar(int pos)
{
    Clasificacion reg = leer(pos);
    if(reg.getIdClasificacion() != -1)
    {
        reg.setEliminado(true);
        return guardar(pos, reg);
    }
    return false;
}

bool ClasificacionArchivo::alta(int pos)
{
    Clasificacion reg = leer(pos);
    if(reg.getIdClasificacion() != -1)
    {
        reg.setEliminado(false);
        return guardar(pos, reg);
    }
    return false;
}
