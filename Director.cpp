#include "Director.h"
#include "utils.h"
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
    Persona::cargar();
    cout << "Pais de residencia: " << endl;
    string texto = cargarCadena();
    strncpy(_paisResidencia, texto.c_str(), sizeof(_paisResidencia) - 1);
    _paisResidencia[sizeof(_paisResidencia) - 1] = '\0';
}

void Director::mostrar()
{
    cout << "ID Director: " << _id << endl;
    Persona::mostrar();
    cout << "Pais de residencia: " << _paisResidencia << endl;
    cout << "Eliminado: " << (_eliminado ? "SI" : "NO") << endl;
}

const char* Director::getPaisResidencia()
{
    return _paisResidencia;
}

void Director::setPaisResidencia(const char* pais)
{
    strcpy(_paisResidencia, pais);
}
