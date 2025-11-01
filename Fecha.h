#pragma once

class Fecha
{
private:
    int _dia, _mes, _anio;

    bool esAnioBisiesto(int anio);
    bool validarFecha(int d, int m, int a);

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    void cargar();
    void mostrar();

    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    bool operator==(const Fecha &otra) const;
    bool operator<(const Fecha &otra) const;
    bool operator>(const Fecha &otra) const;
    bool operator<=(const Fecha &otra) const;
    bool operator>=(const Fecha &otra) const;
};
