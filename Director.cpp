#include "Director.h"
#include <iostream>
#include <cstring>

using namespace std;

Director::Director()
{
    _idDirector = 0;
}

void Director::cargar()
{
    Persona::cargar();
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

void Director::setIdDirector(int id)
{
    _idDirector = id;
}
