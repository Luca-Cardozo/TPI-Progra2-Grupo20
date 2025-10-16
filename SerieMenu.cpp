#include <iostream>
#include "SerieMenu.h"

using namespace std;

SerieMenu::SerieMenu()
{
    _cantidadOpciones = 5;
}

void SerieMenu::mostrar()
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


void SerieMenu::mostrarOpciones()
{
    cout << "--- MENU SERIES ---" << endl;
    cout << "1 - ALTA SERIE" << endl;
    cout << "2 - MODIFICAR SERIE" << endl;
    cout << "3 - ELIMINAR SERIE" << endl;
    cout << "4 - CONSULTAR SERIES" << endl;
    cout << "5 - LISTAR SERIES" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void SerieMenu::ejecutarOpcion(int opcion)
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
    }
}


int SerieMenu::seleccionOpcion()
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
