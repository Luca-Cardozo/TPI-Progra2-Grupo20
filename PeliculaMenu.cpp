#include <iostream>
#include "PeliculaMenu.h"

using namespace std;

PeliculaMenu::PeliculaMenu()
{
    _cantidadOpciones = 4;
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
    cout << "1 - CARGAR PELICULA" << endl;
    cout << "2 - MODIFICAR PELICULA" << endl;
    cout << "3 - ELIMINAR PELICULA" << endl;
    cout << "4 - ALTA PELICULA" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void PeliculaMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _peliculaManager.cargarPelicula();
        if(resultado)
        {
            cout << "Carga exitosa!" << endl;
        }
        else
        {
            cout << "No se pudo realizar la carga..." << endl;
        }
        system("pause");
        break;
    case 2:
        system("cls");
        resultado = _peliculaManager.modificarPelicula();
        if(resultado)
        {
            cout << "Modificacion exitosa!" << endl;
        }
        else
        {
            cout << "No se pudo realizar la modificacion..." << endl;
        }
        system("pause");
        break;
    case 3:
        system("cls");
        resultado = _peliculaManager.eliminarPelicula();
        if(resultado)
        {
            cout << "Baja exitosa!" << endl;
        }
        else
        {
            cout << "No se pudo realizar la baja..." << endl;
        }
        system("pause");
        break;
    case 4:
        system("cls");
        resultado = _peliculaManager.altaPelicula();
        if(resultado)
        {
            cout << "Alta exitosa!" << endl;
        }
        else
        {
            cout << "No se pudo realizar el alta..." << endl;
        }
        system("pause");
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
