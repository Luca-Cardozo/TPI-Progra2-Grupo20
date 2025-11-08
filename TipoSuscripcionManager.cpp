#include "TipoSuscripcionManager.h"
#include "TipoSuscripcion.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>

using namespace std;

bool TipoSuscripcionManager::cargarTipoSuscripcion()
{
    int id, cantRegistros;
    TipoSuscripcion reg;
    TipoSuscripcion *pTiposSuscripciones;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- CARGA DE NUEVO TIPO DE SUSCRIPCION --------" << endl;

    cout << endl;
    if (deseaCancelar()) return false;

    id = _repoTipoSuscripcion.getNuevoID();
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "ID: #" << id << endl;

    reg.cargar();

    cantRegistros = _repoTipoSuscripcion.getCantidadRegistros();
    pTiposSuscripciones = new TipoSuscripcion[cantRegistros];
    if(pTiposSuscripciones == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoTipoSuscripcion.leer(pTiposSuscripciones, cantRegistros);

    reg.setIdTipoSuscripcion(id);
    reg.setDescripcion(validarDescripcion(pTiposSuscripciones, cantRegistros, reg.getDescripcion()).c_str());

    delete [] pTiposSuscripciones;
    return _repoTipoSuscripcion.guardar(reg);
}

bool TipoSuscripcionManager::modificarTipoSuscripcion()
{
    int id, cantRegistros;
    TipoSuscripcion reg;
    TipoSuscripcion *pTiposSuscripciones;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ACTUALIZACION DE TIPO DE SUSCRIPCION --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoTipoSuscripcion.leer(id - 1);
        while(reg.getIdTipoSuscripcion() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un tipo de suscripcion registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarTiposSuscripcion();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoTipoSuscripcion.leer(id - 1);
        }
        system("cls");
        rlutil::setColor(rlutil::YELLOW);
        cout << "----- DATOS DEL REGISTRO A MODIFICAR -----" << endl;
        reg.mostrar();
        cout << endl;
        if (confirmarAccion("Este es el registro a modificar?")) break;
    }

    system("cls");
    rlutil::setColor(rlutil::LIGHTRED);
    cout << "----- CARGUE LOS NUEVOS DATOS DEL REGISTRO -----" << endl;

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << endl;
    cout << "ID: #" << id << endl;
    reg.cargar();

    cantRegistros = _repoTipoSuscripcion.getCantidadRegistros();
    pTiposSuscripciones = new TipoSuscripcion[cantRegistros];
    if(pTiposSuscripciones == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoTipoSuscripcion.leer(pTiposSuscripciones, cantRegistros);

    reg.setDescripcion(validarDescripcion(pTiposSuscripciones, cantRegistros, reg.getDescripcion()).c_str());

    delete [] pTiposSuscripciones;
    return _repoTipoSuscripcion.guardar(id-1, reg);
}

bool TipoSuscripcionManager::eliminarTipoSuscripcion()
{
    int id;
    TipoSuscripcion reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- BAJA DE TIPO DE SUSCRIPCION --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoTipoSuscripcion.leer(id - 1);
        while(reg.getIdTipoSuscripcion() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un tipo de suscripcion registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarTiposSuscripcion();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoTipoSuscripcion.leer(id - 1);
        }
        system("cls");
        rlutil::setColor(rlutil::YELLOW);
        cout << "----- DATOS DEL REGISTRO A DAR DE BAJA -----" << endl;
        reg.mostrar();
        if(reg.getEliminado())
        {
            cout << endl;
            rlutil::setColor(rlutil::RED);
            cout << "El registro ya se encuentra dado de baja..." << endl;
            rlutil::setColor(rlutil::WHITE);
            return false;
        }
        cout << endl;
        if (confirmarAccion("Este es el registro a eliminar?")) break;
    }

    return _repoTipoSuscripcion.eliminar(id - 1);
}

bool TipoSuscripcionManager::altaTipoSuscripcion()
{
    int id;
    TipoSuscripcion reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ALTA DE TIPO DE SUSCRIPCION --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoTipoSuscripcion.leer(id - 1);
        while(reg.getIdTipoSuscripcion() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe tipo de suscripcion registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarTiposSuscripcion();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoTipoSuscripcion.leer(id - 1);
        }
        system("cls");
        rlutil::setColor(rlutil::YELLOW);
        cout << "----- DATOS DEL REGISTRO A DAR DE ALTA -----" << endl;
        reg.mostrar();
        if(!reg.getEliminado())
        {
            cout << endl;
            rlutil::setColor(rlutil::RED);
            cout << "El registro ya se encuentra dado de alta..." << endl;
            rlutil::setColor(rlutil::WHITE);
            return false;
        }
        cout << endl;
        if (confirmarAccion("Este es el registro a dar de alta?")) break;
    }

    return _repoTipoSuscripcion.alta(id - 1);
}

string TipoSuscripcionManager::validarDescripcion(TipoSuscripcion* pTiposSuscripcion,  int cant, const char* d)
{
    string desc = d;
    bool descValida;
    do
    {
        descValida = true;
        for(int i = 0; i < cant; i++)
        {
            if(strcasecmp(desc.c_str(), pTiposSuscripcion[i].getDescripcion()) == 0)
            {
                cout << endl;
                rlutil::setColor(rlutil::RED);
                cout << "La descripcion ingresada ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << endl;
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otra descripcion: " << endl;
                rlutil::setColor(rlutil::WHITE);
                desc = cargarCadena();
                descValida = false;
                break;
            }
        }
    }
    while(!descValida);
    return desc;
}
