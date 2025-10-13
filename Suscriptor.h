#pragma once
#include "Persona.h"

class Suscriptor: public Persona
{
private:
    int _idSuscriptor;
    char _email[40];
    char _telefono[20];
    Fecha _fechaAlta;
    int _tipoSuscripcion;
    bool _eliminado;
public:
    Suscriptor();

    void cargar();
    void mostrar();

    int getIdSuscriptor();
    const char* getEmail();
    const char* getTelefono();
    Fecha getFechaAlta();
    int getTipoSuscripcion();
    bool getEliminado();

    void setIdSuscriptor(int id);
    void setEmail(const char* e);
    void setTelefono(const char* t);
    void setFechaAlta(Fecha f);
    void setTipoSuscripcion(int ts);
    void setEliminado(bool e);
};
