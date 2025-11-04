#include "SuscriptorManager.h"
#include "Suscriptor.h"
#include "utils.h"
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool SuscriptorManager::cargarSuscriptor()
{
    cout << "-------- CARGA DE NUEVO SUSCRIPTOR --------" << endl;
    int carga;
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
    int id = _repoSuscriptor.getNuevoID();
    Suscriptor reg;
    Suscriptor *pSuscriptores;
    cout << "ID: #" << id << endl;
    reg.cargar();
    reg.setTipoSuscripcion(validarTipoSuscripcion(reg.getTipoSuscripcion()));
    int cantRegistros = _repoSuscriptor.getCantidadRegistros();
    pSuscriptores = new Suscriptor[cantRegistros];
    if(pSuscriptores == nullptr)
    {
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        system("pause");
        system("cls");
        return false;
    }
    _repoSuscriptor.leer(pSuscriptores, cantRegistros);
    reg.setEmail(validarEmail(pSuscriptores, cantRegistros, reg.getEmail()).c_str());
    reg.setTelefono(validarTelefono(pSuscriptores, cantRegistros, reg.getTelefono()).c_str());
    delete [] pSuscriptores;
    reg.setId(id);
    return _repoSuscriptor.guardar(reg);
}

bool SuscriptorManager::modificarSuscriptor()
{
    cout << "-------- ACTUALIZACION DE SUSCRIPTOR --------" << endl;
    int id;
    Suscriptor reg;
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
        reg = _repoSuscriptor.leer(id - 1);
        if(reg.getId() == -1)
        {
            cout << "No existe usuario registrado con ese ID... Vuelva a intentarlo..." << endl;
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
    Suscriptor *pSuscriptores;
    cout << "ID: #" << id << endl;
    reg.cargar();
    reg.setTipoSuscripcion(validarTipoSuscripcion(reg.getTipoSuscripcion()));
    int cantRegistros = _repoSuscriptor.getCantidadRegistros();
    pSuscriptores = new Suscriptor[cantRegistros];
    if(pSuscriptores == nullptr)
    {
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        system("pause");
        system("cls");
        return false;
    }
    _repoSuscriptor.leer(pSuscriptores, cantRegistros);
    reg.setEmail(validarEmail(pSuscriptores, cantRegistros, reg.getEmail()).c_str());
    reg.setTelefono(validarTelefono(pSuscriptores, cantRegistros, reg.getTelefono()).c_str());
    delete [] pSuscriptores;
    return _repoSuscriptor.guardar(id-1, reg);
}

bool SuscriptorManager::eliminarSuscriptor()
{
    cout << "-------- BAJA DE SUSCRIPTOR --------" << endl;
    int id;
    Suscriptor reg;
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
        reg = _repoSuscriptor.leer(id - 1);
        while(reg.getId() == -1)
        {
            cout << "No existe el suscriptor registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Baja cancelada..." << endl;
                return false;
            }
            reg = _repoSuscriptor.leer(id - 1);
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
    while(respuesta != 's' && respuesta != 'S');
    return _repoSuscriptor.eliminar(id - 1);
}

bool SuscriptorManager::altaSuscriptor()
{
    cout << "-------- ALTA DE SUSCRIPTOR --------" << endl;
    int id;
    Suscriptor reg;
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
        reg = _repoSuscriptor.leer(id - 1);
        while(reg.getId() == -1)
        {
            cout << "No existe el suscriptor registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a dar de alta (0 para cancelar el alta): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Alta cancelada..." << endl;
                return false;
            }
            reg = _repoSuscriptor.leer(id - 1);
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
    return _repoSuscriptor.alta(id - 1);
}

int SuscriptorManager::validarTipoSuscripcion(int id)
{
    while(_repoTipoSuscripcion.buscar(id) == -1)
    {
        system("cls");
        _listados.listarTiposSuscripcion();
        cout << endl;
        cout << "El ID ingresado para el tipo de suscripcion no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << "Ingrese alguno de los tipos de suscripcion disponibles por favor..." << endl;
        cout << "ID Tipo de Suscripcion: ";
        cin >> id;
    }
    return id;
}

string SuscriptorManager::validarEmail(Suscriptor* pSuscriptores,  int cant, const char* e)
{
    string email = e;
    bool mailValido;
    do
    {
        mailValido = true;
        for(int i = 0; i < cant; i++)
        {
            if(strcasecmp(email.c_str(), pSuscriptores[i].getEmail()) == 0)
            {
                cout << "El email ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << "Ingrese otro email: " << endl;
                email = cargarCadena();
                mailValido = false;
                break;
            }
        }
    }
    while(!mailValido);
    return email;
}

string SuscriptorManager::validarTelefono(Suscriptor* pSuscriptores,  int cant, const char* t)
{
    string tel = t;
    bool telValido;
    do
    {
        telValido = true;
        for(int i = 0; i < (int)tel.length(); i++)
        {
            if(!isdigit(tel[i]))
            {
                cout << "El telefono solo puede contener numeros... Intente cargar la informacion nuevamente..." << endl;
                cout << "Ingrese otro telefono: " << endl;
                tel = cargarCadena();
                telValido = false;
                break;
            }
        }
        for(int i = 0; i < cant; i++)
        {
            if(strcmp(tel.c_str(), pSuscriptores[i].getTelefono()) == 0)
            {
                cout << "El telefono ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << "Ingrese otro telefono: " << endl;
                tel = cargarCadena();
                telValido = false;
                break;
            }
        }
    }
    while(!telValido);
    return tel;
}
