#include "Genero.h"
#include "utils.h"
#include "rlutil.h"
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
    cout << endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Descripcion del genero: ";
    rlutil::setColor(rlutil::WHITE);
    string texto = cargarCadena();
    strncpy(_descripcion, texto.c_str(), sizeof(_descripcion) - 1);
    _descripcion[sizeof(_descripcion) - 1] = '\0';
    _eliminado = false;
}

void Genero::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl;
    cout << "ID Genero: " << _idGenero << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
    rlutil::setColor(rlutil::WHITE);
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
