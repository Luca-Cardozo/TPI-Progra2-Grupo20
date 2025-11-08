#include "TipoContenido.h"
#include "utils.h"
#include "rlutil.h"
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
    cout << endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Descripcion del tipo de contenido: ";
    rlutil::setColor(rlutil::WHITE);
    string texto = cargarCadena();
    strncpy(_descripcion, texto.c_str(), sizeof(_descripcion) - 1);
    _descripcion[sizeof(_descripcion) - 1] = '\0';
    _eliminado = false;
}

void TipoContenido::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl;
    cout << "ID Tipo de contenido: " << _idTipoContenido << endl;
    cout << "Descripcion: " << _descripcion << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
    rlutil::setColor(rlutil::WHITE);
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
