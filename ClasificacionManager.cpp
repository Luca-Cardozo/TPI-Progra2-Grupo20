#include "ClasificacionManager.h"
#include "Clasificacion.h"
#include <iostream>
#include <cstring>

using namespace std;

bool ClasificacionManager::cargarClasificacion()
{
    cout << "-------- ALTA DE NUEVA CLASIFICACION --------" << endl;
    int id = _repoClasificacion.getNuevoID();
    bool cargaExitosa;
    Clasificacion reg;
    Clasificacion *pClasificaciones;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        int cantRegistros = _repoClasificacion.getCantidadRegistros();
        pClasificaciones = new Clasificacion[cantRegistros];
        if(pClasificaciones == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoClasificacion.leer(pClasificaciones, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getDescripcion(),pClasificaciones[i].getDescripcion()) == 0)
            {
                cout << "La clasificacion ingresada ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pClasificaciones;
    reg.setIdClasificacion(id);
    return _repoClasificacion.guardar(reg);
}

bool ClasificacionManager::modificarClasificacion()
{
    cout << "-------- ACTUALIZACION DE CLASIFICACION --------" << endl;
    int id;
    Clasificacion reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a actualizar: " << endl;
        cin >> id;
        reg = _repoClasificacion.leer(id - 1);
        if(reg.getIdClasificacion() == -1)
        {
            cout << "No existe una clasificacion registrada con ese ID... Vuelva a intentarlo..." << endl;
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
    Clasificacion *pClasificaciones;
    bool cargaExitosa;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        int cantRegistros = _repoClasificacion.getCantidadRegistros();
        pClasificaciones = new Clasificacion[cantRegistros];
        if(pClasificaciones == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoClasificacion.leer(pClasificaciones, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getDescripcion(),pClasificaciones[i].getDescripcion()) == 0)
            {
                cout << "La clasificacion ingresada ya existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pClasificaciones;
    return _repoClasificacion.guardar(id-1, reg);
}

bool ClasificacionManager::eliminarClasificacion()
{
    cout << "-------- BAJA DE TIPO DE CONTENIDO --------" << endl;
    int id;
    Clasificacion reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a eliminar: " << endl;
        cin >> id;
        reg = _repoClasificacion.leer(id - 1);
        if(reg.getIdClasificacion() == -1)
        {
            cout << "No existe una clasificacion registrada con ese ID... Vuelva a intentarlo..." << endl;
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
    return _repoClasificacion.eliminar(id - 1);
}
