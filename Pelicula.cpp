#include "Pelicula.h"
#include <iostream>

using namespace std;

Pelicula::Pelicula()
{
    _duracion = 0;
}

void Pelicula::cargar()
{
    Contenido::cargar();
    int d;
    cout << "Duracion (en minutos): ";
    cin >> d;
    setDuracion(d);
}

void Pelicula::mostrar()
{
    Contenido::mostrar();
    cout << "Duracion: " << _duracion << " minutos" << endl;
}

int Pelicula::getDuracion()
{
    return _duracion;
}

void Pelicula::setDuracion(int d)
{
    _duracion = d;
}
