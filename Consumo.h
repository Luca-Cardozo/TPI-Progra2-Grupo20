#pragma once
#include "Fecha.h"

class Consumo
{
private:
    int _idAcceso;
    int _idSuscriptor;
    int _idContenido;
    Fecha _fechaAcceso;
    int _horaAcceso;
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
    int getHoraAcceso();
    int getDuracionVista();
    bool getEliminado();

    void setIdAcceso(int id);
    void setIdSuscriptor(int id);
    void setIdContenido(int id);
    void setFechaAcceso(Fecha f);
    void setHoraAcceso(int ha);
    void setDuracionVista(int dv);
    void setEliminado(bool e);
};
