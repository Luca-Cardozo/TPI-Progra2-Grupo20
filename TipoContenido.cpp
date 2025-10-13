#include "TipoContenido.h"
#include <iostream>
#include <cstring>

using namespace std;

TipoContenido::TipoContenido()
{
    _idTipoContenido = 0;
    strcpy(_descripcion, "");
    _eliminado = false;
}

void TipoContenido::cargar()
{
    int id;
    char d[20];
    cout << "ID del genero: ";
    cin >> id;
    setIdTipoContenido(id);
    cout << "Descripcion del genero: ";
    cin >> d;
    setDescripcion(d);
    _eliminado = false;
}

void TipoContenido::mostrar()
{
    cout << "ID Clasificacion: " << _idTipoContenido << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

int TipoContenido::getIdTipoContenido()
{
    return _idTipoContenido;
}
const char* TipoContenido::getDescripcion()
{
    return _descripcion;
}
bool TipoContenido::getEliminado()
{
    return _eliminado;
}

void TipoContenido::setIdTipoContenido(int id)
{
    _idTipoContenido = id;
}
void TipoContenido::setDescripcion(const char* d)
{
    strcpy(_descripcion, d);
}
void TipoContenido::setEliminado(bool e)
{
    _eliminado = e;
}
