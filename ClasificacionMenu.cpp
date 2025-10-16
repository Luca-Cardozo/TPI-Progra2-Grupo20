#include <iostream>
#include "ClasificacionMenu.h"

using namespace std;

ClasificacionMenu::ClasificacionMenu()
{
    _cantidadOpciones = 5;
}

void ClasificacionMenu::mostrar()
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


void ClasificacionMenu::mostrarOpciones()
{
    cout << "--- MENU CLASIFICACIONES ---" << endl;
    cout << "1 - ALTA CLASIFICACION" << endl;
    cout << "2 - MODIFICAR CLASIFICACION" << endl;
    cout << "3 - ELIMINAR CLASIFICACION" << endl;
    cout << "4 - CONSULTAR CLASIFICACIONES" << endl;
    cout << "5 - LISTAR CLASIFICACIONES" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void ClasificacionMenu::ejecutarOpcion(int opcion)
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


int ClasificacionMenu::seleccionOpcion()
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
