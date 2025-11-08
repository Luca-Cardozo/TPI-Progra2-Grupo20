#include "Clasificacion.h"
#include "utils.h"
#include "rlutil.h"
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
    cout << endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Descripcion de la clasificacion: ";
    rlutil::setColor(rlutil::WHITE);
    string texto = cargarCadena();
    strncpy(_descripcion, texto.c_str(), sizeof(_descripcion) - 1);
    _descripcion[sizeof(_descripcion) - 1] = '\0';
    _eliminado = false;
}

void Clasificacion::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl;
    cout << "ID Clasificacion: " << _idClasificacion << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
    rlutil::setColor(rlutil::WHITE);
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
