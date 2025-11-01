#include "Pelicula.h"
#include "utils.h"
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
    d = validarPositivo(d);
    setDuracion(d);
}

void Pelicula::mostrar()
{
    cout << "ID de la pelicula: " << _id << endl;
    Contenido::mostrar();
    cout << "Duracion: " << _duracion << " minutos" << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

int Pelicula::getDuracion()
{
    return _duracion;
}

void Pelicula::setDuracion(int d)
{
    _duracion = d;
}
