#include "Contenido.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>

using namespace std;

Contenido::Contenido()
{
    _id = 0;
    _idTipoContenido = 0;
    strcpy(_titulo, "");
    _idDirector = 0;
    _genero = 0;
    _clasificacion = 0;
    _eliminado = false;
}

void Contenido::cargar()
{
    int g, c, idD;
    Fecha fe, fa;
    cout << endl;
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Titulo: ";
    rlutil::setColor(rlutil::WHITE);
    string texto = cargarCadena();
    strncpy(_titulo, texto.c_str(), sizeof(_titulo) - 1);
    _titulo[sizeof(_titulo) - 1] = '\0';
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "ID del director: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> idD;
    setIdDirector(idD);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "ID del genero: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> g;
    setGenero(g);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "ID de la clasificacion: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> c;
    setClasificacion(c);
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Fecha de estreno: " << endl;
    rlutil::setColor(rlutil::WHITE);
    fe.cargar();
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Fecha de alta en el sistema: " << endl;
    rlutil::setColor(rlutil::WHITE);
    fa.cargar();
    validarFechas(fe, fa);
    setFechaEstreno(fe);
    setFechaAlta(fa);
    _eliminado = false;
}

void Contenido::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "ID del tipo de contenido: " << _idTipoContenido << endl;
    cout << "Titulo: " << _titulo << endl;
    cout << "ID Director: " << _idDirector << endl;
    cout << "ID Genero: " << _genero << endl;
    cout << "ID Clasificacion: " << _clasificacion << endl;
    cout << "Fecha Estreno: ";
    _fechaEstreno.mostrar();
    cout << "Fecha Alta: ";
    _fechaAlta.mostrar();
    rlutil::setColor(rlutil::WHITE);
}

int Contenido::getId()
{
    return _id;
}
int Contenido::getIdTipoContenido()
{
    return _idTipoContenido;
}
const char* Contenido::getTitulo()
{
    return _titulo;
}
int Contenido::getIdDirector()
{
    return _idDirector;
}
int Contenido::getGenero()
{
    return _genero;
}
int Contenido::getClasificacion()
{
    return _clasificacion;
}
Fecha Contenido::getFechaEstreno()
{
    return _fechaEstreno;
}
Fecha Contenido::getFechaAlta()
{
    return _fechaAlta;
}
bool Contenido::getEliminado()
{
    return _eliminado;
}

void Contenido::setId(int id)
{
    _id = id;
}
void Contenido::setIdTipoContenido(int id)
{
    _idTipoContenido = id;
}
void Contenido::setTitulo(const char* t)
{
    strcpy(_titulo, t);
}
void Contenido::setIdDirector(int id)
{
    _idDirector = id;
}
void Contenido::setGenero(int g)
{
    _genero = g;
}
void Contenido::setClasificacion(int c)
{
    _clasificacion = c;
}
void Contenido::setFechaEstreno(Fecha f)
{
    _fechaEstreno = f;
}
void Contenido::setFechaAlta(Fecha f)
{
    _fechaAlta = f;
}
void Contenido::setEliminado(bool e)
{
    _eliminado = e;
}

void Contenido::validarFechas(Fecha &fechaEstreno, Fecha &fechaAlta)
{
    while(fechaAlta < fechaEstreno)
    {
        cout << endl;
        rlutil::setColor(rlutil::RED);
        cout << "La fecha de alta no puede ser anterior a la fecha de estreno... Intente cargar la informacion nuevamente..." << endl;
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << "Ingrese nuevamente la fecha de estreno:" << endl;
        rlutil::setColor(rlutil::WHITE);
        fechaEstreno.cargar();
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << "Ingrese nuevamente la fecha de alta:" << endl;
        rlutil::setColor(rlutil::WHITE);
        fechaAlta.cargar();
    }
}
