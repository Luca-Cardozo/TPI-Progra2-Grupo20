#include <iostream>
#include "ConsultasMenu.h"

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
    switch(opcion)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;
    case 10 :

        break;
    case 11:

        break;
    case 12:

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
    cout << "---------------" << endl;
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
