#include "Suscriptor.h"
#include <iostream>
#include <cstring>

using namespace std;

Suscriptor::Suscriptor()
{
    _idSuscriptor = 0;
    strcpy(_email, "");
    strcpy(_telefono, "");
    _tipoSuscripcion = 0;
}

void Suscriptor::cargar()
{
    Persona::cargar();
    int ts;
    char e[40], t[20];
    Fecha f;
    cout << "Email: " << endl;
    cin >> e;
    setEmail(e);
    cout << "Telefono: " << endl;
    cin >> t;
    setTelefono(t);
    cout << "Fecha de alta: " << endl;
    f.cargar();
    setFechaAlta(f);
    cout << "ID de tipo de suscripcion: " << endl;
    cin >> ts;
    setTipoSuscripcion(ts);
}

void Suscriptor::mostrar()
{
    cout << "ID Suscriptor: " << _idSuscriptor << endl;
    Persona::mostrar();
    cout << "Email: " << _email << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Fecha alta: ";
    _fechaAlta.mostrar();
    cout << "Tipo suscripcion: " << _tipoSuscripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

int Suscriptor::getIdSuscriptor()
{
    return _idSuscriptor;
}
const char* Suscriptor::getEmail()
{
    return _email;
}
const char* Suscriptor::getTelefono()
{
    return _telefono;
}
Fecha Suscriptor::getFechaAlta()
{
    return _fechaAlta;
}
int Suscriptor::getTipoSuscripcion()
{
    return _tipoSuscripcion;
}

void Suscriptor::setIdSuscriptor(int id)
{
    _idSuscriptor = id;
}
void Suscriptor::setEmail(const char* e)
{
    strcpy(_email, e);
}
void Suscriptor::setTelefono(const char* t)
{
    strcpy(_telefono, t);
}
void Suscriptor::setFechaAlta(Fecha f)
{
    _fechaAlta = f;
}
void Suscriptor::setTipoSuscripcion(int ts)
{
    _tipoSuscripcion = ts;
}
