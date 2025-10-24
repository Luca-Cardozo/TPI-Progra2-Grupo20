#include "SuscriptorManager.h"
#include "Suscriptor.h"
#include <iostream>
#include <cstring>

using namespace std;

bool SuscriptorManager::cargarSuscriptor()
{
    cout << "-------- ALTA DE NUEVO SUSCRIPTOR --------" << endl;
    int id = _repoSuscriptor.getNuevoID();
    bool cargaExitosa;
    Suscriptor reg;
    Suscriptor *pSuscriptores;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        if(_repoTipoSuscripcion.buscar(reg.getTipoSuscripcion()) == -1)
        {
            cout << "El ID ingresado para el tipo de suscripcion no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        int cantRegistros = _repoSuscriptor.getCantidadRegistros();
        pSuscriptores = new Suscriptor[cantRegistros];
        if(pSuscriptores == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoSuscriptor.leer(pSuscriptores, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getEmail(),pSuscriptores[i].getEmail()) == 0)
            {
                cout << "El email ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
            if(strcmp(reg.getTelefono(),pSuscriptores[i].getTelefono()) == 0)
            {
                cout << "El telefono ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pSuscriptores;
    reg.setIdSuscriptor(id);
    return _repoSuscriptor.guardar(reg);
}

bool SuscriptorManager::modificarSuscriptor()
{
    cout << "-------- ACTUALIZACION DE SUSCRIPTOR --------" << endl;
    int id;
    Suscriptor reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a actualizar: " << endl;
        cin >> id;
        reg = _repoSuscriptor.leer(id - 1);
        if(reg.getIdSuscriptor() == -1)
        {
            cout << "No existe usuario registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    Suscriptor *pSuscriptores;
    bool cargaExitosa;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        if(_repoTipoSuscripcion.buscar(reg.getTipoSuscripcion()) == -1)
        {
            cout << "El ID ingresado para el tipo de suscripcion no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        int cantRegistros = _repoSuscriptor.getCantidadRegistros();
        pSuscriptores = new Suscriptor[cantRegistros];
        if(pSuscriptores == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoSuscriptor.leer(pSuscriptores, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getEmail(),pSuscriptores[i].getEmail()) == 0)
            {
                cout << "El email ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                system("pause");
                system("cls");
                break;
            }
            if(strcmp(reg.getTelefono(),pSuscriptores[i].getTelefono()) == 0)
            {
                cout << "El telefono ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                system("pause");
                system("cls");
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pSuscriptores;
    return _repoSuscriptor.guardar(id-1, reg);
}

bool SuscriptorManager::eliminarSuscriptor()
{
    cout << "-------- BAJA DE SUSCRIPTOR --------" << endl;
    int id;
    Suscriptor reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a eliminar: " << endl;
        cin >> id;
        reg = _repoSuscriptor.leer(id - 1);
        if(reg.getIdSuscriptor() == -1)
        {
            cout << "No existe usuario registrado con ese ID... Vuelva a intentarlo..." << endl;
            system("pause");
            system("cls");
            continue;
        }
        system("pause");
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
    return _repoSuscriptor.eliminar(id - 1);
}
