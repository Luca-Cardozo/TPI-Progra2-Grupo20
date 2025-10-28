#include "TipoSuscripcion.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

TipoSuscripcion::TipoSuscripcion()
{
    _idTipoSuscripcion = 0;
    strcpy(_descripcion, "");
    _eliminado = false;
}

void TipoSuscripcion::cargar()
{
    cout << "Descripcion del del tipo de suscripcion: ";
    string texto = cargarCadena();
    strncpy(_descripcion, texto.c_str(), sizeof(_descripcion) - 1);
    _descripcion[sizeof(_descripcion) - 1] = '\0';
    _eliminado = false;
}

void TipoSuscripcion::mostrar()
{
    cout << "ID tipo de suscripcion: " << _idTipoSuscripcion << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

int TipoSuscripcion::getIdTipoSuscripcion()
{
    return _idTipoSuscripcion;
}
const char* TipoSuscripcion::getDescripcion()
{
    return _descripcion;
}
bool TipoSuscripcion::getEliminado()
{
    return _eliminado;
}

void TipoSuscripcion::setIdTipoSuscripcion(int id)
{
    _idTipoSuscripcion = id;
}
void TipoSuscripcion::setDescripcion(const char* d)
{
    strcpy(_descripcion, d);
}
void TipoSuscripcion::setEliminado(bool e)
{
    _eliminado = e;
}
