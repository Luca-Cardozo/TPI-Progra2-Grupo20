#include <iostream>
#include "ReportesMenu.h"

using namespace std;

ReportesMenu::ReportesMenu()
{
    _cantidadOpciones = 10;
}

void ReportesMenu::mostrar()
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


void ReportesMenu::mostrarOpciones()
{
    cout << "--- MENU REPORTES ---" << endl;
    cout << "1 - REPORTE 1" << endl;
    cout << "2 - REPORTE 2" << endl;
    cout << "3 - REPORTE 3" << endl;
    cout << "4 - REPORTE 4" << endl;
    cout << "5 - REPORTE 5" << endl;
    cout << "6 - REPORTE 6" << endl;
    cout << "7 - REPORTE 7" << endl;
    cout << "8 - REPORTE 8" << endl;
    cout << "9 - REPORTE 9" << endl;
    cout << "10 - REPORTE 10" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void ReportesMenu::ejecutarOpcion(int opcion)
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
    }
}


int ReportesMenu::seleccionOpcion()
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
