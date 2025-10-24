#include "ConsumoManager.h"
#include "Consumo.h"
#include <iostream>

using namespace std;

bool ConsumoManager::cargarConsumo()
{
    cout << "-------- ALTA DE NUEVO CONSUMO --------" << endl;
    int id = _repoConsumo.getNuevoID();
    bool cargaExitosa;
    Consumo reg;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        if(_repoSuscriptor.buscar(reg.getIdSuscriptor()) == -1)
        {
            cout << "El ID ingresado para el suscriptor no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        if(_repoTipoContenido.buscar(reg.getIdContenido() == -1))
        {
            cout << "El ID ingresado para el tipo de contenido no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        else
        {
            if(reg.getIdContenido() == 1 && _repoSerie.buscar(reg.getIdContenido()) == -1)
            {
                cout << "El ID ingresado para la pelicula no existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                system("pause");
                system("cls");
                continue;
            }
            else if(reg.getIdContenido() == 2 && _repoPelicula.buscar(reg.getIdContenido()) == -1)
            {
                cout << "El ID ingresado para la serie no existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                system("pause");
                system("cls");
                continue;
            }
        }
        if(reg.getIdContenido() == 2)
        {
            Pelicula reg2 = _repoPelicula.leer(reg.getIdContenido() - 1);
            if(reg.getDuracionVista() > reg2.getDuracion())
            {
                cout << "La duracion vista excede al total de la pelicula... Intente cargar la informacion nuevamente..." << endl;
                cout << "La duracion total de la pelicula es " << reg2.getDuracion() << " minutos" << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
            }
        }
    }
    while(!cargaExitosa);
    reg.setIdAcceso(id);
    return _repoConsumo.guardar(reg);
}

bool ConsumoManager::modificarConsumo()
{
    cout << "-------- ACTUALIZACION DE CONSUMO --------" << endl;
    int id;
    Consumo reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a actualizar: " << endl;
        cin >> id;
        reg = _repoConsumo.leer(id - 1);
        if(reg.getIdAcceso() == -1)
        {
            cout << "No existe el consumo registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    bool cargaExitosa;
    do
    {
        cargaExitosa = true;
        cout << "ID: #" << id << endl;
        reg.cargar();
        if(_repoSuscriptor.buscar(reg.getIdSuscriptor()) == -1)
        {
            cout << "El ID ingresado para el suscriptor no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        if(_repoTipoContenido.buscar(reg.getIdContenido() == -1))
        {
            cout << "El ID ingresado para el tipo de contenido no existe... Intente cargar la informacion nuevamente..." << endl;
            cargaExitosa = false;
            system("pause");
            system("cls");
            continue;
        }
        else
        {
            if(reg.getIdContenido() == 1 && _repoSerie.buscar(reg.getIdContenido()) == -1)
            {
                cout << "El ID ingresado para la pelicula no existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                system("pause");
                system("cls");
                continue;
            }
            else if(reg.getIdContenido() == 2 && _repoPelicula.buscar(reg.getIdContenido()) == -1)
            {
                cout << "El ID ingresado para la serie no existe... Intente cargar la informacion nuevamente..." << endl;
                cargaExitosa = false;
                system("pause");
                system("cls");
                continue;
            }
        }
        if(reg.getIdContenido() == 2)
        {
            Pelicula reg2 = _repoPelicula.leer(reg.getIdContenido() - 1);
            if(reg.getDuracionVista() > reg2.getDuracion())
            {
                cout << "La duracion vista excede al total de la pelicula... Intente cargar la informacion nuevamente..." << endl;
                cout << "La duracion total de la pelicula es " << reg2.getDuracion() << " minutos" << endl;
                system("pause");
                system("cls");
                cargaExitosa = false;
            }
        }
    }
    while(!cargaExitosa);
    return _repoConsumo.guardar(id-1, reg);
}

bool ConsumoManager::eliminarConsumo()
{
    cout << "-------- BAJA DE CONSUMO --------" << endl;
    int id;
    Consumo reg;
    char respuesta;
    do
    {
        cout << "Ingrese ID del registro a eliminar: " << endl;
        cin >> id;
        reg = _repoConsumo.leer(id - 1);
        if(reg.getIdAcceso() == -1)
        {
            cout << "No existe consumo registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    return _repoConsumo.eliminar(id - 1);
}
