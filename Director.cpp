#include "Director.h"
#include <iostream>
#include <cstring>

using namespace std;

Director::Director()
{
    _idDirector = 0;
    _eliminado = false;
}

void Director::cargar()
{
    Persona::cargar();
    int id;
    cout << "ID Suscriptor: " << endl;
    cin >> id;
    setIdDirector(id);
    _eliminado = false;
}

void Director::mostrar()
{
    cout << "ID Director: " << _idDirector << endl;
    Persona::mostrar();
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

int Director::getIdDirector()
{
    return _idDirector;
}
bool Director::getEliminado()
{
    return _eliminado;
}

void Director::setIdDirector(int id)
{
    _idDirector = id;
}
void Director::setEliminado(bool e)
{
    _eliminado = e;
}
