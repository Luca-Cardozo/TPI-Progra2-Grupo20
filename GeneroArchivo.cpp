#include <iostream>
#include "GeneroArchivo.h"

using namespace std;

GeneroArchivo::GeneroArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int GeneroArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Genero);
    fclose(pArchivo);
    return cantidad;
}

int GeneroArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}

int GeneroArchivo::buscar(int id)
{
    Genero reg;
    int pos = 0;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    while(fread(&reg, sizeof(Genero), 1, pArchivo))
    {
        if(reg.getIdGenero() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Genero GeneroArchivo::leer(int pos)
{
    Genero reg;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr)
    {
        reg.setIdGenero(-1);
        return reg;
    }
    fseek(pArchivo, sizeof(Genero) * pos, SEEK_SET);
    fread(&reg, sizeof(Genero), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int GeneroArchivo::leer(Genero generos[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(generos, sizeof(Genero), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool GeneroArchivo::guardar(Genero reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(Genero), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool GeneroArchivo::guardar(int pos, Genero reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(Genero) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(Genero), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool GeneroArchivo::eliminar(int pos)
{
    Genero reg = leer(pos);
    if(reg.getIdGenero() != -1)
    {
        reg.setEliminado(true);
        return guardar(pos, reg);
    }
    return false;
}

bool GeneroArchivo::alta(int pos)
{
    Genero reg = leer(pos);
    if(reg.getIdGenero() != -1)
    {
        reg.setEliminado(false);
        return guardar(pos, reg);
    }
    return false;
}
