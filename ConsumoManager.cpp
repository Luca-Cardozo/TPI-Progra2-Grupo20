#include "ConsumoManager.h"
#include "Consumo.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>

using namespace std;

bool ConsumoManager::cargarConsumo()
{
    int id, idSus, idCont, idTipoCont;
    Consumo reg;
    Fecha fechaConsumo;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- CARGA DE NUEVO CONSUMO --------" << endl;

    cout << endl;
    if (deseaCancelar()) return false;

    id = _repoConsumo.getNuevoID();
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "ID: #" << id << endl;

    reg.cargar();

    reg.setIdAcceso(id);
    reg.setIdSuscriptor(validarSuscriptor(reg.getIdSuscriptor()));

    if(reg.getIdTipoContenido() == 1)
    {
        reg.setIdContenido(validarPelicula(reg.getIdContenido()));
        reg.setDuracionVista(validarDuracion(reg.getIdContenido(), reg.getDuracionVista()));
    }
    else if(reg.getIdTipoContenido() == 2)
    {
        reg.setIdContenido(validarSerie(reg.getIdContenido()));
    }

    fechaConsumo = reg.getFechaAcceso();
    idSus = reg.getIdSuscriptor();
    idCont = reg.getIdContenido();
    idTipoCont = reg.getIdTipoContenido();
    validarFechaAltaConsumo(fechaConsumo, idSus, idCont, idTipoCont);
    reg.setFechaAcceso(fechaConsumo);

    if (existeConsumoDuplicado(reg))
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Ya existe un consumo con los mismos datos (suscriptor, contenido, tipo, fecha, hora y duracion)..." << endl;
        cout << "No se puede registrar el mismo consumo dos veces..." << endl;
        cout << "Carga anulada..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }

    return _repoConsumo.guardar(reg);
}

