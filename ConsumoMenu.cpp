#include <iostream>
#include "ConsumoMenu.h"

using namespace std;

ConsumoMenu::ConsumoMenu()
{
    _cantidadOpciones = 5;
}

void ConsumoMenu::mostrar()
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


void ConsumoMenu::mostrarOpciones()
{
    cout << "--- MENU CONSUMOS ---" << endl;
    cout << "1 - ALTA CONSUMO" << endl;
    cout << "2 - MODIFICAR CONSUMO" << endl;
    cout << "3 - ELIMINAR CONSUMO" << endl;
    cout << "4 - CONSULTAR CONSUMOS" << endl;
    cout << "5 - LISTAR CONSUMOS" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
}

void ConsumoMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _consumoManager.cargarConsumo();
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
        resultado = _consumoManager.modificarConsumo();
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
        resultado = _consumoManager.eliminarConsumo();
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


int ConsumoMenu::seleccionOpcion()
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
