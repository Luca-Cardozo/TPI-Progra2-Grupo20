#include <iostream>
#include "DirectorMenu.h"

using namespace std;

DirectorMenu::DirectorMenu()
{
    _cantidadOpciones = 5;
}

void DirectorMenu::mostrar()
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


void DirectorMenu::mostrarOpciones()
{
    cout << "--- MENU DIRECTORES ---" << endl;
    cout << "1 - ALTA DIRECTOR" << endl;
    cout << "2 - MODIFICAR DIRECTOR" << endl;
    cout << "3 - ELIMINAR DIRECTOR" << endl;
    cout << "4 - CONSULTAR DIRECTORES" << endl;
    cout << "5 - LISTAR DIRECTORES" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void DirectorMenu::ejecutarOpcion(int opcion)
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


int DirectorMenu::seleccionOpcion()
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
