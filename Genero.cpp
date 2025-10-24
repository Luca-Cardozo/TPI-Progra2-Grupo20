#include "Genero.h"
#include <iostream>
#include <cstring>

using namespace std;

Genero::Genero()
{
    _idGenero = 0;
    strcpy(_descripcion, "");
    _eliminado = false;
}

void Genero::cargar()
{
    char d[20];
    cout << "Descripcion del genero: ";
    cin >> d;
    setDescripcion(d);
    _eliminado = false;
}

void Genero::mostrar()
{
    cout << "ID Genero: " << _idGenero << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

int Genero::getIdGenero()
{
    return _idGenero;
}
const char* Genero::getDescripcion()
{
    return _descripcion;
}
bool Genero::getEliminado()
{
    return _eliminado;
}

void Genero::setIdGenero(int id)
{
    _idGenero = id;
}
void Genero::setDescripcion(const char* d)
{
    strcpy(_descripcion, d);
}
void Genero::setEliminado(bool e)
{
    _eliminado = e;
}
