#include "Suscriptor.h"
#include <iostream>
#include <cstring>

using namespace std;

Suscriptor::Suscriptor()
{
    _id = 0;
    strcpy(_email, "");
    strcpy(_telefono, "");
    _tipoSuscripcion = 0;
}

void Suscriptor::cargar()
{
    Persona::cargar();
    int ts;
    char e[40], t[20];
    Fecha fn = this->getFechaNacimiento();
    Fecha fa;
    cout << "Email: " << endl;
    cin >> e;
    setEmail(e);
    cout << "Telefono: " << endl;
    cin >> t;
    setTelefono(t);
    cout << "Fecha de alta: " << endl;
    fa.cargar();
    validarFechas(fn, fa);
    setFechaNacimiento(fn);
    setFechaAlta(fa);
    cout << "ID de tipo de suscripcion: " << endl;
    cin >> ts;
    setTipoSuscripcion(ts);
}

void Suscriptor::mostrar()
{
    cout << "ID Suscriptor: " << _id << endl;
    Persona::mostrar();
    cout << "Email: " << _email << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Fecha alta: ";
    _fechaAlta.mostrar();
    cout << "Tipo suscripcion: " << _tipoSuscripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
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

void Suscriptor::validarFechas(Fecha &fechaNacimiento, Fecha &fechaAlta)
{
    while(fechaAlta <= fechaNacimiento)
    {
        cout << endl;
        cout << "La fecha de alta no puede ser anterior o igual a la fecha de nacimiento... Intente cargar la informacion nuevamente..." << endl;
        cout << "Ingrese nuevamente la fecha de nacimiento:" << endl;
        fechaNacimiento.cargar();
        cout << "Ingrese nuevamente la fecha de alta:" << endl;
        fechaAlta.cargar();
    }
}
