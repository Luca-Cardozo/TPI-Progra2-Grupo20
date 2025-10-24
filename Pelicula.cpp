#include "Pelicula.h"
#include <iostream>

using namespace std;

Pelicula::Pelicula()
{
    _idPelicula = 0;
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
    cout << "ID de la pelicula: " << _idPelicula << endl;
    cout << "Duracion: " << _duracion << " minutos" << endl;
}

int Pelicula::getIdPelicula()
{
    return _idPelicula;
}
int Pelicula::getDuracion()
{
    return _duracion;
}

void Pelicula::setIdPelicula(int id)
{
    _idPelicula = id;
}
void Pelicula::setDuracion(int d)
{
    _duracion = d;
}
