#include "SerieManager.h"
#include "Serie.h"
#include "utils.h"
#include "rlutil.h"
#include <iostream>
#include <cstring>

using namespace std;

bool SerieManager::cargarSerie()
{
    int cantRegistros, id;
    Serie reg;
    Serie *pSeries;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- CARGA DE NUEVA SERIE --------" << endl;

    cout << endl;
    if (deseaCancelar()) return false;

    id = _repoSerie.getNuevoID();
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "ID: #" << id << endl;

    reg.cargar();

    cantRegistros = _repoSerie.getCantidadRegistros();
    pSeries = new Serie[cantRegistros];
    if(pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoSerie.leer(pSeries, cantRegistros);

    reg.setId(id);
    reg.setIdTipoContenido(2);
    reg.setTitulo(validarTitulo(pSeries, cantRegistros, reg.getTitulo()).c_str());
    reg.setIdDirector(validarDirector(reg.getIdDirector()));
    reg.setGenero(validarGenero(reg.getGenero()));
    reg.setClasificacion(validarClasificacion(reg.getClasificacion()));

    delete [] pSeries;
    return _repoSerie.guardar(reg);
}

bool SerieManager::modificarSerie()
{
    int id, cantRegistros;
    Serie reg;
    Serie *pSeries;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ACTUALIZACION DE SERIE --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoSerie.leer(id - 1);
        while(reg.getId() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe una serie registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarSeriesTitulo();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a modificar (0 para anular la modificacion): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoSerie.leer(id - 1);
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

    cantRegistros = _repoSerie.getCantidadRegistros();
    pSeries = new Serie[cantRegistros];
    if(pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Error en la asignacion de memoria dinamica... No se pudo guardar el registro..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        return false;
    }
    _repoSerie.leer(pSeries, cantRegistros);

    reg.setTitulo(validarTitulo(pSeries, cantRegistros, reg.getTitulo(), reg.getId()).c_str());
    reg.setIdDirector(validarDirector(reg.getIdDirector()));
    reg.setGenero(validarGenero(reg.getGenero()));
    reg.setClasificacion(validarClasificacion(reg.getClasificacion()));

    delete [] pSeries;
    return _repoSerie.guardar(id-1, reg);
}

bool SerieManager::eliminarSerie()
{
    int id;
    Serie reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- BAJA DE SERIE --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoSerie.leer(id - 1);
        while(reg.getId() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe una serie registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarSeriesTitulo();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a eliminar (0 para anular la baja): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoSerie.leer(id - 1);
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

    return _repoSerie.eliminar(id - 1);
}

bool SerieManager::altaSerie()
{
    int id;
    Serie reg;

    rlutil::setColor(rlutil::LIGHTRED);
    cout << "-------- ALTA DE SERIE --------" << endl;
    while(true)
    {
        cout << endl;
        if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
        id = validarPositivo(id);
        reg = _repoSerie.leer(id - 1);
        while(reg.getId() == 0)
        {
            rlutil::setColor(rlutil::RED);
            cout << endl;
            cout << "No existe serie registrada con ese ID... Vuelva a intentarlo..." << endl;
            cout << endl;
            rlutil::setColor(rlutil::WHITE);
            system("pause");
            system("cls");
            _listados.listarSeriesTitulo();
            cout << endl;
            if (pedirIdConCancelacion("Ingrese ID del registro a dar de alta (0 para anular el alta): ", id)) return false;
            id = validarPositivo(id);
            reg = _repoSerie.leer(id - 1);
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

    return _repoSerie.alta(id - 1);
}

int SerieManager::validarDirector(int id)
{
    char respuesta;
    while(_repoDirector.buscar(id) == -1)
    {
        cout << endl;
        rlutil::setColor(rlutil::RED);
        cout << "El ID ingresado para el director no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        system("pause");
        system("cls");
        _listados.listarDirectoresApellido();
        rlutil::setColor(rlutil::CYAN);
        cout << "Elija un director disponible por favor..." << endl;
        cout << "ID Director: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> id;
        id = validarPositivo(id);
    }
    while(true)
    {
        Director aux = _repoDirector.leer(id - 1);
        if(aux.getEliminado())
        {
            rlutil::setColor(rlutil::BROWN);
            cout << endl;
            cout << "El director se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                rlutil::setColor(rlutil::RED);
                cout << endl;
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                rlutil::setColor(rlutil::BROWN);
                cout << endl;
                cout << "El director se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
                rlutil::setColor(rlutil::WHITE);
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoDirector.guardar(aux.getId() - 1, aux);
                cout << endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "Director reactivado correctamente" << endl;
                rlutil::setColor(rlutil::WHITE);
                break;
            }
            else
            {
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro ID de director: ";
                rlutil::setColor(rlutil::WHITE);
                cin >> id;
                id = validarPositivo(id);
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
        cout << endl;
        rlutil::setColor(rlutil::RED);
        cout << "El ID ingresado para el genero no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        system("pause");
        system("cls");
        _listados.listarGeneros();
        rlutil::setColor(rlutil::CYAN);
        cout << "Elija un genero disponible por favor..." << endl;
        cout << "ID Genero: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> id;
        id = validarPositivo(id);
    }
    while(true)
    {
        Genero aux = _repoGenero.leer(id - 1);
        if(aux.getEliminado())
        {
            rlutil::setColor(rlutil::BROWN);
            cout << endl;
            cout << "El genero se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                rlutil::setColor(rlutil::RED);
                cout << endl;
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                rlutil::setColor(rlutil::BROWN);
                cout << endl;
                cout << "El genero se encuentra dado de baja... Desea darlo de alta? (S/N)" << endl;
                rlutil::setColor(rlutil::WHITE);
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoGenero.guardar(aux.getIdGenero() - 1, aux);
                cout << endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "Genero reactivado correctamente" << endl;
                rlutil::setColor(rlutil::WHITE);
                break;
            }
            else
            {
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro ID de genero: ";
                rlutil::setColor(rlutil::WHITE);
                cin >> id;
                id = validarPositivo(id);
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
        cout << endl;
        rlutil::setColor(rlutil::RED);
        cout << "El ID ingresado para la clasificacion no existe... Intente cargar la informacion nuevamente..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        system("pause");
        system("cls");
        _listados.listarClasificaciones();
        rlutil::setColor(rlutil::CYAN);
        cout << "Elija una clasificacion disponible por favor..." << endl;
        cout << "ID Clasificacion: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> id;
        id = validarPositivo(id);
    }
    while(true)
    {
        Clasificacion aux = _repoClasificacion.leer(id - 1);
        if(aux.getEliminado())
        {
            rlutil::setColor(rlutil::BROWN);
            cout << endl;
            cout << "La clasificacion se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
            rlutil::setColor(rlutil::WHITE);
            cin >> respuesta;
            while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
            {
                rlutil::setColor(rlutil::RED);
                cout << endl;
                cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
                rlutil::setColor(rlutil::BROWN);
                cout << endl;
                cout << "La clasificacion se encuentra dada de baja... Desea darla de alta? (S/N)" << endl;
                rlutil::setColor(rlutil::WHITE);
                cin >> respuesta;
            }
            if(respuesta == 'S' || respuesta == 's')
            {
                aux.setEliminado(false);
                _repoClasificacion.guardar(aux.getIdClasificacion() - 1, aux);
                cout << endl;
                rlutil::setColor(rlutil::GREEN);
                cout << "Clasificacion reactivada correctamente" << endl;
                rlutil::setColor(rlutil::WHITE);
                break;
            }
            else
            {
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro ID de clasificacion: ";
                rlutil::setColor(rlutil::WHITE);
                cin >> id;
                id = validarPositivo(id);
            }
        }
        else break;
    }
    return id;
}

string SerieManager::validarTitulo(Serie* pSeries,  int cant, const char* t, int idActual)
{
    string tit = t;
    bool titValido;
    do
    {
        titValido = true;
        for(int i = 0; i < cant; i++)
        {
            if (pSeries[i].getId() == idActual) continue;

            if(strcasecmp(tit.c_str(), pSeries[i].getTitulo()) == 0)
            {
                cout << endl;
                rlutil::setColor(rlutil::RED);
                cout << "El titulo ingresado ya existe... Intente cargar la informacion nuevamente..." << endl;
                cout << endl;
                rlutil::setColor(rlutil::CYAN);
                cout << "Ingrese otro titulo: " << endl;
                rlutil::setColor(rlutil::WHITE);
                tit = cargarCadena();
                titValido = false;
                break;
            }
        }
    }
    while(!titValido);
    return tit;
}
