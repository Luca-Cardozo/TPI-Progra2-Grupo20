#include <iostream>
#include "SuscriptorMenu.h"

using namespace std;

SuscriptorMenu::SuscriptorMenu()
{
    _cantidadOpciones = 4;
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
    cout << "1 - NUEVO SUSCRIPTOR" << endl;
    cout << "2 - MODIFICAR SUSCRIPTOR" << endl;
    cout << "3 - ELIMINAR SUSCRIPTOR" << endl;
    cout << "4 - ALTA SUSCRIPTOR" << endl;
    cout << "-------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------------" << endl;
}

void SuscriptorMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _suscriptorManager.cargarSuscriptor();
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
        resultado = _suscriptorManager.modificarSuscriptor();
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
        resultado = _suscriptorManager.eliminarSuscriptor();
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
        resultado = _suscriptorManager.altaSuscriptor();
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


int SuscriptorMenu::seleccionOpcion()
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
