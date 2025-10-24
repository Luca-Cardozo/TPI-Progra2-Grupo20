#include "Clasificacion.h"
#include <iostream>
#include <cstring>

using namespace std;

Clasificacion::Clasificacion()
{
    _idClasificacion = 0;
    strcpy(_descripcion, "");
    _eliminado = false;
}

void Clasificacion::cargar()
{
    char d[20];
    cout << "Descripcion de la clasificacion: ";
    cin >> d;
    setDescripcion(d);
    _eliminado = false;
}

void Clasificacion::mostrar()
{
    cout << "ID Clasificacion: " << _idClasificacion << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

int Clasificacion::getIdClasificacion()
{
    return _idClasificacion;
}
const char* Clasificacion::getDescripcion()
{
    return _descripcion;
}
bool Clasificacion::getEliminado()
{
    return _eliminado;
}

void Clasificacion::setIdClasificacion(int id)
{
    _idClasificacion = id;
}
void Clasificacion::setDescripcion(const char* d)
{
    strcpy(_descripcion, d);
}
void Clasificacion::setEliminado(bool e)
{
    _eliminado = e;
}
