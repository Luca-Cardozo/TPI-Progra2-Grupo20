#include <iostream>
#include "ConsultasMenu.h"
#include "utils.h"

using namespace std;

ConsultasMenu::ConsultasMenu()
{
    _cantidadOpciones = 14;
}

void ConsultasMenu::mostrar()
{
    int opcion;
    do
    {
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
        system("pause");
    }
    while(opcion != 0);
}


void ConsultasMenu::mostrarOpciones()
{
    cout << "------------------- MENU CONSULTAS -------------------" << endl;
    cout << "1 - CONSULTAR SUSCRIPTOR POR EMAIL" << endl;
    cout << "2 - CONSULTAR SUSCRIPTOR POR TELEFONO" << endl;
    cout << "3 - CONSULTAR SUSCRIPTORES POR TIPO DE SUSCRIPCION" << endl;
    cout << "4 - CONSULTAR PELICULA POR TITULO" << endl;
    cout << "5 - CONSULTAR PELICULAS POR DIRECTOR" << endl;
    cout << "6 - CONSULTAR PELICULAS POR GENERO" << endl;
    cout << "7 - CONSULTAR PELICULAS POR CLASIFICACION" << endl;
    cout << "8 - CONSULTAR SERIE POR TITULO" << endl;
    cout << "9 - CONSULTAR SERIES POR DIRECTOR" << endl;
    cout << "10 - CONSULTAR SERIES POR GENERO" << endl;
    cout << "11 - CONSULTAR SERIES POR CLASIFICACION" << endl;
    cout << "12 - CONSULTAR DIRECTOR POR NOMBRE Y APELLIDO" << endl;
    cout << "13 - CONSULTAR CONSUMOS POR SUSCRIPTOR" << endl;
    cout << "14 - CONSULTAR CONSUMOS POR CONTENIDO" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "------------------------------------------------------" << endl;
}

void ConsultasMenu::ejecutarOpcion(int opcion)
{
    std::string email, tel, tit, nom, ape;
    int id;
    switch(opcion)
    {
    case 1:
        cout << "Ingrese un email: " << endl;
        cin >> email;
        _consultasManager.consultarSuscriptorEmail(email.c_str());
        break;
    case 2:
        cout << "Ingrese un telefono: " << endl;
        cin >> tel;
        _consultasManager.consultarSuscriptorTelefono(tel.c_str());
        break;
    case 3:
        do
        {
            system("cls");
            _listadosManager.listarTiposSuscripcion();
            cout << endl;
            cout << "Ingrese un ID de la lista o 0 para salir: " << endl;
            cin >> id;
            if(id > _repoTipoSuscripcion.getCantidadRegistros() || id < 0)
            {
                cout << "No existe el ID ingresado..." << endl;
                system("pause");
            }
            else if(id != 0)
            {
                _consultasManager.consultarSuscriptorTipoSuscripcion(id);
                break;
            }
        }
        while(id != 0);
        break;
    case 4:
        cout << "Ingrese un titulo: " << endl;
        tit = cargarCadena();
        _consultasManager.consultarPeliculaTitulo(tit.c_str());
        break;
    case 5:
        do
        {
            system("cls");
            _listadosManager.listarDirectoresApellido();
            cout << endl;
            cout << "Ingrese un ID de la lista o 0 para salir: " << endl;
            cin >> id;
            if(id > _repoDirector.getCantidadRegistros() || id < 0)
            {
                cout << "No existe el ID ingresado..." << endl;
                system("pause");
            }
            else if(id != 0)
            {
                _consultasManager.consultarPeliculaDirector(id);
                break;
            }
        }
        while(id != 0);
        break;
    case 6:
        do
        {
            system("cls");
            _listadosManager.listarGeneros();
            cout << endl;
            cout << "Ingrese un ID de la lista o 0 para salir: " << endl;
            cin >> id;
            if(id > _repoGenero.getCantidadRegistros() || id < 0)
            {
                cout << "No existe el ID ingresado..." << endl;
                system("pause");
            }
            else if(id != 0)
            {
                _consultasManager.consultarPeliculaGenero(id);
                break;
            }
        }
        while(id != 0);
        break;
    case 7:
        do
        {
            system("cls");
            _listadosManager.listarClasificaciones();
            cout << endl;
            cout << "Ingrese un ID de la lista o 0 para salir: " << endl;
            cin >> id;
            if(id > _repoClasificacion.getCantidadRegistros() || id < 0)
            {
                cout << "No existe el ID ingresado..." << endl;
                system("pause");
            }
            else if(id != 0)
            {
                _consultasManager.consultarPeliculaClasificacion(id);
                break;
            }
        }
        while(id != 0);
        break;
    case 8:
        cout << "Ingrese un titulo: " << endl;
        tit = cargarCadena();
        _consultasManager.consultarSerieTitulo(tit.c_str());
        break;
    case 9:
        do
        {
            system("cls");
            _listadosManager.listarDirectoresApellido();
            cout << endl;
            cout << "Ingrese un ID de la lista o 0 para salir: " << endl;
            cin >> id;
            if(id > _repoDirector.getCantidadRegistros() || id < 0)
            {
                cout << "No existe el ID ingresado..." << endl;
                system("pause");
            }
            else if(id != 0)
            {
                _consultasManager.consultarSerieDirector(id);
                break;
            }
        }
        while(id != 0);
        break;
    case 10 :
        do
        {
            system("cls");
            _listadosManager.listarGeneros();
            cout << endl;
            cout << "Ingrese un ID de la lista o 0 para salir: " << endl;
            cin >> id;
            if(id > _repoGenero.getCantidadRegistros() || id < 0)
            {
                cout << "No existe el ID ingresado..." << endl;
                system("pause");
            }
            else if(id != 0)
            {
                _consultasManager.consultarSerieGenero(id);
                break;
            }
        }
        while(id != 0);
        break;
    case 11:
        do
        {
            system("cls");
            _listadosManager.listarClasificaciones();
            cout << endl;
            cout << "Ingrese un ID de la lista o 0 para salir: " << endl;
            cin >> id;
            if(id > _repoClasificacion.getCantidadRegistros() || id < 0)
            {
                cout << "No existe el ID ingresado..." << endl;
                system("pause");
            }
            else if(id != 0)
            {
                _consultasManager.consultarSerieClasificacion(id);
                break;
            }
        }
        while(id != 0);
        break;
    case 12:
        cout << "Ingrese un nombre: " << endl;
        nom = cargarCadena();
        cout << "Ingrese un apellido: " << endl;
        ape = cargarCadena();
        _consultasManager.consultarDirectorNombreApellido(nom.c_str(), ape.c_str());
        break;
    case 13:

        break;
    case 14:

        break;
    }
}


int ConsultasMenu::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    cout << "------------------------------------------------------" << endl;
    cout << "SELECCIONE UNA OPCION: ";
    cin >> opcion;
    while(opcion < 0 || opcion > _cantidadOpciones)
    {
        cout << "---------------" << endl;
        cout << "Opcion incorrecta... Vuelva a intentarlo por favor..." << endl;
        cout << "---------------" << endl;
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
    }
    return opcion;
}
