#include "DirectorManager.h"
#include "Director.h"
#include <iostream>
#include <cstring>

using namespace std;

bool DirectorManager::cargarDirector()
{
    cout << "-------- ALTA DE NUEVO DIRECTOR --------" << endl;
    int id = _repoDirector.getNuevoID();
    bool cargaExitosa;
    Director reg;
    Director *pDirectores;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        int cantRegistros = _repoDirector.getCantidadRegistros();
        pDirectores = new Director[cantRegistros];
        if(pDirectores == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoDirector.leer(pDirectores, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(
                strcmp(reg.getNombre(),pDirectores[i].getNombre()) == 0
                && strcmp(reg.getApellido(),pDirectores[i].getApellido()) == 0
                && strcmp(reg.getNacionalidad(),pDirectores[i].getNacionalidad()) == 0
            )
            {
                cout << "El director ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pDirectores;
    reg.setIdDirector(id);
    return _repoDirector.guardar(reg);
}

bool DirectorManager::modificarDirector()
{
    cout << "-------- ACTUALIZACION DE DIRECTOR --------" << endl;
    int id;
    Director reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a actualizar: " << endl;
        cin >> id;
        reg = _repoDirector.leer(id - 1);
        if(reg.getIdDirector() == -1)
        {
            cout << "No existe director registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    Director *pDirectores;
    bool cargaExitosa;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        int cantRegistros = _repoDirector.getCantidadRegistros();
        pDirectores = new Director[cantRegistros];
        if(pDirectores == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoDirector.leer(pDirectores, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(
                strcmp(reg.getNombre(),pDirectores[i].getNombre()) == 0
                && strcmp(reg.getApellido(),pDirectores[i].getApellido()) == 0
                && strcmp(reg.getNacionalidad(),pDirectores[i].getNacionalidad()) == 0
            )
            {
                cout << "El director ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pDirectores;
    return _repoDirector.guardar(id-1, reg);
}

bool DirectorManager::eliminarDirector()
{
    cout << "-------- BAJA DE DIRECTOR --------" << endl;
    int id;
    Director reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a eliminar: " << endl;
        cin >> id;
        reg = _repoDirector.leer(id - 1);
        if(reg.getIdDirector() == -1)
        {
            cout << "No existe director registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    return _repoDirector.eliminar(id - 1);
}
