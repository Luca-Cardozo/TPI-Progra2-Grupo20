#include "DirectorManager.h"
#include "Director.h"
#include "utils.h"
#include <iostream>
#include <cstring>

using namespace std;

bool DirectorManager::cargarDirector()
{
    cout << "-------- CARGA DE NUEVO DIRECTOR --------" << endl;
    int carga;
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
    int id = _repoDirector.getNuevoID();
    Director reg;
    Director *pDirectores;
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
    char nombre[20], apellido[20];
    if(validarNombreApellido(pDirectores, cantRegistros, reg.getNombre(), reg.getApellido(), nombre, apellido))
    {
        reg.setNombre(nombre);
        reg.setApellido(apellido);
    }
    delete [] pDirectores;
    reg.setId(id);
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
        cout << "Ingrese ID del registro a actualizar (0 para anular la actualizacion): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Modificacion anulada..." << endl;
            return false;
        }
        reg = _repoDirector.leer(id - 1);
        if(reg.getId() == -1)
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
    while(respuesta != 's' && respuesta != 'S');
    system("cls");
    cout << "----- CARGUE LOS NUEVOS DATOS DEL REGISTRO -----" << endl;
    Director *pDirectores;
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
    char nombre[20], apellido[20];
    if(validarNombreApellido(pDirectores, cantRegistros, reg.getNombre(), reg.getApellido(), nombre, apellido))
    {
        reg.setNombre(nombre);
        reg.setApellido(apellido);
    }
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
        cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Baja cancelada..." << endl;
            return false;
        }
        reg = _repoDirector.leer(id - 1);
        while(reg.getId() == -1)
        {
            cout << "No existe director registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Baja cancelada..." << endl;
                return false;
            }
            reg = _repoDirector.leer(id - 1);
        }
        system("pause");
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
    while(respuesta != 's' && respuesta != 'S');
    return _repoDirector.eliminar(id - 1);
}

bool DirectorManager::altaDirector()
{
    cout << "-------- ALTA DE DIRECTOR --------" << endl;
    int id;
    Director reg;
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
        reg = _repoDirector.leer(id - 1);
        while(reg.getId() == -1)
        {
            cout << "No existe director registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a dar de alta (0 para cancelar el alta): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Alta cancelada..." << endl;
                return false;
            }
            reg = _repoDirector.leer(id - 1);
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
    while(respuesta != 's' && respuesta != 'S');
    return _repoDirector.alta(id - 1);
}

bool DirectorManager::validarNombreApellido(Director* pDirectores,  int cant, const char* n, const char* a, char nombre[20], char apellido[20])
{
    string nom = n;
    string ape = a;
    bool directorValido;
    do
    {
        directorValido = true;
        for(int i = 0; i < cant; i++)
        {
            if(strcasecmp(nom.c_str(), pDirectores[i].getNombre()) == 0 && strcmp(ape.c_str(), pDirectores[i].getApellido()) == 0)
            {
                cout << "El nombre y apellido ingresados ya existen... Intente cargar la informacion nuevamente..." << endl;
                cout << "Ingrese otro nombre: " << endl;
                nom = cargarCadena();
                cout << "Ingrese otro apellido: " << endl;
                ape = cargarCadena();
                directorValido = false;
                break;
            }
        }
    }
    while(!directorValido);
    strcpy(nombre, nom.c_str());
    strcpy(apellido, ape.c_str());
    return true;
}
