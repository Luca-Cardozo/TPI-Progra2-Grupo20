#include "GeneroManager.h"
#include "Genero.h"
#include <iostream>
#include <cstring>

using namespace std;

bool GeneroManager::cargarGenero()
{
    cout << "-------- ALTA DE NUEVO GENERO --------" << endl;
    int id = _repoGenero.getNuevoID();
    bool cargaExitosa;
    Genero reg;
    Genero *pGeneros;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        int cantRegistros = _repoGenero.getCantidadRegistros();
        pGeneros = new Genero[cantRegistros];
        if(pGeneros == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoGenero.leer(pGeneros, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getDescripcion(),pGeneros[i].getDescripcion()) == 0)
            {
                cout << "El genero ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pGeneros;
    reg.setIdGenero(id);
    return _repoGenero.guardar(reg);
}

bool GeneroManager::modificarGenero()
{
    cout << "-------- ACTUALIZACION DE GENERO --------" << endl;
    int id;
    Genero reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a actualizar: " << endl;
        cin >> id;
        reg = _repoGenero.leer(id - 1);
        if(reg.getIdGenero() == -1)
        {
            cout << "No existe un genero registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    Genero *pGeneros;
    bool cargaExitosa;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        int cantRegistros = _repoGenero.getCantidadRegistros();
        pGeneros = new Genero[cantRegistros];
        if(pGeneros == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoGenero.leer(pGeneros, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getDescripcion(),pGeneros[i].getDescripcion()) == 0)
            {
                cout << "El genero ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pGeneros;
    return _repoGenero.guardar(id-1, reg);
}

bool GeneroManager::eliminarGenero()
{
    cout << "-------- BAJA DE GENERO --------" << endl;
    int id;
    Genero reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a eliminar: " << endl;
        cin >> id;
        reg = _repoGenero.leer(id - 1);
        if(reg.getIdGenero() == -1)
        {
            cout << "No existe un genero registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    return _repoGenero.eliminar(id - 1);
}
