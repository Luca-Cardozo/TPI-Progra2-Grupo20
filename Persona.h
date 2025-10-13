#pragma once
#include "Fecha.h"

class Persona
{
protected:
    char _nombre[20];
    char _apellido[20];
    char _nacionalidad[20];
    Fecha _fechaNacimiento;
public:
    Persona();

    void cargar();
    void mostrar();

    const char* getNombre();
    const char* getApellido();
    const char* getNacionalidad();
    Fecha getFechaNacimiento();

    void setNombre(const char* n);
    void setApellido(const char* a);
    void setNacionalidad(const char* nac);
    void setFechaNacimiento(Fecha f);
};
