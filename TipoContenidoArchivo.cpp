#include <iostream>
#include "TipoContenidoArchivo.h"

using namespace std;

TipoContenidoArchivo::TipoContenidoArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int TipoContenidoArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(TipoContenido);
    fclose(pArchivo);
    return cantidad;
}

int TipoContenidoArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}

int TipoContenidoArchivo::buscar(int id)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    TipoContenido reg;
    int pos = 0;
    while(fread(&reg, sizeof(TipoContenido), 1, pArchivo))
    {
        if(reg.getIdTipoContenido() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

TipoContenido TipoContenidoArchivo::leer(int pos)
{
    TipoContenido reg;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr)
    {
        reg.setIdTipoContenido(-1);
        return reg;
    }
    fseek(pArchivo, sizeof(TipoContenido) * pos, SEEK_SET);
    fread(&reg, sizeof(TipoContenido), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int TipoContenidoArchivo::leer(TipoContenido tiposContenido[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(tiposContenido, sizeof(TipoContenido), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool TipoContenidoArchivo::guardar(TipoContenido reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(TipoContenido), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool TipoContenidoArchivo::guardar(int pos, TipoContenido reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(TipoContenido) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(TipoContenido), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool TipoContenidoArchivo::eliminar(int pos)
{
    TipoContenido reg = leer(pos);
    if(reg.getIdTipoContenido() != -1)
    {
        reg.setEliminado(true);
        return guardar(pos, reg);
    }
    return false;
}

bool TipoContenidoArchivo::alta(int pos)
{
    TipoContenido reg = leer(pos);
    if(reg.getIdTipoContenido() != -1)
    {
        reg.setEliminado(false);
        return guardar(pos, reg);
    }
    return false;
}
