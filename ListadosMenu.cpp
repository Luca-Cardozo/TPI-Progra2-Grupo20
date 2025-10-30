#include <iostream>
#include "ListadosMenu.h"

using namespace std;

ListadosMenu::ListadosMenu()
{
    _cantidadOpciones = 10;
}

void ListadosMenu::mostrar()
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


void ListadosMenu::mostrarOpciones()
{
    cout << "------------------ MENU LISTADOS ------------------" << endl;
    cout << "1 - SUSCRIPTORES ORDENADOS POR APELLIDO" << endl;
    cout << "2 - SUSCRIPTORES ORDENADOS POR FECHA DE ALTA" << endl;
    cout << "3 - PELICULAS ORDENADAS POR TITULO" << endl;
    cout << "4 - PELICULAS ORDENADAS POR FECHA DE ESTRENO" << endl;
    cout << "5 - PELICULAS ORDENADAS POR DURACION" << endl;
    cout << "6 - SERIES ORDENADAS POR TITULO" << endl;
    cout << "7 - SERIES ORDENADAS POR FECHA DE ESTRENO" << endl;
    cout << "8 - SERIES ORDENADAS POR CAPITULOS" << endl;
    cout << "9 - DIRECTORES ORDENADOS POR APELLIDO" << endl;
    cout << "10 - CONSUMOS ORDENADOS POR FECHA DE ACCESO" << endl;
    cout << "11 - CONSUMOS ORDENADOS POR ID DE SUSCRIPTOR" << endl;
    cout << "12 - GENEROS DISPONIBLES" << endl;
    cout << "13 - CLASIFICACIONES DISPONIBLES" << endl;
    cout << "14 - TIPOS DE CONTENIDO DISPONIBLES" << endl;
    cout << "15 - TIPOS DE SUSCRIPCIONES DISPONIBLES" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------------------------------------" << endl;
}

void ListadosMenu::ejecutarOpcion(int opcion)
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
    case 15:

        break;
    }
}


int ListadosMenu::seleccionOpcion()
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
