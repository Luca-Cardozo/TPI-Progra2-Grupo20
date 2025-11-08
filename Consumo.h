#pragma once
#include "Fecha.h"
#include "Hora.h"

class Consumo
{
private:
    int _idAcceso;
    int _idSuscriptor;
    int _idContenido;
    int _idTipoContenido;
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
    int getIdTipoContenido();
    Fecha getFechaAcceso();
    Hora getHoraAcceso();
    int getDuracionVista();
    bool getEliminado();

    void setIdAcceso(int id);
    void setIdSuscriptor(int id);
    void setIdContenido(int id);
    void setIdTipoContenido(int id);
    void setFechaAcceso(Fecha f);
    void setHoraAcceso(Hora ha);
    void setDuracionVista(int dv);
    void setEliminado(bool e);
};
