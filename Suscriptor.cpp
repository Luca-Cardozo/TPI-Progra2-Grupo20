#include "Suscriptor.h"
#include <iostream>
#include <cstring>
#include "rlutil.h"

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
    cout << endl;
    Persona::cargar();
    int ts;
    char e[40], t[20];
    Fecha fn = this->getFechaNacimiento();
    Fecha fa;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Email: " << endl;
    rlutil::setColor(rlutil::WHITE);
    cin >> e;
    setEmail(e);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Telefono: " << endl;
    rlutil::setColor(rlutil::WHITE);
    cin >> t;
    setTelefono(t);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Fecha de alta: " << endl;
    rlutil::setColor(rlutil::WHITE);
    fa.cargar();
    validarFechas(fn, fa);
    setFechaNacimiento(fn);
    setFechaAlta(fa);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "ID de tipo de suscripcion: " << endl;
    rlutil::setColor(rlutil::WHITE);
    cin >> ts;
    setTipoSuscripcion(ts);
}

void Suscriptor::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl;
    cout << "ID Suscriptor: " << _id << endl;
    Persona::mostrar();
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Email: " << _email << endl;
    cout << "Telefono: " << _telefono << endl;
    cout << "Fecha alta: ";
    _fechaAlta.mostrar();
    cout << "Tipo suscripcion: " << _tipoSuscripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
    cout << endl;
    rlutil::setColor(rlutil::WHITE);
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
        rlutil::setColor(rlutil::RED);
        cout << "La fecha de alta no puede ser anterior o igual a la fecha de nacimiento... Intente cargar la informacion nuevamente..." << endl;
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << "Ingrese nuevamente la fecha de nacimiento:" << endl;
        rlutil::setColor(rlutil::WHITE);
        fechaNacimiento.cargar();
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << "Ingrese nuevamente la fecha de alta:" << endl;
        rlutil::setColor(rlutil::WHITE);
        fechaAlta.cargar();
    }
}
