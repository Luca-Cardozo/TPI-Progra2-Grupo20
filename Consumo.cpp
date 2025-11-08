#include "Consumo.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

Consumo::Consumo()
{
    _idAcceso = 0;
    _idSuscriptor = 0;
    _idContenido = 0;
    _idTipoContenido = 0;
    _duracionVista = 0;
    _eliminado = false;
}

void Consumo::cargar()
{
    int idS, idC, idTC, dv;
    Fecha f;
    Hora ha;
    cout << endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "ID Suscriptor: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> idS;
    setIdSuscriptor(idS);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "ID Contenido: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> idC;
    setIdContenido(idC);
    do
    {
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << "ID Tipo Contenido (1- PELICULA, 2- SERIE): " << endl;
        rlutil::setColor(rlutil::WHITE);
        cin >> idTC;
    }
    while(idTC != 1 && idTC != 2);
    setIdTipoContenido(idTC);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Fecha de acceso:" << endl;
    rlutil::setColor(rlutil::WHITE);
    f.cargar();
    setFechaAcceso(f);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Hora de acceso:" << endl;
    rlutil::setColor(rlutil::WHITE);
    ha.cargar();
    setHoraAcceso(ha);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Duracion vista (en minutos): ";
    rlutil::setColor(rlutil::WHITE);
    cin >> dv;
    dv = validarPositivo(dv);
    setDuracionVista(dv);
    _eliminado = false;
}

void Consumo::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl;
    cout << "ID Acceso: " << _idAcceso << endl;
    cout << "ID Suscriptor: " << _idSuscriptor << endl;
    cout << "ID Contenido: " << _idContenido << endl;
    cout << "Fecha Acceso: ";
    _fechaAcceso.mostrar();
    cout << "Hora Acceso: ";
    _horaAcceso.mostrar();
    cout << "Duracion Vista: " << _duracionVista << " minutos" << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
    rlutil::setColor(rlutil::WHITE);
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
int Consumo::getIdTipoContenido()
{
    return _idTipoContenido;
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
void Consumo::setIdTipoContenido(int id)
{
    _idTipoContenido = id;
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
