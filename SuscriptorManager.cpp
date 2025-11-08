#include "SuscriptorManager.h"
#include "Suscriptor.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool SuscriptorManager::cargarSuscriptor()
{
    int id, cantRegistros;
    Suscriptor reg;
    Suscriptor *pSuscriptores;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- CARGA DE NUEVO SUSCRIPTOR --------" << endl;

    cout << endl;
    if (deseaCancelar()) return false;

    id = _repoSuscriptor.getNuevoID();
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "ID: #" << id << endl;

    reg.cargar();

    cantRegistros = _repoSuscriptor.getCantidadRegistros();
    pSuscriptores = new Suscriptor[cantRegistros];
    if(pSuscriptores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoSuscriptor.leer(pSuscriptores, cantRegistros);

    reg.setId(id);
    reg.setEmail(validarEmail(pSuscriptores, cantRegistros, reg.getEmail()).c_str());
    reg.setTelefono(validarTelefono(pSuscriptores, cantRegistros, reg.getTelefono()).c_str());
    reg.setTipoSuscripcion(validarTipoSuscripcion(reg.getTipoSuscripcion()));

    delete [] pSuscriptores;
    return _repoSuscriptor.guardar(reg);
}

bool SuscriptorManager::modificarSuscriptor()
{
    int id, cantRegistros;
    Suscriptor reg;
    Suscriptor *pSuscriptores;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ACTUALIZACION DE SUSCRIPTOR --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoSuscriptor.leer(id - 1);
        while(reg.getId() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un suscriptor registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarSuscriptoresApellido();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoSuscriptor.leer(id - 1);
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

    cantRegistros = _repoSuscriptor.getCantidadRegistros();
    pSuscriptores = new Suscriptor[cantRegistros];
    if(pSuscriptores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoSuscriptor.leer(pSuscriptores, cantRegistros);

    reg.setEmail(validarEmail(pSuscriptores, cantRegistros, reg.getEmail(), reg.getId()).c_str());
    reg.setTelefono(validarTelefono(pSuscriptores, cantRegistros, reg.getTelefono(), reg.getId()).c_str());
    reg.setTipoSuscripcion(validarTipoSuscripcion(reg.getTipoSuscripcion()));

    delete [] pSuscriptores;
    return _repoSuscriptor.guardar(id-1, reg);
}

bool SuscriptorManager::eliminarSuscriptor()
{
    int id;
    Suscriptor reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- BAJA DE SUSCRIPTOR --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoSuscriptor.leer(id - 1);
        while(reg.getId() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un suscriptor registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarSuscriptoresApellido();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoSuscriptor.leer(id - 1);
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

    return _repoSuscriptor.eliminar(id - 1);
}

bool SuscriptorManager::altaSuscriptor()
{
    int id;
    Suscriptor reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ALTA DE SUSCRIPTOR --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoSuscriptor.leer(id - 1);
        while(reg.getId() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe suscriptor registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarSuscriptoresApellido();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoSuscriptor.leer(id - 1);
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

    return _repoSuscriptor.alta(id - 1);
}

int SuscriptorManager::validarTipoSuscripcion(int id)
{
    char respuesta;
    while(_repoTipoSuscripcion.buscar(id) == -1)
    {
        cout << endl;
        rlutil::setColor(rlutil::RED);
        cout << "El ID ingresado para el tipo de suscripcion no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        system("pause");
        system("cls");
        _listados.listarTiposSuscripcion();
        rlutil::setColor(rlutil::CYAN);
        cout << "Ingrese alguno de los tipos de suscripcion disponibles por favor..." << endl;
        cout << "ID Tipo de Suscripcion: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> id;
        id = validarPositivo(id);
    }
    while(true)
    {
        TipoSuscripcion aux = _repoTipoSuscripcion.leer(id - 1);
        if(aux.getEliminado())
        {
            rlutil::setColor(rlutil::BROWN);
            cout << endl;
            cout << "El tipo de suscripcion se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                rlutil::setColor(rlutil::RED);
                cout << endl;
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                rlutil::setColor(rlutil::BROWN);
                cout << endl;
                cout << "El tipo de suscripcion se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
                rlutil::setColor(rlutil::WHITE);
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoTipoSuscripcion.guardar(aux.getIdTipoSuscripcion() - 1, aux);
                cout << endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "Tipo de suscripcion reactivado correctamente" << endl;
                rlutil::setColor(rlutil::WHITE);
                break;
            }
            else
            {
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro ID de tipo de suscripcion: ";
                rlutil::setColor(rlutil::WHITE);
                cin >> id;
                id = validarPositivo(id);
            }
        }
        else break;
    }
    return id;
}

string SuscriptorManager::validarEmail(Suscriptor* pSuscriptores,  int cant, const char* e, int idActual)
{
    string email = e;
    bool mailValido;
    do
    {
        mailValido = true;
        for(int i = 0; i < cant; i++)
        {
            if (pSuscriptores[i].getId() == idActual) continue;

            if(strcasecmp(email.c_str(), pSuscriptores[i].getEmail()) == 0)
            {
                cout << endl;
                rlutil::setColor(rlutil::RED);
                cout << "El email ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << endl;
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro email: " << endl;
                rlutil::setColor(rlutil::WHITE);
                email = cargarCadena();
                mailValido = false;
                break;
            }
        }
    }
    while(!mailValido);
    return email;
}

string SuscriptorManager::validarTelefono(Suscriptor* pSuscriptores,  int cant, const char* t, int idActual)
{
    string tel = t;
    bool telValido;
    do
    {
        telValido = true;
        for(int i = 0; i < (int)tel.length(); i++)
        {
            if (pSuscriptores[i].getId() == idActual) continue;

            if(!isdigit(tel[i]))
            {
                cout << endl;
                rlutil::setColor(rlutil::RED);
                cout << "El telefono solo puede contener numeros... Intente cargar la informacion nuevamente..." << endl;
                cout << endl;
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro telefono: " << endl;
                rlutil::setColor(rlutil::WHITE);
                tel = cargarCadena();
                telValido = false;
                break;
            }
        }
        for(int i = 0; i < cant; i++)
        {
            if(strcmp(tel.c_str(), pSuscriptores[i].getTelefono()) == 0)
            {
                cout << endl;
                rlutil::setColor(rlutil::RED);
                cout << "El telefono ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << endl;
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro telefono: " << endl;
                rlutil::setColor(rlutil::WHITE);
                tel = cargarCadena();
                telValido = false;
                break;
            }
        }
    }
    while(!telValido);
    return tel;
}
