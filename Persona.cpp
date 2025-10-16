#include "Persona.h"
#include <iostream>
#include <cstring>

using namespace std;

Persona::Persona()
{
    strcpy(_nombre, "");
    strcpy(_apellido, "");
    strcpy(_nacionalidad, "");
    _eliminado = false;
}

void Persona::cargar()
{
    char n[20], a[20], nac[20];
    Fecha f;
    cout << "Nombre: " << endl;
    cin >> n;
    setNombre(n);
    cout << "Apellido: " << endl;
    cin >> a;
    setApellido(a);
    cin.ignore();
    cout << "Nacionalidad: " << endl;
    cin.getline(nac, 20);
    setNacionalidad(nac);
    cout << "Fecha de nacimiento: " << endl;
    f.cargar();
    setFechaNacimiento(f);
}

void Persona::mostrar()
{
    cout << "Nombre: " << _nombre << endl;
    cout << "Apellido: " << _apellido << endl;
    cout << "Nacionalidad: " << _nacionalidad << endl;
    cout << "Fecha nacimiento: ";
    _fechaNacimiento.mostrar();
}

const char* Persona::getNombre()
{
    return _nombre;
}
const char* Persona::getApellido()
{
    return _apellido;
}
const char* Persona::getNacionalidad()
{
    return _nacionalidad;
}
Fecha Persona::getFechaNacimiento()
{
    return _fechaNacimiento;
}
bool Persona::getEliminado()
{
    return _eliminado;
}

void Persona::setNombre(const char* n)
{
    strcpy(_nombre, n);
}
void Persona::setApellido(const char* a)
{
    strcpy(_apellido, a);
}
void Persona::setNacionalidad(const char* nac)
{
    strcpy(_nacionalidad, nac);
}
void Persona::setFechaNacimiento(Fecha f)
{
    _fechaNacimiento = f;
}
void Persona::setEliminado(bool e)
{
    _eliminado = e;
}
