#pragma once

class Hora
{
private:
    int _hora;
    int _minuto;

public:
    Hora();
    Hora(int hora, int minuto);

    int getHora();
    int getMinuto();
    void setHora(int hora);
    void setMinuto(int minuto);

    void cargar();
    void mostrar();
    bool validarHora(int hora, int minuto);

    bool operator==(const Hora& otra) const;
    bool operator<(const Hora& otra) const;
    bool operator>(const Hora& otra) const;
    bool operator<=(const Hora& otra) const;
    bool operator>=(const Hora& otra) const;
};





