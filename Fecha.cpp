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

void Fecha::cargar()
{
    int dia, mes, anio;
    cout << "Dia: ";
    cin >> dia;
    setDia(dia);
    cout << "Mes: ";
    cin >> mes;
    setMes(mes);
    cout << "Anio: ";
    cin >> anio;
    setAnio(anio);
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
