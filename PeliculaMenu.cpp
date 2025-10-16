#include <iostream>
#include "PeliculaMenu.h"

using namespace std;

PeliculaMenu::PeliculaMenu()
{
    _cantidadOpciones = 5;
}

void PeliculaMenu::mostrar()
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


void PeliculaMenu::mostrarOpciones()
{
    cout << "--- MENU PELICULAS ---" << endl;
    cout << "1 - ALTA PELICULA" << endl;
    cout << "2 - MODIFICAR PELICULA" << endl;
    cout << "3 - ELIMINAR PELICULA" << endl;
    cout << "4 - CONSULTAR PELICULAS" << endl;
    cout << "5 - LISTAR PELICULAS" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void PeliculaMenu::ejecutarOpcion(int opcion)
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


int PeliculaMenu::seleccionOpcion()
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
