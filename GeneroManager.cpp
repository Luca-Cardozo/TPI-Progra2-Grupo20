#include "GeneroManager.h"
#include "Genero.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

bool GeneroManager::cargarGenero()
{
    cout << "-------- CARGA DE NUEVO GENERO --------" << endl;
    int carga;
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
    int id = _repoGenero.getNuevoID();
    Genero reg;
    Genero *pGeneros;
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
    reg.setDescripcion(validarDescripcion(pGeneros, cantRegistros, reg.getDescripcion()).c_str());
    delete [] pGeneros;
    reg.setIdGenero(id);
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
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
        cout << "Ingrese ID del registro a actualizar (0 para anular la actualizacion): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Modificacion anulada..." << endl;
            return false;
        }
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
    reg.setDescripcion(validarDescripcion(pGeneros, cantRegistros, reg.getDescripcion()).c_str());
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
        cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Baja cancelada..." << endl;
            return false;
        }
        reg = _repoGenero.leer(id - 1);
        while(reg.getIdGenero() == -1)
        {
            cout << "No existe un genero registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Baja cancelada..." << endl;
                return false;
            }
            reg = _repoGenero.leer(id - 1);
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

bool GeneroManager::altaGenero()
{
    cout << "-------- ALTA DE GENERO --------" << endl;
    int id;
    Genero reg;
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
        reg = _repoGenero.leer(id - 1);
        while(reg.getIdGenero() == -1)
        {
            cout << "No existe genero registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a dar de alta (0 para cancelar el alta): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Alta cancelada..." << endl;
                return false;
            }
            reg = _repoGenero.leer(id - 1);
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
    return _repoGenero.alta(id - 1);
}

string GeneroManager::validarDescripcion(Genero* pGeneros,  int cant, const char* d)
{
    string desc = d;
    bool descValida;
    do
    {
        descValida = true;
        for(int i = 0; i < cant; i++)
        {
            if(strcmp(desc.c_str(), pGeneros[i].getDescripcion()) == 0)
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
