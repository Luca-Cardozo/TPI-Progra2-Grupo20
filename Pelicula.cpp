#include "Pelicula.h"
#include "utils.h"
#include "rlutil.h"
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
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Duracion (en minutos): ";
    rlutil::setColor(rlutil::WHITE);
    cin >> d;
    d = validarPositivo(d);
    setDuracion(d);
}

void Pelicula::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl;
    cout << "ID de la pelicula: " << _id << endl;
    Contenido::mostrar();
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Duracion: " << _duracion << " minutos" << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
    rlutil::setColor(rlutil::WHITE);
}

int Pelicula::getDuracion()
{
    return _duracion;
}

void Pelicula::setDuracion(int d)
{
    _duracion = d;
}
