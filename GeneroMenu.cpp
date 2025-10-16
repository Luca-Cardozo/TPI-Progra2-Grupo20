#include <iostream>
#include "GeneroMenu.h"

using namespace std;

GeneroMenu::GeneroMenu()
{
    _cantidadOpciones = 5;
}

void GeneroMenu::mostrar()
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


void GeneroMenu::mostrarOpciones()
{
    cout << "--- MENU GENEROS ---" << endl;
    cout << "1 - ALTA GENERO" << endl;
    cout << "2 - MODIFICAR GENERO" << endl;
    cout << "3 - ELIMINAR GENERO" << endl;
    cout << "4 - CONSULTAR GENEROS" << endl;
    cout << "5 - LISTAR GENEROS" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void GeneroMenu::ejecutarOpcion(int opcion)
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


int GeneroMenu::seleccionOpcion()
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
