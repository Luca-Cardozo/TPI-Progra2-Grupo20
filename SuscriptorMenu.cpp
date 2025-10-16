#include <iostream>
#include "SuscriptorMenu.h"

using namespace std;

SuscriptorMenu::SuscriptorMenu()
{
    _cantidadOpciones = 5;
}

void SuscriptorMenu::mostrar()
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


void SuscriptorMenu::mostrarOpciones()
{
    cout << "--- MENU SUSCRIPTORES ---" << endl;
    cout << "1 - ALTA SUSCRIPTOR" << endl;
    cout << "2 - MODIFICAR SUSCRIPTOR" << endl;
    cout << "3 - ELIMINAR SUSCRIPTOR" << endl;
    cout << "4 - CONSULTAR SUSCRIPTORES" << endl;
    cout << "5 - LISTAR SUSCRIPTORES" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void SuscriptorMenu::ejecutarOpcion(int opcion)
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


int SuscriptorMenu::seleccionOpcion()
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
