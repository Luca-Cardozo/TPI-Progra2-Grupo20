#pragma once

class TipoContenido
{
private:
    int _idTipoContenido;
    char _descripcion[20];
    bool _eliminado;
public:
    TipoContenido();

    void cargar();
    void mostrar();

    int getIdTipoContenido();
    const char* getDescripcion();
    bool getEliminado();

    void setIdTipoContenido(int id);
    void setDescripcion(const char* d);
    void setEliminado(bool e);
};
