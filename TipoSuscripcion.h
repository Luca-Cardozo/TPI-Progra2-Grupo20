#pragma once

class TipoSuscripcion
{
private:
    int _idTipoSuscripcion;
    char _descripcion[20];
    bool _eliminado;
public:
    TipoSuscripcion();

    void cargar();
    void mostrar();

    int getIdTipoSuscripcion();
    const char* getDescripcion();
    bool getEliminado();

    void setIdTipoSuscripcion(int id);
    void setDescripcion(const char* d);
    void setEliminado(bool e);
};
