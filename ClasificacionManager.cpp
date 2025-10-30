#include "ClasificacionManager.h"
#include "Clasificacion.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

bool ClasificacionManager::cargarClasificacion()
{
    cout << "-------- CARGA DE NUEVA CLASIFICACION --------" << endl;
    int carga;
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
    int id = _repoClasificacion.getNuevoID();
    Clasificacion reg;
    Clasificacion *pClasificaciones;
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
    reg.setDescripcion(validarDescripcion(pClasificaciones, cantRegistros, reg.getDescripcion()).c_str());
    delete [] pClasificaciones;
    reg.setIdClasificacion(id);
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
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
        cout << "Ingrese ID del registro a actualizar (0 para anular la actualizacion): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Modificacion anulada..." << endl;
            return false;
        }
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
    reg.setDescripcion(validarDescripcion(pClasificaciones, cantRegistros, reg.getDescripcion()).c_str());
    delete [] pClasificaciones;
    return _repoClasificacion.guardar(id-1, reg);
}

bool ClasificacionManager::eliminarClasificacion()
{
    cout << "-------- BAJA DE CLASIFICACION --------" << endl;
    int id;
    Clasificacion reg;
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
        reg = _repoClasificacion.leer(id - 1);
        while(reg.getIdClasificacion() == -1)
        {
            cout << "No existe clasificacion registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Baja cancelada..." << endl;
                return false;
            }
            reg = _repoClasificacion.leer(id - 1);
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

bool ClasificacionManager::altaClasificacion()
{
    cout << "-------- ALTA DE CLASIFICACION --------" << endl;
    int id;
    Clasificacion reg;
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
        reg = _repoClasificacion.leer(id - 1);
        while(reg.getIdClasificacion() == -1)
        {
            cout << "No existe clasificacion registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a dar de alta (0 para cancelar el alta): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Alta cancelada..." << endl;
                return false;
            }
            reg = _repoClasificacion.leer(id - 1);
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
    return _repoClasificacion.alta(id - 1);
}

string ClasificacionManager::validarDescripcion(Clasificacion* pClasificaciones,  int cant, const char* d)
{
    string desc = d;
    bool descValida;
    do
    {
        descValida = true;
        for(int i = 0; i < cant; i++)
        {
            if(strcmp(desc.c_str(), pClasificaciones[i].getDescripcion()) == 0)
            {
                cout << "La descripcion ingresada ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << "Ingrese otra descripcion: " << endl;
                desc = cargarCadena();
                break;
            }
        }
    }
    while(!descValida);
    return desc;
}
