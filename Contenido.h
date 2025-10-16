#pragma once
#include "Fecha.h"

class Contenido
{
protected:
    int _idTipoContenido;
    char _titulo[50];
    int _idDirector;
    int _genero;
    int _clasificacion;
    Fecha _fechaEstreno;
    Fecha _fechaAlta;
    bool _eliminado;
public:
    Contenido();

    void cargar();
    void mostrar();

    int getIdTipoContenido();
    const char* getTitulo();
    int getIdDirector();
    int getGenero();
    int getClasificacion();
    Fecha getFechaEstreno();
    Fecha getFechaAlta();
    bool getEliminado();

    void setIdTipoContenido(int id);
    void setTitulo(const char* t);
    void setIdDirector(int id);
    void setGenero(int g);
    void setClasificacion(int c);
    void setFechaEstreno(Fecha f);
    void setFechaAlta(Fecha f);
    void setEliminado(bool e);
};


