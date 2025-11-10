#include <iostream>
#include "SuscriptorArchivo.h"

using namespace std;

SuscriptorArchivo::SuscriptorArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int SuscriptorArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Suscriptor);
    fclose(pArchivo);
    return cantidad;
}

int SuscriptorArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}

int SuscriptorArchivo::buscar(int id)
{
    Suscriptor reg;
    int pos = 0;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    while(fread(&reg, sizeof(Suscriptor), 1, pArchivo))
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

Suscriptor SuscriptorArchivo::leer(int pos)
{
    Suscriptor reg;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return reg;
    fseek(pArchivo, sizeof(Suscriptor) * pos, SEEK_SET);
    fread(&reg, sizeof(Suscriptor), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int SuscriptorArchivo::leer(Suscriptor suscriptores[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(suscriptores, sizeof(Suscriptor), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool SuscriptorArchivo::guardar(Suscriptor reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(Suscriptor), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool SuscriptorArchivo::guardar(int pos, Suscriptor reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(Suscriptor) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(Suscriptor), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool SuscriptorArchivo::eliminar(int pos)
{
    Suscriptor reg = leer(pos);
    if(reg.getId() != 0)
    {
        reg.setEliminado(true);
        return guardar(pos, reg);
    }
    return false;
}

bool SuscriptorArchivo::alta(int pos)
{
    Suscriptor reg = leer(pos);
    if(reg.getId() != 0)
    {
        reg.setEliminado(false);
        return guardar(pos, reg);
    }
    return false;
}
