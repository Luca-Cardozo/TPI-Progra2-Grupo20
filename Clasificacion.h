#pragma once

class Clasificacion
{
private:
    int _idClasificacion;
    char _descripcion[20];
    bool _eliminado;
public:
    Clasificacion();

    void cargar();
    void mostrar();

    int getIdClasificacion();
    const char* getDescripcion();
    bool getEliminado();

    void setIdClasificacion(int id);
    void setDescripcion(const char* d);
    void setEliminado(bool e);
};
