#include "PeliculaManager.h"
#include "Pelicula.h"
#include <iostream>
#include <cstring>

using namespace std;

bool PeliculaManager::cargarPelicula()
{
    cout << "-------- ALTA DE NUEVA PELICULA --------" << endl;
    int id = _repoPelicula.getNuevoID();
    bool cargaExitosa;
    Pelicula reg;
    Pelicula *pPeliculas;
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
        int cantRegistros = _repoPelicula.getCantidadRegistros();
        pPeliculas = new Pelicula[cantRegistros];
        if(pPeliculas == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoPelicula.leer(pPeliculas, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getTitulo(),pPeliculas[i].getTitulo()) == 0)
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
    delete [] pPeliculas;
    reg.setIdPelicula(id);
    reg.setIdTipoContenido(1);
    return _repoPelicula.guardar(reg);
}

bool PeliculaManager::modificarPelicula()
{
    cout << "-------- ACTUALIZACION DE PELICULA --------" << endl;
    int id;
    Pelicula reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a actualizar: " << endl;
        cin >> id;
        reg = _repoPelicula.leer(id - 1);
        if(reg.getIdPelicula() == -1)
        {
            cout << "No existe pelicula registrada con ese ID... Vuelva a intentarlo..." << endl;
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
    Pelicula *pPeliculas;
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
        int cantRegistros = _repoPelicula.getCantidadRegistros();
        pPeliculas = new Pelicula[cantRegistros];
        if(pPeliculas == nullptr)
        {
            cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
            system("pause");
            system("cls");
            return false;
        }
        _repoPelicula.leer(pPeliculas, cantRegistros);
        for(int i = 0; i < cantRegistros; i++)
        {
            if(strcmp(reg.getTitulo(),pPeliculas[i].getTitulo()) == 0)
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
    delete [] pPeliculas;
    return _repoPelicula.guardar(id-1, reg);
}

bool PeliculaManager::eliminarPelicula()
{
    cout << "-------- BAJA DE PELICULA --------" << endl;
    int id;
    Pelicula reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a eliminar: " << endl;
        cin >> id;
        reg = _repoPelicula.leer(id - 1);
        if(reg.getIdPelicula() == -1)
        {
            cout << "No existe pelicula registrada con ese ID... Vuelva a intentarlo..." << endl;
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
    return _repoPelicula.eliminar(id - 1);
}
