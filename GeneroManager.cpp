#include "GeneroManager.h"
#include "Genero.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>

using namespace std;

bool GeneroManager::cargarGenero()
{
    int id, cantRegistros;
    Genero reg;
    Genero *pGeneros;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- CARGA DE NUEVO GENERO --------" << endl;

    cout << endl;
    if (deseaCancelar()) return false;

    id = _repoGenero.getNuevoID();
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "ID: #" << id << endl;

    reg.cargar();

    cantRegistros = _repoGenero.getCantidadRegistros();
    pGeneros = new Genero[cantRegistros];
    if(pGeneros == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoGenero.leer(pGeneros, cantRegistros);

    reg.setIdGenero(id);
    reg.setDescripcion(validarDescripcion(pGeneros, cantRegistros, reg.getDescripcion()).c_str());

    delete [] pGeneros;
    return _repoGenero.guardar(reg);
}

bool GeneroManager::modificarGenero()
{
    int id, cantRegistros;
    Genero reg;
    Genero *pGeneros;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ACTUALIZACION DE GENERO --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoGenero.leer(id - 1);
        while(reg.getIdGenero() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un genero registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarGeneros();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoGenero.leer(id - 1);
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

    cantRegistros = _repoGenero.getCantidadRegistros();
    pGeneros = new Genero[cantRegistros];
    if(pGeneros == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoGenero.leer(pGeneros, cantRegistros);

    reg.setDescripcion(validarDescripcion(pGeneros, cantRegistros, reg.getDescripcion()).c_str());

    delete [] pGeneros;
    return _repoGenero.guardar(id-1, reg);
}

bool GeneroManager::eliminarGenero()
{
    int id;
    Genero reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- BAJA DE GENERO --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoGenero.leer(id - 1);
        while(reg.getIdGenero() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un genero registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarGeneros();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoGenero.leer(id - 1);
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

    return _repoGenero.eliminar(id - 1);
}

bool GeneroManager::altaGenero()
{
    int id;
    Genero reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ALTA DE GENERO --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoGenero.leer(id - 1);
        while(reg.getIdGenero() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe genero registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarGeneros();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoGenero.leer(id - 1);
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
            if(strcasecmp(desc.c_str(), pGeneros[i].getDescripcion()) == 0)
            {
                cout << endl;
                rlutil::setColor(rlutil::RED);
                cout << "La descripcion ingresada ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << endl;
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otra descripcion: " << endl;
                rlutil::setColor(rlutil::WHITE);
                desc = cargarCadena();
                descValida = false;
                break;
            }
        }
    }
    while(!descValida);
    return desc;
}
