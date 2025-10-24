#include "TipoSuscripcionManager.h"
#include "TipoSuscripcion.h"
#include <iostream>
#include <cstring>

using namespace std;

bool TipoSuscripcionManager::cargarTipoSuscripcion()
{
    cout << "-------- ALTA DE NUEVO TIPO DE SUSCRIPCION --------" << endl;
    int id = _repoTipoSuscripcion.getNuevoID();
    bool cargaExitosa;
    TipoSuscripcion reg;
    TipoSuscripcion *pTiposSuscripciones;
    do
    {
        cargaExitosa = true;
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
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getDescripcion(),pTiposSuscripciones[i].getDescripcion()) == 0)
            {
                cout << "El tipo de suscripcion ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pTiposSuscripciones;
    reg.setIdTipoSuscripcion(id);
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
        cout << "Ingrese ID del registro a actualizar: " << endl;
        cin >> id;
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
    while(respuesta != 's' || respuesta != 'S');
    system("cls");
    cout << "----- CARGUE LOS NUEVOS DATOS DEL REGISTRO -----" << endl;
    TipoSuscripcion *pTiposSuscripciones;
    bool cargaExitosa;
    do
    {
        cargaExitosa = true;
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
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getDescripcion(),pTiposSuscripciones[i].getDescripcion()) == 0)
            {
                cout << "El tipo de suscripcion ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
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
        cout << "Ingrese ID del registro a eliminar: " << endl;
        cin >> id;
        reg = _repoTipoSuscripcion.leer(id - 1);
        if(reg.getIdTipoSuscripcion() == -1)
        {
            cout << "No existe un tipo de suscripcion registrado con ese ID... Vuelva a intentarlo..." << endl;
            system("pause");
            system("cls");
            continue;
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
    while(respuesta != 's' || respuesta != 'S');
    return _repoTipoSuscripcion.eliminar(id - 1);
}
