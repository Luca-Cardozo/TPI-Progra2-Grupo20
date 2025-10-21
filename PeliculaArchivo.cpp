#include <iostream>
#include "PeliculaArchivo.h"

using namespace std;

PeliculaArchivo::PeliculaArchivo(std::string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

int PeliculaArchivo::getCantidadRegistros()
{
    int cantidad;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    fseek(pArchivo, 0, SEEK_END);
    cantidad = ftell(pArchivo) / sizeof(Pelicula);
    fclose(pArchivo);
    return cantidad;
}

int PeliculaArchivo::getNuevoID()
{
    return getCantidadRegistros() + 1;
}

int PeliculaArchivo::buscar(int id)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return -1;
    Pelicula reg;
    int pos = 0;
    while(fread(&reg, sizeof(Pelicula), 1, pArchivo))
    {
        if(reg.getIdPelicula() == id)
        {
            fclose(pArchivo);
            return pos;
        }
        pos++;
    }
    fclose(pArchivo);
    return -1;
}

Pelicula PeliculaArchivo::leer(int pos)
{
    Pelicula reg;
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr)
    {
        reg.setIdPelicula(-1);
        return reg;
    }
    fseek(pArchivo, sizeof(Pelicula) * pos, SEEK_SET);
    fread(&reg, sizeof(Pelicula), 1, pArchivo);
    fclose(pArchivo);
    return reg;
}

int PeliculaArchivo::leer(Pelicula peliculas[], int cantidad)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb");
    if(pArchivo == nullptr) return 0;
    int resultado = fread(peliculas, sizeof(Pelicula), cantidad, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool PeliculaArchivo::guardar(Pelicula reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "ab");
    if(pArchivo == nullptr) return false;
    bool resultado = fwrite(&reg, sizeof(Pelicula), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool PeliculaArchivo::guardar(int pos, Pelicula reg)
{
    FILE *pArchivo = fopen(_nombreArchivo.c_str(), "rb+");
    if(pArchivo == nullptr) return false;
    fseek(pArchivo, sizeof(Pelicula) * pos, SEEK_SET);
    bool resultado = fwrite(&reg, sizeof(Pelicula), 1, pArchivo);
    fclose(pArchivo);
    return resultado;
}

bool PeliculaArchivo::eliminar(int pos)
{
    Pelicula reg = leer(pos);
    if(reg.getIdPelicula() != -1)
    {
        reg.setEliminado(true);
        return guardar(pos, reg);
    }
    return false;
}
