#include "TipoSuscripcion.h"
#include "utils.h"
#include "rlutil.h"
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
    cout << endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Descripcion del del tipo de suscripcion: ";
    rlutil::setColor(rlutil::WHITE);
    string texto = cargarCadena();
    strncpy(_descripcion, texto.c_str(), sizeof(_descripcion) - 1);
    _descripcion[sizeof(_descripcion) - 1] = '\0';
    _eliminado = false;
}

void TipoSuscripcion::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl;
    cout << "ID tipo de suscripcion: " << _idTipoSuscripcion << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
    rlutil::setColor(rlutil::WHITE);
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
