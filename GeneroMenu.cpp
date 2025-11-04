#include <iostream>
#include "GeneroMenu.h"

using namespace std;

GeneroMenu::GeneroMenu()
{
    _cantidadOpciones = 4;
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
    cout << "1 - CARGAR GENERO" << endl;
    cout << "2 - MODIFICAR GENERO" << endl;
    cout << "3 - ELIMINAR GENERO" << endl;
    cout << "4 - ALTA GENERO" << endl;
    cout << "--------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void GeneroMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _generoManager.cargarGenero();
        if(resultado)
        {
            cout << "Carga exitosa!" << endl;
        }
        else
        {
            cout << "No se pudo realizar la carga..." << endl;
        }
        break;
    case 2:
        system("cls");
        resultado = _generoManager.modificarGenero();
        if(resultado)
        {
            cout << "Modificacion exitosa!" << endl;
        }
        else
        {
            cout << "No se pudo realizar la modificacion..." << endl;
        }
        break;
    case 3:
        system("cls");
        resultado = _generoManager.eliminarGenero();
        if(resultado)
        {
            cout << "Baja exitosa!" << endl;
        }
        else
        {
            cout << "No se pudo realizar la baja..." << endl;
        }
        break;
    case 4:
        system("cls");
        resultado = _generoManager.altaGenero();
        if(resultado)
        {
            cout << "Alta exitosa!" << endl;
        }
        else
        {
            cout << "No se pudo realizar el alta..." << endl;
        }
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
