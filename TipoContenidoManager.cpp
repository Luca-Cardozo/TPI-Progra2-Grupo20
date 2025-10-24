#include "TipoContenidoManager.h"
#include "TipoContenido.h"
#include <iostream>
#include <cstring>

using namespace std;

bool TipoContenidoManager::cargarTipoContenido()
{
    cout << "-------- ALTA DE NUEVO TIPO DE CONTENIDO --------" << endl;
    int id = _repoTipoContenido.getNuevoID();
    bool cargaExitosa;
    TipoContenido reg;
    TipoContenido *pTiposContenido;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        int cantRegistros = _repoTipoContenido.getCantidadRegistros();
        pTiposContenido = new TipoContenido[cantRegistros];
        if(pTiposContenido == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoTipoContenido.leer(pTiposContenido, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getDescripcion(),pTiposContenido[i].getDescripcion()) == 0)
            {
                cout << "El tipo de contenido ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pTiposContenido;
    reg.setIdTipoContenido(id);
    return _repoTipoContenido.guardar(reg);
}

bool TipoContenidoManager::modificarTipoContenido()
{
    cout << "-------- ACTUALIZACION DE TIPO DE CONTENIDO --------" << endl;
    int id;
    TipoContenido reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a actualizar: " << endl;
        cin >> id;
        reg = _repoTipoContenido.leer(id - 1);
        if(reg.getIdTipoContenido() == -1)
        {
            cout << "No existe un tipo de contenido registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    TipoContenido *pTiposContenido;
    bool cargaExitosa;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        int cantRegistros = _repoTipoContenido.getCantidadRegistros();
        pTiposContenido = new TipoContenido[cantRegistros];
        if(pTiposContenido == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoTipoContenido.leer(pTiposContenido, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getDescripcion(),pTiposContenido[i].getDescripcion()) == 0)
            {
                cout << "El tipo de contenido ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pTiposContenido;
    return _repoTipoContenido.guardar(id-1, reg);
}

bool TipoContenidoManager::eliminarTipoContenido()
{
    cout << "-------- BAJA DE TIPO DE CONTENIDO --------" << endl;
    int id;
    TipoContenido reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a eliminar: " << endl;
        cin >> id;
        reg = _repoTipoContenido.leer(id - 1);
        if(reg.getIdTipoContenido() == -1)
        {
            cout << "No existe un tipo de contenido registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    return _repoTipoContenido.eliminar(id - 1);
}
