#include "Serie.h"
#include <iostream>

using namespace std;

Serie::Serie()
{
    _temporadas = 0;
    _capitulos = 0;
}

void Serie::cargar()
{
    Contenido::cargar();
    int t, c;
    cout << "Cantidad de temporadas: ";
    cin >> t;
    setTemporadas(t);
    cout << "Cantidad de capitulos: ";
    cin >> c;
    setCapitulos(c);
}

void Serie::mostrar()
{
    cout << "ID de la serie: " << _id << endl;
    Contenido::mostrar();
    cout << "Temporadas: " << _temporadas << endl;
    cout << "Capitulos: " << _capitulos << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

int Serie::getTemporadas()
{
    return _temporadas;
}
int Serie::getCapitulos()
{
    return _capitulos;
}

void Serie::setTemporadas(int t)
{
    _temporadas = t;
}
void Serie::setCapitulos(int c)
{
    _capitulos = c;
}




