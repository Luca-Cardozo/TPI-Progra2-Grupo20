#pragma once
#include "Fecha.h"

class Persona
{
protected:
    int _id;
    char _nombre[20];
    char _apellido[20];
    char _nacionalidad[20];
    Fecha _fechaNacimiento;
    bool _eliminado;
public:
    Persona();

    void cargar();
    void mostrar();

    int getId();
    const char* getNombre();
    const char* getApellido();
    const char* getNacionalidad();
    Fecha getFechaNacimiento();
    bool getEliminado();

    void setId(int id);
    void setNombre(const char* n);
    void setApellido(const char* a);
    void setNacionalidad(const char* nac);
    void setFechaNacimiento(Fecha f);
    void setEliminado(bool e);
};
