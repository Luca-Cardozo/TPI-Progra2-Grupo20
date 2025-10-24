#include "Consumo.h"
#include <iostream>

using namespace std;

Consumo::Consumo()
{
    _idAcceso = 0;
    _idSuscriptor = 0;
    _idContenido = 0;
    _tipoContenido = 0;
    _horaAcceso = 0;
    _duracionVista = 0;
    _eliminado = false;
}

void Consumo::cargar()
{
    int idS, idC, tc, ha, dv;
    Fecha f;
    cout << "ID Suscriptor: ";
    cin >> idS;
    setIdSuscriptor(idS);
    cout << "ID Contenido: ";
    cin >> idC;
    setIdContenido(idC);
    cout << "Tipo de contenido (1 = Pelicula, 2 = Serie): ";
    cin >> tc;
    setTipoContenido(tc);
    cout << "Fecha de acceso:" << endl;
    f.cargar();
    setFechaAcceso(f);
    do
    {
        cout << "Hora de acceso (0-23): ";
        cin >> ha;
        if(ha < 0 || ha > 23)
        {
            cout << "Ingrese una hora valida por favor..." << endl;
        }
    }
    while(ha < 0 || ha > 23);
    setHoraAcceso(ha);
    cout << "Duracion vista (en minutos): ";
    cin >> dv;
    setDuracionVista(dv);
    _eliminado = false;
}

void Consumo::mostrar()
{
    cout << "ID Acceso: " << _idAcceso << endl;
    cout << "ID Suscriptor: " << _idSuscriptor << endl;
    cout << "ID Contenido: " << _idContenido << endl;
    cout << "Tipo Contenido: " << _tipoContenido << endl;
    cout << "Fecha Acceso: ";
    _fechaAcceso.mostrar();
    cout << "Hora Acceso: " << _horaAcceso << " hs" << endl;
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
int Consumo::getTipoContenido()
{
    return _tipoContenido;
}
Fecha Consumo::getFechaAcceso()
{
    return _fechaAcceso;
}
int Consumo::getHoraAcceso()
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
void Consumo::setTipoContenido(int tc)
{
    _tipoContenido = tc;
}
void Consumo::setFechaAcceso(Fecha f)
{
    _fechaAcceso = f;
}
void Consumo::setHoraAcceso(int ha)
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
