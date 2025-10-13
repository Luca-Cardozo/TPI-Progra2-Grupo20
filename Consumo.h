#pragma once
#include "Fecha.h"

class Consumo
{
private:
    int _idSuscriptor;
    int _idContenido;
    int _tipoContenido;
    Fecha _fechaAcceso;
    int _horaAcceso;
    int _duracionVista;
    bool _eliminado;
public:
    Consumo();

    void cargar();
    void mostrar();

    int getIdSuscriptor();
    int getIdContenido();
    int getTipoContenido();
    Fecha getFechaAcceso();
    int getHoraAcceso();
    int getDuracionVista();
    bool getEliminado();

    void setIdSuscriptor(int id);
    void setIdContenido(int id);
    void setTipoContenido(int tc);
    void setFechaAcceso(Fecha f);
    void setHoraAcceso(int ha);
    void setDuracionVista(int dv);
    void setEliminado(bool e);
};
