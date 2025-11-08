#pragma once
#include "SuscriptorArchivo.h"
#include "TipoSuscripcionArchivo.h"
#include "ListadosManager.h"

class SuscriptorManager
{
private:
    SuscriptorArchivo _repoSuscriptor;
    TipoSuscripcionArchivo _repoTipoSuscripcion;
    ListadosManager _listados;

    int validarTipoSuscripcion(int id);
    std::string validarEmail(Suscriptor* pSuscriptores, int cant, const char* e, int idActual = -1);
    std::string validarTelefono(Suscriptor* pSuscriptores, int cant, const char* t, int idActual = -1);
public:
    bool cargarSuscriptor();
    bool modificarSuscriptor();
    bool eliminarSuscriptor();
    bool altaSuscriptor();
};

