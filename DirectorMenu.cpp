#include <iostream>
#include "DirectorMenu.h"

using namespace std;

DirectorMenu::DirectorMenu()
{
    _cantidadOpciones = 4;
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
    cout << "1 - CARGAR DIRECTOR" << endl;
    cout << "2 - MODIFICAR DIRECTOR" << endl;
    cout << "3 - ELIMINAR DIRECTOR" << endl;
    cout << "4 - ALTA DIRECTOR" << endl;
    cout << "--------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void DirectorMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _directorManager.cargarDirector();
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
        resultado = _directorManager.modificarDirector();
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
        resultado = _directorManager.eliminarDirector();
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
        resultado = _directorManager.altaDirector();
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


int DirectorMenu::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    cout << "--------------------" << endl;
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
