#include "Consumo.h"
#include "utils.h"
#include <iostream>

using namespace std;

Consumo::Consumo()
{
    _idAcceso = 0;
    _idSuscriptor = 0;
    _idContenido = 0;
    _duracionVista = 0;
    _eliminado = false;
}

void Consumo::cargar()
{
    int idS, idC, dv;
    Fecha f;
    Hora ha;
    cout << "ID Suscriptor: ";
    cin >> idS;
    setIdSuscriptor(idS);
    cout << "ID Contenido: ";
    cin >> idC;
    setIdContenido(idC);
    cout << "Fecha de acceso:" << endl;
    f.cargar();
    setFechaAcceso(f);
    cout << "Hora de acceso:" << endl;
    ha.cargar();
    setHoraAcceso(ha);
    cout << "Duracion vista (en minutos): ";
    cin >> dv;
    dv = validarPositivo(dv);
    setDuracionVista(dv);
    _eliminado = false;
}

void Consumo::mostrar()
{
    cout << "ID Acceso: " << _idAcceso << endl;
    cout << "ID Suscriptor: " << _idSuscriptor << endl;
    cout << "ID Contenido: " << _idContenido << endl;
    cout << "Fecha Acceso: ";
    _fechaAcceso.mostrar();
    cout << "Hora Acceso: ";
    _horaAcceso.mostrar();
    cout << "Duracion Vista: " << _duracionVista << " minutos" << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

int Consumo::getIdAcceso()
{
    return _idAcceso;
}
int Consumo::getIdSuscriptor()
{
    return _idSuscriptor;
}
int Consumo::getIdContenido()
{
    return _idContenido;
}
Fecha Consumo::getFechaAcceso()
{
    return _fechaAcceso;
}
Hora Consumo::getHoraAcceso()
{
    return _horaAcceso;
}
int Consumo::getDuracionVista()
{
    return _duracionVista;
}
bool Consumo::getEliminado()
{
    return _eliminado;
}

void Consumo::setIdAcceso(int id)
{
    _idAcceso = id;
}
void Consumo::setIdSuscriptor(int id)
{
    _idSuscriptor = id;
}
void Consumo::setIdContenido(int id)
{
    _idContenido = id;
}
void Consumo::setFechaAcceso(Fecha f)
{
    _fechaAcceso = f;
}
void Consumo::setHoraAcceso(Hora ha)
{
    _horaAcceso = ha;
}
void Consumo::setDuracionVista(int dv)
{
    _duracionVista = dv;
}
void Consumo::setEliminado(bool e)
{
    _eliminado = e;
}
