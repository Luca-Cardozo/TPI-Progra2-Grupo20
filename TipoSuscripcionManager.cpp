#include "TipoSuscripcionManager.h"
#include "TipoSuscripcion.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

bool TipoSuscripcionManager::cargarTipoSuscripcion()
{
    cout << "-------- CARGA DE NUEVO TIPO DE SUSCRIPCION --------" << endl;
    int carga;
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
    int id = _repoTipoSuscripcion.getNuevoID();
    TipoSuscripcion reg;
    TipoSuscripcion *pTiposSuscripciones;
    cout << "ID: #" << id << endl;
    reg.cargar();
    int cantRegistros = _repoTipoSuscripcion.getCantidadRegistros();
    pTiposSuscripciones = new TipoSuscripcion[cantRegistros];
    if(pTiposSuscripciones == nullptr)
    {
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        system("pause");
        system("cls");
        return false;
    }
    _repoTipoSuscripcion.leer(pTiposSuscripciones, cantRegistros);
    reg.setDescripcion(validarDescripcion(pTiposSuscripciones, cantRegistros, reg.getDescripcion()).c_str());
    delete [] pTiposSuscripciones;
    reg.setIdTipoSuscripcion(id);
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
    return _repoTipoSuscripcion.guardar(reg);
}

bool TipoSuscripcionManager::modificarTipoSuscripcion()
{
    cout << "-------- ACTUALIZACION DE TIPO DE SUSCRIPCION --------" << endl;
    int id;
    TipoSuscripcion reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a actualizar (0 para anular la actualizacion): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Modificacion anulada..." << endl;
            return false;
        }
        reg = _repoTipoSuscripcion.leer(id - 1);
        if(reg.getIdTipoSuscripcion() == -1)
        {
            cout << "No existe un tipo de suscripcion registrado con ese ID... Vuelva a intentarlo..." << endl;
            system("pause");
            system("cls");
            continue;
        }
        cout << "----- DATOS DEL REGISTRO A MODIFICAR -----" << endl;
        reg.mostrar();
        cout << "Este es el registro a modificar? (S/N)" << endl;
        cin >> respuesta;
        while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
        {
            cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
            cout << "Este es el registro a modificar? (S/N)" << endl;
            cin >> respuesta;
        }
        if(respuesta == 'N' || respuesta == 'n') continue;
    }
    while(respuesta != 's' && respuesta != 'S');
    system("cls");
    cout << "----- CARGUE LOS NUEVOS DATOS DEL REGISTRO -----" << endl;
    TipoSuscripcion *pTiposSuscripciones;
    cout << "ID: #" << id << endl;
    reg.cargar();
    int cantRegistros = _repoTipoSuscripcion.getCantidadRegistros();
    pTiposSuscripciones = new TipoSuscripcion[cantRegistros];
    if(pTiposSuscripciones == nullptr)
    {
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        system("pause");
        system("cls");
        return false;
    }
    _repoTipoSuscripcion.leer(pTiposSuscripciones, cantRegistros);
    reg.setDescripcion(validarDescripcion(pTiposSuscripciones, cantRegistros, reg.getDescripcion()).c_str());
    delete [] pTiposSuscripciones;
    return _repoTipoSuscripcion.guardar(id-1, reg);
}

bool TipoSuscripcionManager::eliminarTipoSuscripcion()
{
    cout << "-------- BAJA DE TIPO DE SUSCRIPCION --------" << endl;
    int id;
    TipoSuscripcion reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Baja cancelada..." << endl;
            return false;
        }
        reg = _repoTipoSuscripcion.leer(id - 1);
        while(reg.getIdTipoSuscripcion() == -1)
        {
            cout << "No existe un tipo de suscripcion registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Baja cancelada..." << endl;
                return false;
            }
            reg = _repoTipoSuscripcion.leer(id - 1);
        }
        system("cls");
        cout << "----- DATOS DEL REGISTRO A DAR DE BAJA -----" << endl;
        reg.mostrar();
        cout << "Este es el registro a eliminar? (S/N)" << endl;
        cin >> respuesta;
        while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
        {
            cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
            cout << "Este es el registro a eliminar? (S/N)" << endl;
            cin >> respuesta;
        }
        if(respuesta == 'N' || respuesta == 'n') continue;
    }
    while(respuesta != 's' && respuesta != 'S');
    return _repoTipoSuscripcion.eliminar(id - 1);
}

bool TipoSuscripcionManager::altaTipoSuscripcion()
{
    cout << "-------- ALTA DE TIPO DE SUSCRIPCION --------" << endl;
    int id;
    TipoSuscripcion reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a dar de alta (0 para cancelar el alta): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Alta cancelada..." << endl;
            return false;
        }
        reg = _repoTipoSuscripcion.leer(id - 1);
        while(reg.getIdTipoSuscripcion() == -1)
        {
            cout << "No existe tipo de suscripcion registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a dar de alta (0 para cancelar el alta): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Alta cancelada..." << endl;
                return false;
            }
            reg = _repoTipoSuscripcion.leer(id - 1);
        }
        cout << "----- DATOS DEL REGISTRO A DAR DE ALTA -----" << endl;
        reg.mostrar();
        if(!reg.getEliminado())
        {
            cout << "El registro ya se encuentra dado de alta..." << endl;
            return false;
        }
        cout << "Este es el registro a dar de alta? (S/N)" << endl;
        cin >> respuesta;
        while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
        {
            cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
            cout << "Este es el registro a dar de alta? (S/N)" << endl;
            cin >> respuesta;
        }
        if(respuesta == 'N' || respuesta == 'n') continue;
    }
    while(respuesta != 's' && respuesta != 'S');
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
            if(strcmp(desc.c_str(), pTiposSuscripcion[i].getDescripcion()) == 0)
            {
                cout << "La descripcion ingresada ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << "Ingrese otra descripcion: " << endl;
                desc = cargarCadena();
                descValida = false;
                break;
            }
        }
    }
    while(!descValida);
    return desc;
}
