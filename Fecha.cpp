#include "Fecha.h"
#include <iostream>

using namespace std;

Fecha::Fecha()
{
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    setDia(dia);
    setMes(mes);
    setAnio(anio);
}

bool Fecha::esAnioBisiesto(int anio)
{
    return (anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0);
}

bool Fecha::validarFecha(int d, int m, int a)
{
    if (d < 1 || m < 1 || m > 12 || a < 1) return false;
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (m == 2 && esAnioBisiesto(a))
        diasPorMes[1] = 29;
    return d <= diasPorMes[m - 1];
}

bool Fecha::operator==(const Fecha &otra) const
{
    return _dia == otra._dia && _mes == otra._mes && _anio == otra._anio;
}

bool Fecha::operator<(const Fecha &otra) const
{
    if (_anio < otra._anio) return true;
    if (_anio > otra._anio) return false;
    if (_mes < otra._mes) return true;
    if (_mes > otra._mes) return false;
    return _dia < otra._dia;
}

bool Fecha::operator>(const Fecha &otra) const
{
    return otra < *this;
}

bool Fecha::operator<=(const Fecha &otra) const
{
    return *this < otra || *this == otra;
}
bool Fecha::operator>=(const Fecha &otra) const
{
    return *this > otra || *this == otra;
}

void Fecha::cargar()
{
    int dia, mes, anio;
    bool fechaValida = false;
    do
    {
        cout << "Dia: ";
        cin >> dia;
        setDia(dia);
        cout << "Mes: ";
        cin >> mes;
        setMes(mes);
        cout << "Anio: ";
        cin >> anio;
        setAnio(anio);
        if (validarFecha(dia, mes, anio))
        {
            fechaValida = true;
        }
        else
        {
            cout << "Fecha invalida... Intentelo nuevamente..." << endl;
            system("pause");
            system("cls");
        }
    }
    while(!fechaValida);
}

void Fecha::mostrar()
{
    cout << _dia << "/" << _mes << "/" << _anio << endl;
}

int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}

void Fecha::setDia(int dia)
{
    _dia = dia;
}

void Fecha::setMes(int mes)
{
    _mes = mes;
}

void Fecha::setAnio(int anio)
{
    _anio = anio;
}
