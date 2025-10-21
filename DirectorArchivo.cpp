#include <iostream>
#include "DirectorArchivo.h"

using namespace std;

DirectorArchivo::DirectorArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int DirectorArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Director);
    fclose(pArchivo);
    return cantidad;
}

int DirectorArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}

int DirectorArchivo::buscar(int id)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    Director reg;
    int pos = 0;
    while(fread(&reg, sizeof(Director), 1, pArchivo))
    {
        if(reg.getIdDirector() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Director DirectorArchivo::leer(int pos)
{
    Director reg;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr)
    {
        reg.setIdDirector(-1);
        return reg;
    }
    fseek(pArchivo, sizeof(Director) * pos, SEEK_SET);
    fread(&reg, sizeof(Director), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int DirectorArchivo::leer(Director directores[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(directores, sizeof(Director), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool DirectorArchivo::guardar(Director reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(Director), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool DirectorArchivo::guardar(int pos, Director reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(Director) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(Director), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool DirectorArchivo::eliminar(int pos)
{
    Director reg = leer(pos);
    if(reg.getIdDirector() != -1)
    {
        reg.setEliminado(true);
        return guardar(pos, reg);
    }
    return false;
}
