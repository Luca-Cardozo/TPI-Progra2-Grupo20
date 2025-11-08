#include "Director.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>

using namespace std;

Director::Director()
{
    _id = 0;
    strcpy(_paisResidencia, "");
}

void Director::cargar()
{
    cout << endl;
    Persona::cargar();
    rlutil::setColor(rlutil::LIGHTBLUE);
    cout << "Pais de residencia: " << endl;
    rlutil::setColor(rlutil::WHITE);
    string texto = cargarCadena();
    strncpy(_paisResidencia, texto.c_str(), sizeof(_paisResidencia) - 1);
    _paisResidencia[sizeof(_paisResidencia) - 1] = '\0';
}

void Director::mostrar()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << endl;
    cout << "ID Director: " << _id << endl;
    Persona::mostrar();
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Pais de residencia: " << _paisResidencia << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
    rlutil::setColor(rlutil::WHITE);
}

const char* Director::getPaisResidencia()
{
    return _paisResidencia;
}

void Director::setPaisResidencia(const char* pais)
{
    strcpy(_paisResidencia, pais);
}
