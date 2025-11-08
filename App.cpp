#include <iostream>
#include "App.h"
#include "rlutil.h"

using namespace std;

App::App()
{
    _cantidadOpciones = 12;
}
void App::run()
{
    int opcion;
    do
    {
        system("cls");
        opcion = seleccionOpcion();
        system("cls");
        ejecutarOpcion(opcion);
    }
    while(opcion != 0);
}

void App::mostrarOpciones()
{
    rlutil::setColor(rlutil::LIGHTGREEN);
    cout << "--------- MENU PRINCIPAL ---------" << endl;
    cout << "1- SUSCRIPTORES" << endl;
    cout << "2- PELICULAS" << endl;
    cout << "3- SERIES" << endl;
    cout << "4- GENEROS" << endl;
    cout << "5- CLASIFICACIONES" << endl;
    cout << "6- TIPOS DE SUSCRIPCION" << endl;
    cout << "7- TIPOS DE CONTENIDO" << endl;
    cout << "8- DIRECTORES" << endl;
    cout << "9- CONSUMOS" << endl;
    cout << "10- LISTADOS" << endl;
    cout << "11- CONSULTAS" << endl;
    cout << "12- REPORTES" << endl;
    cout << "----------------------------------" << endl;
    cout << "0- SALIR" << endl;
    rlutil::setColor(rlutil::WHITE);
}

int App::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    rlutil::setColor(rlutil::YELLOW);
    cout << "--------------------" << endl;
    cout << "SELECCIONE UNA OPCION: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> opcion;
    while(opcion < 0 || opcion > _cantidadOpciones)
    {
        rlutil::setColor(rlutil::RED);
        cout << "---------------" << endl;
        cout << "Opcion incorrecta... Vuelva a intentarlo por favor..." << endl;
        cout << "---------------" << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "SELECCIONE UNA OPCION: ";
        cin >> opcion;
        rlutil::setColor(rlutil::WHITE);
    }
    return opcion;
}

void App::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:
        _suscriptorMenu.mostrar();
        break;
    case 2:
        _peliculaMenu.mostrar();
        break;
    case 3:
        _serieMenu.mostrar();
        break;
    case 4:
        _generoMenu.mostrar();
        break;
    case 5:
        _clasificacionMenu.mostrar();
        break;
    case 6:
        _tipoSuscripcionMenu.mostrar();
        break;
    case 7:
        _tipoContenidoMenu.mostrar();
        break;
    case 8:
        _directorMenu.mostrar();
        break;
    case 9:
        _consumoMenu.mostrar();
        break;
    case 10:
        _listadosMenu.mostrar();
        break;
    case 11:
        _consultasMenu.mostrar();
        break;
    case 12:
        _reportesMenu.mostrar();
        break;
    case 0:
        rlutil::setColor(rlutil::LIGHTRED);
        cout << endl;
        cout << endl;
        cout << "GRACIAS POR UTILIZAR EL PROGRAMA!" << endl;
        rlutil::setColor(rlutil::WHITE);
        cout << endl;
        cout << endl;
        break;
    }
}
