#include "ConsumoManager.h"
#include "Consumo.h"
#include <iostream>

using namespace std;

bool ConsumoManager::cargarConsumo()
{
    cout << "-------- CARGA DE NUEVO CONSUMO --------" << endl;
    int carga;
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
    int id = _repoConsumo.getNuevoID();
    Consumo reg;
    cout << "ID: #" << id << endl;
    reg.cargar();
    reg.setIdSuscriptor(validarSuscriptor(reg.getIdSuscriptor()));
    if(reg.getIdContenido() >= 1001 && reg.getIdContenido() <= 2000)
    {
        reg.setIdContenido(validarPelicula(reg.getIdContenido()));
        reg.setDuracionVista(validarDuracion(reg.getIdContenido(), reg.getDuracionVista()));
    }
    else if(reg.getIdContenido() >= 2001 && reg.getIdContenido() <= 3000)
    {
        reg.setIdContenido(validarSerie(reg.getIdContenido()));
    }
    reg.setIdAcceso(id);
    cout << "Ingrese 0 si desea anular la carga o cualquier numero para continuar" << endl;
    cin >> carga;
    if(carga == 0)
    {
        cout << "Carga anulada..." << endl;
        return false;
    }
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
        cout << "Ingrese ID del registro a actualizar (0 para anular la actualizacion): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Modificacion anulada..." << endl;
            return false;
        }
        reg = _repoConsumo.leer(id - 1);
        while(reg.getIdAcceso() == -1)
        {
            cout << "No existe el consumo registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a actualizar (0 para anular la actualizacion): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Modificacion anulada..." << endl;
                return false;
            }
            reg = _repoConsumo.leer(id - 1);
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
    cout << "ID: #" << id << endl;
    reg.cargar();
    reg.setIdSuscriptor(validarSuscriptor(reg.getIdSuscriptor()));
    if(reg.getIdContenido() >= 1001 && reg.getIdContenido() <= 2000)
    {
        reg.setIdContenido(validarPelicula(reg.getIdContenido()));
        reg.setDuracionVista(validarDuracion(reg.getIdContenido(), reg.getDuracionVista()));
    }
    else if(reg.getIdContenido() >= 2001 && reg.getIdContenido() <= 3000)
    {
        reg.setIdContenido(validarSerie(reg.getIdContenido()));
    }
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
        cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
        cin >> id;
        if(id == 0)
        {
            cout << "Baja cancelada..." << endl;
            return false;
        }
        reg = _repoConsumo.leer(id - 1);
        while(reg.getIdAcceso() == -1)
        {
            cout << "No existe el consumo registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a eliminar (0 para cancelar la baja): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Baja cancelada..." << endl;
                return false;
            }
            reg = _repoConsumo.leer(id - 1);
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
    return _repoConsumo.eliminar(id - 1);
}

bool ConsumoManager::altaConsumo()
{
    cout << "-------- ALTA DE CONSUMO --------" << endl;
    int id;
    Consumo reg;
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
        reg = _repoConsumo.leer(id - 1);
        while(reg.getIdAcceso() == -1)
        {
            cout << "No existe el consumo registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << "Ingrese ID del registro a dar de alta (0 para cancelar el alta): " << endl;
            cin >> id;
            if(id == 0)
            {
                cout << "Alta cancelada..." << endl;
                return false;
            }
            reg = _repoConsumo.leer(id - 1);
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
    return _repoConsumo.alta(id - 1);
}


int ConsumoManager::validarSuscriptor(int id)
{
    char respuesta;
    while(_repoSuscriptor.buscar(id) == -1)
    {
        cout << "El ID ingresado para el suscriptor no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << "ID Suscriptor: ";
        cin >> id;
    }
    while(true)
    {
        Suscriptor aux = _repoSuscriptor.leer(id - 1);
        if(aux.getEliminado())
        {
            cout << "El suscriptor se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                cout << "El suscriptor se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoSuscriptor.guardar(aux.getId() - 1, aux);
                cout << "Suscriptor reactivado correctamente" << endl;
                break;
            }
            else
            {
                cout << "Ingrese otro ID de suscriptor: ";
                cin >> id;
            }
        }
        else break;
    }
    return id;
}

int ConsumoManager::validarPelicula(int id)
{
    char respuesta;
    while(_repoPelicula.buscar(id) == -1)
    {
        cout << "El ID ingresado para la pelicula no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << "ID Contenido: ";
        cin >> id;
    }
    while(true)
    {
        Pelicula aux = _repoPelicula.leer(id - 1001);
        if(aux.getEliminado())
        {
            cout << "La pelicula se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                cout << "La pelicula se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoPelicula.guardar(aux.getId() - 1, aux);
                cout << "Pelicula reactivada correctamente" << endl;
                break;
            }
            else
            {
                cout << "Ingrese otro ID de pelicula: ";
                cin >> id;
            }
        }
        else break;
    }
    return id;
}

int ConsumoManager::validarSerie(int id)
{
    char respuesta;
    while(_repoSerie.buscar(id) == -1)
    {
        cout << "El ID ingresado para la serie no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << "ID Contenido: ";
        cin >> id;
    }
    while(true)
    {
        Serie aux = _repoSerie.leer(id - 2001);
        if(aux.getEliminado())
        {
            cout << "La serie se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                cout << "La serie se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoSerie.guardar(aux.getId() - 1, aux);
                cout << "Serie reactivada correctamente" << endl;
                break;
            }
            else
            {
                cout << "Ingrese otro ID de serie: ";
                cin >> id;
            }
        }
        else break;
    }
    return id;
}

int ConsumoManager::validarDuracion(int id, int dv)
{
    Pelicula reg = _repoPelicula.leer(id - 1);
    while(dv > reg.getDuracion())
    {
        cout << "La duracion vista excede al total de la pelicula... Intente cargar la informacion nuevamente..." << endl;
        cout << "La duracion total de la pelicula es " << reg.getDuracion() << " minutos" << endl;
        cout << "Duracion vista (en minutos): ";
        cin >> dv;
    }
    return dv;
}
