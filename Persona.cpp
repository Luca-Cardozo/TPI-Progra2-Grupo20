#include "Persona.h"
#include "utils.h"
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
    string texto;
    Fecha f;
    cout << "Nombre: " << endl;
    texto = cargarCadena();
    strncpy(_nombre, texto.c_str(), sizeof(_nombre) - 1);
    _nombre[sizeof(_nombre) - 1] = '\0';
    cout << "Apellido: " << endl;
    texto = cargarCadena();
    strncpy(_apellido, texto.c_str(), sizeof(_apellido) - 1);
    _apellido[sizeof(_apellido) - 1] = '\0';
    cout << "Nacionalidad: " << endl;
    texto = cargarCadena();
    strncpy(_nacionalidad, texto.c_str(), sizeof(_nacionalidad) - 1);
    _nacionalidad[sizeof(_nacionalidad) - 1] = '\0';
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

int Persona::getId()
{
    return _id;
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

void Persona::setId(int id)
{
    _id = id;
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
