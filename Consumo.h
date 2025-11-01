#pragma once
#include "Fecha.h"
#include "Hora.h"

class Consumo
{
private:
    int _idAcceso;
    int _idSuscriptor;
    int _idContenido;
    Fecha _fechaAcceso;
    Hora _horaAcceso;
    int _duracionVista;
    bool _eliminado;
public:
    Consumo();

    void cargar();
    void mostrar();

    int getIdAcceso();
    int getIdSuscriptor();
    int getIdContenido();
    Fecha getFechaAcceso();
    Hora getHoraAcceso();
    int getDuracionVista();
    bool getEliminado();

    void setIdAcceso(int id);
    void setIdSuscriptor(int id);
    void setIdContenido(int id);
    void setFechaAcceso(Fecha f);
    void setHoraAcceso(Hora ha);
    void setDuracionVista(int dv);
    void setEliminado(bool e);
};
