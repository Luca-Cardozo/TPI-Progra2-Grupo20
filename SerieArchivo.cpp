#include <iostream>
#include "SerieArchivo.h"

using namespace std;

SerieArchivo::SerieArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int SerieArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Serie);
    fclose(pArchivo);
    return cantidad;
}

int SerieArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}

int SerieArchivo::buscar(int id)
{
    Serie reg;
    int pos = 0;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    while(fread(&reg, sizeof(Serie), 1, pArchivo))
    {
        if(reg.getId() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Serie SerieArchivo::leer(int pos)
{
    Serie reg;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr)
    {
        reg.setId(-1);
        return reg;
    }
    fseek(pArchivo, sizeof(Serie) * pos, SEEK_SET);
    fread(&reg, sizeof(Serie), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int SerieArchivo::leer(Serie series[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(series, sizeof(Serie), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool SerieArchivo::guardar(Serie reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(Serie), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool SerieArchivo::guardar(int pos, Serie reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(Serie) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(Serie), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool SerieArchivo::eliminar(int pos)
{
    Serie reg = leer(pos);
    if(reg.getId() != -1)
    {
        reg.setEliminado(true);
        return guardar(pos, reg);
    }
    return false;
}

bool SerieArchivo::alta(int pos)
{
    Serie reg = leer(pos);
    if(reg.getId() != -1)
    {
        reg.setEliminado(false);
        return guardar(pos, reg);
    }
    return false;
}
