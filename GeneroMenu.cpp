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
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _generoManager.cargarGenero();
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
        system("pause");
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
        system("pause");
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
