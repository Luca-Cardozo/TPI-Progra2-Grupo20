#include "Serie.h"
#include <iostream>

using namespace std;

Serie::Serie()
{
    _idSerie = 0;
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
    Contenido::mostrar();
    cout << "ID de la serie: " << _idSerie << endl;
    cout << "Temporadas: " << _temporadas << endl;
    cout << "Capitulos: " << _capitulos << endl;
}

int Serie::getIdSerie()
{
    return _idSerie;
}
int Serie::getTemporadas()
{
    return _temporadas;
}
int Serie::getCapitulos()
{
    return _capitulos;
}

void Serie::setIdSerie(int id)
{
    _idSerie = id;
}
void Serie::setTemporadas(int t)
{
    _temporadas = t;
}
void Serie::setCapitulos(int c)
{
    _capitulos = c;
}




