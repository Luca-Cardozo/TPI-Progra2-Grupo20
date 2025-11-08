#include "ClasificacionManager.h"
#include "Clasificacion.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>

using namespace std;

bool ClasificacionManager::cargarClasificacion()
{
    int id, cantRegistros;
    Clasificacion reg;
    Clasificacion *pClasificaciones;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- CARGA DE NUEVA CLASIFICACION --------" << endl;

    cout << endl;
    if (deseaCancelar()) return false;

    id = _repoClasificacion.getNuevoID();
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "ID: #" << id << endl;

    reg.cargar();

    cantRegistros = _repoClasificacion.getCantidadRegistros();
    pClasificaciones = new Clasificacion[cantRegistros];
    if(pClasificaciones == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoClasificacion.leer(pClasificaciones, cantRegistros);

    reg.setIdClasificacion(id);
    reg.setDescripcion(validarDescripcion(pClasificaciones, cantRegistros, reg.getDescripcion()).c_str());

    delete [] pClasificaciones;
    return _repoClasificacion.guardar(reg);
}

bool ClasificacionManager::modificarClasificacion()
{
    int id, cantRegistros;
    Clasificacion reg;
    Clasificacion *pClasificaciones;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ACTUALIZACION DE CLASIFICACION --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoClasificacion.leer(id - 1);
        while(reg.getIdClasificacion() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe una clasificacion registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarClasificaciones();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoClasificacion.leer(id - 1);
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

    cantRegistros = _repoClasificacion.getCantidadRegistros();
    pClasificaciones = new Clasificacion[cantRegistros];
    if(pClasificaciones == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoClasificacion.leer(pClasificaciones, cantRegistros);

    reg.setDescripcion(validarDescripcion(pClasificaciones, cantRegistros, reg.getDescripcion()).c_str());

    delete [] pClasificaciones;
    return _repoClasificacion.guardar(id-1, reg);
}

bool ClasificacionManager::eliminarClasificacion()
{
    int id;
    Clasificacion reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- BAJA DE CLASIFICACION --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoClasificacion.leer(id - 1);
        while(reg.getIdClasificacion() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe clasificacion registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarClasificaciones();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoClasificacion.leer(id - 1);
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

    return _repoClasificacion.eliminar(id - 1);
}

bool ClasificacionManager::altaClasificacion()
{
    int id;
    Clasificacion reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ALTA DE CLASIFICACION --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoClasificacion.leer(id - 1);
        while(reg.getIdClasificacion() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe clasificacion registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarClasificaciones();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoClasificacion.leer(id - 1);
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

    return _repoClasificacion.alta(id - 1);
}

string ClasificacionManager::validarDescripcion(Clasificacion* pClasificaciones,  int cant, const char* d)
{
    string desc = d;
    bool descValida;
    do
    {
        descValida = true;
        for(int i = 0; i < cant; i++)
        {
            if(strcasecmp(desc.c_str(), pClasificaciones[i].getDescripcion()) == 0)
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
