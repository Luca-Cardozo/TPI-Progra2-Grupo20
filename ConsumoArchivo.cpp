#include <iostream>
#include "ConsumoArchivo.h"

using namespace std;

ConsumoArchivo::ConsumoArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int ConsumoArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Consumo);
    fclose(pArchivo);
    return cantidad;
}

int ConsumoArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}

int ConsumoArchivo::buscar(int id)
{
    Consumo reg;
    int pos = 0;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    while(fread(&reg, sizeof(Consumo), 1, pArchivo))
    {
        if(reg.getIdAcceso() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Consumo ConsumoArchivo::leer(int pos)
{
    Consumo reg;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr)
    {
        reg.setIdAcceso(-1);
        return reg;
    }
    fseek(pArchivo, sizeof(Consumo) * pos, SEEK_SET);
    fread(&reg, sizeof(Consumo), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int ConsumoArchivo::leer(Consumo consumos[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(consumos, sizeof(Consumo), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool ConsumoArchivo::guardar(Consumo reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(Consumo), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool ConsumoArchivo::guardar(int pos, Consumo reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(Consumo) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(Consumo), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool ConsumoArchivo::eliminar(int pos)
{
    Consumo reg = leer(pos);
    if(reg.getIdAcceso() != -1)
    {
        reg.setEliminado(true);
        return guardar(pos, reg);
    }
    return false;
}

bool ConsumoArchivo::alta(int pos)
{
    Consumo reg = leer(pos);
    if(reg.getIdAcceso() != -1)
    {
        reg.setEliminado(false);
        return guardar(pos, reg);
    }
    return false;
}
