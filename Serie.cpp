#include "Serie.h"
#include "utils.h"
#include "rlutil.h"
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
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Cantidad de temporadas: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> t;
    t = validarPositivo(t);
    setTemporadas(t);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Cantidad de capitulos: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> c;
    c = validarPositivo(c);
    setCapitulos(c);
}

void Serie::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl;
    cout << "ID de la serie: " << _id << endl;
    Contenido::mostrar();
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Temporadas: " << _temporadas << endl;
    cout << "Capitulos: " << _capitulos << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
    rlutil::setColor(rlutil::WHITE);
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




