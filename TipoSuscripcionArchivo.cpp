#include <iostream>
#include "TipoSuscripcionArchivo.h"

using namespace std;

TipoSuscripcionArchivo::TipoSuscripcionArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int TipoSuscripcionArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(TipoSuscripcion);
    fclose(pArchivo);
    return cantidad;
}

int TipoSuscripcionArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}

int TipoSuscripcionArchivo::buscar(int id)
{
    TipoSuscripcion reg;
    int pos = 0;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    while(fread(&reg, sizeof(TipoSuscripcion), 1, pArchivo))
    {
        if(reg.getIdTipoSuscripcion() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

TipoSuscripcion TipoSuscripcionArchivo::leer(int pos)
{
    TipoSuscripcion reg;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return reg;
    fseek(pArchivo, sizeof(TipoSuscripcion) * pos, SEEK_SET);
    fread(&reg, sizeof(TipoSuscripcion), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int TipoSuscripcionArchivo::leer(TipoSuscripcion tiposSuscripcion[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(tiposSuscripcion, sizeof(TipoSuscripcion), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool TipoSuscripcionArchivo::guardar(TipoSuscripcion reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(TipoSuscripcion), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool TipoSuscripcionArchivo::guardar(int pos, TipoSuscripcion reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(TipoSuscripcion) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(TipoSuscripcion), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool TipoSuscripcionArchivo::eliminar(int pos)
{
    TipoSuscripcion reg = leer(pos);
    if(reg.getIdTipoSuscripcion() != 0)
    {
        reg.setEliminado(true);
        return guardar(pos, reg);
    }
    return false;
}

bool TipoSuscripcionArchivo::alta(int pos)
{
    TipoSuscripcion reg = leer(pos);
    if(reg.getIdTipoSuscripcion() != 0)
    {
        reg.setEliminado(false);
        return guardar(pos, reg);
    }
    return false;
}
