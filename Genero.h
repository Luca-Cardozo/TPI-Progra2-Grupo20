#pragma once

class Genero
{
private:
    int _idGenero;
    char _descripcion[20];
    bool _eliminado;
public:
    Genero();

    void cargar();
    void mostrar();

    int getIdGenero();
    const char* getDescripcion();
    bool getEliminado();

    void setIdGenero(int id);
    void setDescripcion(const char* d);
    void setEliminado(bool e);
};
