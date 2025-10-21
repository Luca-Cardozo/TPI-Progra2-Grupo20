#include <iostream>
#include "ConsumoMenu.h"

using namespace std;

ConsumoMenu::ConsumoMenu()
{
    _cantidadOpciones = 5;
}

void ConsumoMenu::mostrar()
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


void ConsumoMenu::mostrarOpciones()
{
    cout << "--- MENU CONSUMOS ---" << endl;
    cout << "1 - ALTA CONSUMO" << endl;
    cout << "2 - MODIFICAR CONSUMO" << endl;
    cout << "3 - ELIMINAR CONSUMO" << endl;
    cout << "4 - CONSULTAR CONSUMOS" << endl;
    cout << "5 - LISTAR CONSUMOS" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void ConsumoMenu::ejecutarOpcion(int opcion)
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


int ConsumoMenu::seleccionOpcion()
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
