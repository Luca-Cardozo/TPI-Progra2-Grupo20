#include "SerieManager.h"
#include "Serie.h"
#include "utils.h"
#include <iostream>
#include <cstring>
using namespace std;
bool SerieManager::cargarSerie()
{
    cout << "-------- CARGA DE NUEVA SERIE --------" << endl;
    int carga;
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
    int id = _repoSerie.getNuevoID();
    Serie reg;
    Serie *pSeries;
    cout << "ID: #" << id << endl;
    reg.cargar();
    reg.setIdDirector(validarDirector(reg.getIdDirector()));
    reg.setGenero(validarGenero(reg.getGenero()));
    reg.setClasificacion(validarClasificacion(reg.getClasificacion()));
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
    reg.setTitulo(validarTitulo(pSeries, cantRegistros, reg.getTitulo()).c_str());
    delete [] pSeries;
    reg.setId(id);
    reg.setIdTipoContenido(2);
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
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
        cout << "Ingrese ID del registro a actualizar (0 para anular la actualizacion): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Modificacion anulada..." << endl;
            return false;
        }
        reg = _repoSerie.leer(id - 2001);
        if(reg.getId() == -1)
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
    cout << "ID: #" << id << endl;
    reg.cargar();
    reg.setIdDirector(validarDirector(reg.getIdDirector()));
    reg.setGenero(validarGenero(reg.getGenero()));
    reg.setClasificacion(validarClasificacion(reg.getClasificacion()));
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
    reg.setTitulo(validarTitulo(pSeries, cantRegistros, reg.getTitulo()).c_str());
    delete [] pSeries;
    return _repoSerie.guardar(id-2001, reg);
}

bool SerieManager::eliminarSerie()
{
    cout << "-------- BAJA DE SERIE --------" << endl;
    int id;
    Serie reg;
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
        reg = _repoSerie.leer(id - 2001);
        while(reg.getId() == -1)
        {
            cout << "No existe serie registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Baja cancelada..." << endl;
                return false;
            }
            reg = _repoSerie.leer(id - 2001);
        }
        cout << "----- DATOS DEL REGISTRO A DAR DE BAJA -----" << endl;
        reg.mostrar();
        if(reg.getEliminado())
        {
            cout << "El registro ya se encuentra dado de baja..." << endl;
            return false;
        }
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
    return _repoSerie.eliminar(id - 2001);
}

bool SerieManager::altaSerie()
{
    cout << "-------- ALTA DE SERIE --------" << endl;
    int id;
    Serie reg;
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
        reg = _repoSerie.leer(id - 2001);
        while(reg.getId() == -1)
        {
            cout << "No existe serie registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a dar de alta (0 para cancelar el alta): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Alta cancelada..." << endl;
                return false;
            }
            reg = _repoSerie.leer(id - 2001);
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
    while(respuesta != 's' || respuesta != 'S');
    return _repoSerie.alta(id - 2001);
}

int SerieManager::validarDirector(int id)
{
    char respuesta;
    while(_repoDirector.buscar(id) == -1)
    {
        cout << "El ID ingresado para el director no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << "ID Director: ";
        cin >> id;
    }
    while(true)
    {
        Director aux = _repoDirector.leer(id - 1);
        if(aux.getEliminado())
        {
            cout << "El director se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                cout << "El director se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoDirector.guardar(aux.getId() - 1, aux);
                cout << "Director reactivado correctamente" << endl;
                break;
            }
            else
            {
                cout << "Ingrese otro ID de director: ";
                cin >> id;
            }
        }
        else break;
    }
    return id;
}

int SerieManager::validarGenero(int id)
{
    char respuesta;
    while(_repoGenero.buscar(id) == -1)
    {
        cout << "El ID ingresado para el genero no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << "ID Genero: ";
        cin >> id;
    }
    while(true)
    {
        Genero aux = _repoGenero.leer(id - 1);
        if(aux.getEliminado())
        {
            cout << "El genero se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                cout << "El genero se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoGenero.guardar(aux.getIdGenero() - 1, aux);
                cout << "Genero reactivado correctamente" << endl;
                break;
            }
            else
            {
                cout << "Ingrese otro ID de genero: ";
                cin >> id;
            }
        }
        else break;
    }
    return id;
}

int SerieManager::validarClasificacion(int id)
{
    char respuesta;
    while(_repoClasificacion.buscar(id) == -1)
    {
        cout << "El ID ingresado para la clasificacion no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << "ID Clasificacion: ";
        cin >> id;
    }
    while(true)
    {
        Clasificacion aux = _repoClasificacion.leer(id - 1);
        if(aux.getEliminado())
        {
            cout << "La clasificacion se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                cout << "La clasificacion se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoClasificacion.guardar(aux.getIdClasificacion() - 1, aux);
                cout << "Clasificacion reactivada correctamente" << endl;
                break;
            }
            else
            {
                cout << "Ingrese otro ID de clasificacion: ";
                cin >> id;
            }
        }
        else break;
    }
    return id;
}

string SerieManager::validarTitulo(Serie* pSeries,  int cant, const char* t)
{
    string tit = t;
    bool titValido;
    do
    {
        titValido = true;
        for(int i = 0; i < cant; i++)
        {
            if(strcmp(tit.c_str(), pSeries[i].getTitulo()) == 0)
            {
                cout << "El titulo ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << "Ingrese otro titulo: " << endl;
                tit = cargarCadena();
                titValido = false;
                break;
            }
        }
    }
    while(!titValido);
    return tit;
}