bool ConsumoManager::modificarConsumo()
{
    int id, pos, idSus, idCont, idTipoCont;
    Consumo reg;
    Fecha fechaConsumo;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ACTUALIZACION DE CONSUMO --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoConsumo.leer(id - 1);
        while(reg.getIdAcceso() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un consumo registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarConsumosIdSuscriptor();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoConsumo.leer(id - 1);
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

    reg.setIdSuscriptor(validarSuscriptor(reg.getIdSuscriptor()));

    if(reg.getIdTipoContenido() == 1)
    {
        reg.setIdContenido(validarPelicula(reg.getIdContenido()));
        reg.setDuracionVista(validarDuracion(reg.getIdContenido(), reg.getDuracionVista()));
    }
    else if(reg.getIdTipoContenido() == 2)
    {
        reg.setIdContenido(validarSerie(reg.getIdContenido()));
    }

    fechaConsumo = reg.getFechaAcceso();
    idSus = reg.getIdSuscriptor();
    idCont = reg.getIdContenido();
    idTipoCont = reg.getIdTipoContenido();
    validarFechaAltaConsumo(fechaConsumo, idSus, idCont, idTipoCont);
    reg.setFechaAcceso(fechaConsumo);

    pos = id - 1;

    if (existeConsumoDuplicado(pos, reg))
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "No se puede modificar el consumo, ya existe otro registro con los mismos datos..." << endl;
        cout << "Modificacion anulada..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }

    return _repoConsumo.guardar(id-1, reg);
}

bool ConsumoManager::eliminarConsumo()
{
    int id;
    Consumo reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- BAJA DE CONSUMO --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoConsumo.leer(id - 1);
        while(reg.getIdAcceso() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe un consumo registrad con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarConsumosIdSuscriptor();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoConsumo.leer(id - 1);
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

    return _repoConsumo.eliminar(id - 1);
}

bool ConsumoManager::altaConsumo()
{
    int id;
    Consumo reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ALTA DE CONSUMO --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoConsumo.leer(id - 1);
        while(reg.getIdAcceso() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe consumo registrado con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarConsumosIdSuscriptor();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoConsumo.leer(id - 1);
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

    return _repoConsumo.alta(id - 1);
}

int ConsumoManager::validarSuscriptor(int id)
{
    char respuesta;
    while(_repoSuscriptor.buscar(id) == -1)
    {
        cout << endl;
        rlutil::setColor(rlutil::RED);
        cout << "El ID ingresado para el suscriptor no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        system("pause");
        system("cls");
        _listados.listarSuscriptoresApellido();
        rlutil::setColor(rlutil::CYAN);
        cout << "Elija un suscriptor disponible por favor..." << endl;
        cout << "ID Suscriptor: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> id;
        id = validarPositivo(id);
    }
    while(true)
    {
        Suscriptor aux = _repoSuscriptor.leer(id - 1);
        if(aux.getEliminado())
        {
            rlutil::setColor(rlutil::BROWN);
            cout << endl;
            cout << "El suscriptor se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                rlutil::setColor(rlutil::RED);
                cout << endl;
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                rlutil::setColor(rlutil::BROWN);
                cout << endl;
                cout << "El suscriptor se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
                rlutil::setColor(rlutil::WHITE);
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoSuscriptor.guardar(aux.getId() - 1, aux);
                cout << endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "Suscriptor reactivado correctamente" << endl;
                rlutil::setColor(rlutil::WHITE);
                break;
            }
            else
            {
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro ID de suscriptor: ";
                rlutil::setColor(rlutil::WHITE);
                cin >> id;
                id = validarPositivo(id);
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
        cout << endl;
        rlutil::setColor(rlutil::RED);
        cout << "El ID ingresado para la pelicula no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        system("pause");
        system("cls");
        _listados.listarPeliculasTitulo();
        rlutil::setColor(rlutil::CYAN);
        cout << "Elija una pelicula disponible por favor..." << endl;
        cout << "ID Pelicula: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> id;
        id = validarPositivo(id);
    }
    while(true)
    {
        Pelicula aux = _repoPelicula.leer(id - 1);
        if(aux.getEliminado())
        {
            rlutil::setColor(rlutil::BROWN);
            cout << endl;
            cout << "La pelicula se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                rlutil::setColor(rlutil::RED);
                cout << endl;
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                rlutil::setColor(rlutil::BROWN);
                cout << endl;
                cout << "La pelicula se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
                rlutil::setColor(rlutil::WHITE);
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoPelicula.guardar(aux.getId() - 1, aux);
                cout << endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "Pelicula reactivada correctamente" << endl;
                rlutil::setColor(rlutil::WHITE);
                break;
            }
            else
            {
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro ID de pelicula: ";
                rlutil::setColor(rlutil::WHITE);
                cin >> id;
                id = validarPositivo(id);
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
        cout << endl;
        rlutil::setColor(rlutil::RED);
        cout << "El ID ingresado para la serie no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        system("pause");
        system("cls");
        _listados.listarSeriesTitulo();
        rlutil::setColor(rlutil::CYAN);
        cout << "Elija una serie disponible por favor..." << endl;
        cout << "ID Serie: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> id;
        id = validarPositivo(id);
    }
    while(true)
    {
        Serie aux = _repoSerie.leer(id - 1);
        if(aux.getEliminado())
        {
            rlutil::setColor(rlutil::BROWN);
            cout << endl;
            cout << "La serie se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                rlutil::setColor(rlutil::RED);
                cout << endl;
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                rlutil::setColor(rlutil::BROWN);
                cout << endl;
                cout << "La serie se encuentra dado de baja... Desea darla de alta? (S/N)" << endl;
                rlutil::setColor(rlutil::WHITE);
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoSerie.guardar(aux.getId() - 1, aux);
                cout << endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "Serie reactivada correctamente" << endl;
                rlutil::setColor(rlutil::WHITE);
                break;
            }
            else
            {
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro ID de serie: ";
                rlutil::setColor(rlutil::WHITE);
                cin >> id;
                id = validarPositivo(id);
            }
        }
        else break;
    }
    return id;
}

int ConsumoManager::validarDuracion(int id, int dv)
{
    Pelicula reg = _repoPelicula.leer(id - 1);
    while(dv > reg.getDuracion() || dv < 0)
    {
        if(dv > reg.getDuracion())
        {
            cout << endl;
            rlutil::setColor(rlutil::RED);
            cout << "La duracion vista excede al total de la pelicula... Intente cargar la informacion nuevamente..." << endl;
            rlutil::setColor(rlutil::BROWN);
            cout << "La duracion total de la pelicula es " << reg.getDuracion() << " minutos" << endl;
            rlutil::setColor(rlutil::WHITE);
        }
        else if(dv < 0)
        {
            cout << endl;
            rlutil::setColor(rlutil::RED);
            cout << "La duracion vista debe ser positiva.. Intente cargar la informacion nuevamente..." << endl;
            rlutil::setColor(rlutil::WHITE);
        }
        rlutil::setColor(rlutil::CYAN);
        cout << "Duracion vista (en minutos): ";
        rlutil::setColor(rlutil::WHITE);
        cin >> dv;
    }
    return dv;
}

void ConsumoManager::validarFechaAltaConsumo(Fecha &fechaConsumo, int idSuscriptor, int idContenido, int idTipoContenido)
{
    Suscriptor sus = _repoSuscriptor.leer(idSuscriptor - 1);
    Fecha fechaSuscriptor = sus.getFechaAlta();
    Fecha fechaContenido;
    if(idTipoContenido == 1)
    {
        Pelicula peli = _repoPelicula.leer(idContenido - 1);
        fechaContenido = peli.getFechaAlta();
    }
    else if(idTipoContenido == 2)
    {
        Serie serie = _repoSerie.leer(idContenido - 1);
        fechaContenido = serie.getFechaAlta();
    }
    while(fechaConsumo < fechaSuscriptor || fechaConsumo < fechaContenido)
    {
        cout << endl;
        rlutil::setColor(rlutil::RED);
        cout << "La fecha del consumo debe ser mayor o igual a las fechas de alta del suscriptor y del contenido..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::BROWN);
        cout << "Fecha de alta del suscriptor: ";
        rlutil::setColor(rlutil::YELLOW);
        fechaSuscriptor.mostrar();
        cout << endl;
        rlutil::setColor(rlutil::BROWN);
        cout << "Fecha de alta del contenido: ";
        rlutil::setColor(rlutil::YELLOW);
        fechaContenido.mostrar();
        rlutil::setColor(rlutil::CYAN);
        cout << endl;
        cout << "Intentelo nuevamente..." << endl;
        cout << "Ingrese fecha de consumo: " << endl;
        rlutil::setColor(rlutil::WHITE);
        fechaConsumo.cargar();
    }
}

bool ConsumoManager::existeConsumoDuplicado(Consumo nuevo)
{
    int cantRegistros = _repoConsumo.getCantidadRegistros();
    for (int i = 0; i < cantRegistros; i++)
    {
        Consumo reg = _repoConsumo.leer(i);

        if (    reg.getIdSuscriptor() == nuevo.getIdSuscriptor() &&
                reg.getIdContenido() == nuevo.getIdContenido() &&
                reg.getIdTipoContenido() == nuevo.getIdTipoContenido() &&
                reg.getFechaAcceso() == nuevo.getFechaAcceso() &&
                reg.getHoraAcceso() == nuevo.getHoraAcceso() &&
                reg.getDuracionVista() == nuevo.getDuracionVista()
           )
        {
            return true;
        }
    }
    return false;
}

bool ConsumoManager::existeConsumoDuplicado(int pos, Consumo nuevo)
{
    int cantRegistros = _repoConsumo.getCantidadRegistros();
    for (int i = 0; i < cantRegistros; i++)
    {
        if (i == pos) continue;

        Consumo reg = _repoConsumo.leer(i);

        if (    reg.getIdSuscriptor() == nuevo.getIdSuscriptor() &&
                reg.getIdContenido() == nuevo.getIdContenido() &&
                reg.getIdTipoContenido() == nuevo.getIdTipoContenido() &&
                reg.getFechaAcceso() == nuevo.getFechaAcceso() &&
                reg.getHoraAcceso() == nuevo.getHoraAcceso() &&
                reg.getDuracionVista() == nuevo.getDuracionVista()
           )
        {
            return true;
        }
    }
    return false;
}
