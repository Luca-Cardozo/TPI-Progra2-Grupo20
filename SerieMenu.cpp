#include <iostream>
#include "SerieMenu.h"

using namespace std;

SerieMenu::SerieMenu()
{
    _cantidadOpciones = 4;
}

void SerieMenu::mostrar()
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


void SerieMenu::mostrarOpciones()
{
    cout << "--- MENU SERIES ---" << endl;
    cout << "1 - CARGAR SERIE" << endl;
    cout << "2 - MODIFICAR SERIE" << endl;
    cout << "3 - ELIMINAR SERIE" << endl;
    cout << "4 - ALTA SERIE" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void SerieMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _serieManager.cargarSerie();
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
        resultado = _serieManager.modificarSerie();
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
        resultado = _serieManager.eliminarSerie();
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
        resultado = _serieManager.altaSerie();
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


int SerieMenu::seleccionOpcion()
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
