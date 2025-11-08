#include "DirectorManager.h"
#include "Director.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>

using namespace std;

bool DirectorManager::cargarDirector()
{
    int id, cantRegistros;
    Director reg;
    Director *pDirectores;
    char nombre[20], apellido[20];

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- CARGA DE NUEVO DIRECTOR --------" << endl;

    cout << endl;
    if (deseaCancelar()) return false;

    id = _repoDirector.getNuevoID();
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "ID: #" << id << endl;

    reg.cargar();

    cantRegistros = _repoDirector.getCantidadRegistros();
    pDirectores = new Director[cantRegistros];
    if(pDirectores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoDirector.leer(pDirectores, cantRegistros);

    reg.setId(id);

    if(validarNombreApellido(pDirectores, cantRegistros, reg.getNombre(), reg.getApellido(), nombre, apellido))
    {
        reg.setNombre(nombre);
        reg.setApellido(apellido);
    }

    delete [] pDirectores;
    return _repoDirector.guardar(reg);
}

bool DirectorManager::modificarDirector()
{
    int id, cantRegistros;
    Director reg;
    Director *pDirectores;
    char nombre[20], apellido[20];

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ACTUALIZACION DE DIRECTOR --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoDirector.leer(id - 1);
        while(reg.getId() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un director registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarDirectoresApellido();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoDirector.leer(id - 1);
        }
        system("cls");
        rlutil::setColor(rlutil::YELLOW);
        cout << "----- DATOS DEL REGISTRO A MODIFICAR -----" << endl;
        reg.mostrar();
        cout << endl;
        if (confirmarAccion("Este es el registro a modificar?")) break;
    }

    system("cls");
    rlutil::setColor(rlutil::LIGHTRED);
    cout << "----- CARGUE LOS NUEVOS DATOS DEL REGISTRO -----" << endl;

    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << endl;
    cout << "ID: #" << id << endl;

    reg.cargar();

    cantRegistros = _repoDirector.getCantidadRegistros();
    pDirectores = new Director[cantRegistros];
    if(pDirectores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoDirector.leer(pDirectores, cantRegistros);

    if(validarNombreApellido(pDirectores, cantRegistros, reg.getNombre(), reg.getApellido(), nombre, apellido, reg.getId()))
    {
        reg.setNombre(nombre);
        reg.setApellido(apellido);
    }

    delete [] pDirectores;
    return _repoDirector.guardar(id-1, reg);
}

bool DirectorManager::eliminarDirector()
{
    int id;
    Director reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- BAJA DE DIRECTOR --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoDirector.leer(id - 1);
        while(reg.getId() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un director registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarDirectoresApellido();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoDirector.leer(id - 1);
        }
        system("cls");
        rlutil::setColor(rlutil::YELLOW);
        cout << "----- DATOS DEL REGISTRO A DAR DE BAJA -----" << endl;
        reg.mostrar();
        if(reg.getEliminado())
        {
            cout << endl;
            rlutil::setColor(rlutil::RED);
            cout << "El registro ya se encuentra dado de baja..." << endl;
            rlutil::setColor(rlutil::WHITE);
            return false;
        }
        cout << endl;
        if (confirmarAccion("Este es el registro a eliminar?")) break;
    }

    return _repoDirector.eliminar(id - 1);
}

bool DirectorManager::altaDirector()
{
    int id;
    Director reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ALTA DE DIRECTOR --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoDirector.leer(id - 1);
        while(reg.getId() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe director registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarDirectoresApellido();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoDirector.leer(id - 1);
        }
        system("cls");
        rlutil::setColor(rlutil::YELLOW);
        cout << "----- DATOS DEL REGISTRO A DAR DE ALTA -----" << endl;
        reg.mostrar();
        if(!reg.getEliminado())
        {
            cout << endl;
            rlutil::setColor(rlutil::RED);
            cout << "El registro ya se encuentra dado de alta..." << endl;
            rlutil::setColor(rlutil::WHITE);
            return false;
        }
        cout << endl;
        if (confirmarAccion("Este es el registro a dar de alta?")) break;
    }

    return _repoDirector.alta(id - 1);
}

bool DirectorManager::validarNombreApellido(Director* pDirectores,  int cant, const char* n, const char* a, char nombre[20], char apellido[20], int idActual)
{
    string nom = n;
    string ape = a;
    bool directorValido;
    do
    {
        directorValido = true;
        for(int i = 0; i < cant; i++)
        {
            if (pDirectores[i].getId() == idActual) continue;


            if(strcasecmp(nom.c_str(), pDirectores[i].getNombre()) == 0 && strcmp(ape.c_str(), pDirectores[i].getApellido()) == 0)
            {
                cout << endl;
                rlutil::setColor(rlutil::RED);
                cout << "El nombre y apellido ingresados ya existen... Intente cargar la informacion nuevamente..." << endl;
                cout << endl;
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro nombre: " << endl;
                rlutil::setColor(rlutil::WHITE);
                nom = cargarCadena();
                cout << endl;
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro apellido: " << endl;
                rlutil::setColor(rlutil::WHITE);
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
