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
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _clasificacionManager.cargarClasificacion();
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
        resultado = _clasificacionManager.modificarClasificacion();
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
        resultado = _clasificacionManager.eliminarClasificacion();
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
