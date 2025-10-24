#include "SerieManager.h"
#include "Serie.h"
#include <iostream>
#include <cstring>

using namespace std;

bool SerieManager::cargarSerie()
{
    cout << "-------- ALTA DE NUEVA SERIE --------" << endl;
    int id = _repoSerie.getNuevoID();
    bool cargaExitosa;
    Serie reg;
    Serie *pSeries;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        if(_repoDirector.buscar(reg.getIdDirector()) == -1)
        {
            cout << "El ID ingresado para el director no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        if(_repoGenero.buscar(reg.getGenero()) == -1)
        {
            cout << "El ID ingresado para el genero no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        if(_repoClasificacion.buscar(reg.getClasificacion()) == -1)
        {
            cout << "El ID ingresado para la clasificacion no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        int cantRegistros = _repoSerie.getCantidadRegistros();
        pSeries = new Serie[cantRegistros];
        if(pSeries == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoSerie.leer(pSeries, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getTitulo(),pSeries[i].getTitulo()) == 0)
            {
                cout << "El titulo ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pSeries;
    reg.setIdSerie(id);
    reg.setIdTipoContenido(2);
    return _repoSerie.guardar(reg);
}

bool SerieManager::modificarSerie()
{
    cout << "-------- ACTUALIZACION DE SERIE --------" << endl;
    int id;
    Serie reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a actualizar: " << endl;
        cin >> id;
        reg = _repoSerie.leer(id - 1);
        if(reg.getIdSerie() == -1)
        {
            cout << "No existe serie registrada con ese ID... Vuelva a intentarlo..." << endl;
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
    Serie *pSeries;
    bool cargaExitosa;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        if(_repoDirector.buscar(reg.getIdDirector()) == -1)
        {
            cout << "El ID ingresado para el director no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        if(_repoGenero.buscar(reg.getGenero()) == -1)
        {
            cout << "El ID ingresado para el genero no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        if(_repoClasificacion.buscar(reg.getClasificacion()) == -1)
        {
            cout << "El ID ingresado para la clasificacion no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        int cantRegistros = _repoSerie.getCantidadRegistros();
        pSeries = new Serie[cantRegistros];
        if(pSeries == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoSerie.leer(pSeries, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getTitulo(),pSeries[i].getTitulo()) == 0)
            {
                cout << "El titulo ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
                break;
            }
        }
    }
    while(!cargaExitosa);
    delete [] pSeries;
    return _repoSerie.guardar(id-1, reg);
}

bool SerieManager::eliminarSerie()
{
    cout << "-------- BAJA DE SERIE --------" << endl;
    int id;
    Serie reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a eliminar: " << endl;
        cin >> id;
        reg = _repoSerie.leer(id - 1);
        if(reg.getIdSerie() == -1)
        {
            cout << "No existe serie registrada con ese ID... Vuelva a intentarlo..." << endl;
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
    return _repoSerie.eliminar(id - 1);
}
