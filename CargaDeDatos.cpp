#include "Suscriptor.h"
#include "Director.h"
#include "Pelicula.h"
#include "Serie.h"
#include "Consumo.h"
#include <iostream>

using namespace std;


void cargarSuscriptores()
{
    FILE *p = fopen("suscriptores.dat", "wb");

    if (p == nullptr)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Suscriptor reg;

    for (int i = 0; i < 20; i++)
    {
        reg.setId(i + 1);
        reg.cargar();
        fwrite(&reg, sizeof(Suscriptor), 1, p);
    }

    fclose(p);
    cout << "Archivo creado y 20 suscriptores cargados correctamente." << endl;
}


void cargarDirectores()
{
    FILE *p = fopen("directores.dat", "wb");

    if (p == nullptr)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Director reg;

    for (int i = 0; i < 10; i++)
    {
        reg.setId(i + 1);
        reg.cargar();
        fwrite(&reg, sizeof(Director), 1, p);
    }

    fclose(p);
    cout << "Archivo creado y 10 directores cargados correctamente." << endl;
}


void cargarPeliculas()
{
    FILE *p = fopen("peliculas.dat", "wb");

    if (p == nullptr)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Pelicula reg;

    for (int i = 0; i < 30; i++)
    {
        reg.setId(i + 1);
        reg.setIdTipoContenido(1);
        reg.cargar();
        fwrite(&reg, sizeof(Pelicula), 1, p);
    }

    fclose(p);
    cout << "Archivo creado y 30 peliculas cargadas correctamente." << endl;
}


void cargarSeries()
{
    FILE *p = fopen("series.dat", "wb");

    if (p == nullptr)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Serie reg;

    for (int i = 0; i < 30; i++)
    {
        reg.setId(i + 1);
        reg.setIdTipoContenido(2);
        reg.cargar();
        fwrite(&reg, sizeof(Serie), 1, p);
    }

    fclose(p);
    cout << "Archivo creado y 30 series cargadas correctamente." << endl;
}


void cargarConsumos()
{
    FILE *p = fopen("consumos.dat", "wb");

    if (p == nullptr)
    {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    Consumo reg;

    for (int i = 0; i < 1000; i++)
    {
        reg.setIdAcceso(i + 1);
        reg.cargar();
        fwrite(&reg, sizeof(Consumo), 1, p);
    }

    fclose(p);
    cout << "Archivo creado y 1000 consumos cargados correctamente." << endl;
}
