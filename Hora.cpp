#include <iostream>
#include "Hora.h"

using namespace std;

Hora::Hora()
{
    _hora = 0;
    _minuto = 0;
}

Hora::Hora(int hora, int minuto)
{
    if (validarHora(hora, minuto))
    {
        _hora = hora;
        _minuto = minuto;
    }
    else
    {
        _hora = 0;
        _minuto = 0;
    }
}

int Hora::getHora()
{
    return _hora;
}
int Hora::getMinuto()
{
    return _minuto;
}

void Hora::setHora(int hora)
{
    if (hora >= 0 && hora < 24)
        _hora = hora;
}

void Hora::setMinuto(int minuto)
{
    if (minuto >= 0 && minuto < 60)
        _minuto = minuto;
}

void Hora::cargar()
{
    int h, m;
    cout << "Ingrese hora (0-23): ";
    cin >> h;
    cout << "Ingrese minutos (0-59): ";
    cin >> m;
    while (!validarHora(h, m))
    {
        cout << "Hora invalida... Intentelo nuevamente..." << endl;
        cout << "Ingrese hora (0-23): ";
        cin >> h;
        cout << "Ingrese minutos (0-59): ";
        cin >> m;
    }
    _hora = h;
    _minuto = m;
}

void Hora::mostrar()
{
    cout << _hora << " hs " << _minuto << " min" << endl;
}

bool Hora::validarHora(int hora, int minuto)
{
    return (hora >= 0 && hora < 24 && minuto >= 0 && minuto < 60);
}

bool Hora::operator==(const Hora& otra) const
{
    return _hora == otra._hora && _minuto == otra._minuto;
}

bool Hora::operator<(const Hora& otra) const
{
    if (_hora < otra._hora) return true;
    if (_hora == otra._hora && _minuto < otra._minuto) return true;
    return false;
}

bool Hora::operator>(const Hora& otra) const
{
    return otra < *this;
}

bool Hora::operator<=(const Hora& otra) const
{
    return !(*this > otra);
}

bool Hora::operator>=(const Hora& otra) const
{
    return !(*this < otra);
}
