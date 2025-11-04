#include <iostream>
#include "TipoSuscripcionMenu.h"

using namespace std;

TipoSuscripcionMenu::TipoSuscripcionMenu()
{
    _cantidadOpciones = 4;
}

void TipoSuscripcionMenu::mostrar()
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


void TipoSuscripcionMenu::mostrarOpciones()
{
    cout << "--- MENU TIPOS DE SUSCRIPCION ---" << endl;
    cout << "1 - CARGAR TIPO DE SUSCRIPCION" << endl;
    cout << "2 - MODIFICAR TIPO DE SUSCRIPCION" << endl;
    cout << "3 - ELIMINAR TIPO DE SUSCRIPCION" << endl;
    cout << "4 - ALTA TIPO DE SUSCRIPCION" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "---------------------------------" << endl;
}

void TipoSuscripcionMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _tipoSuscripcionManager.cargarTipoSuscripcion();
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
        resultado = _tipoSuscripcionManager.modificarTipoSuscripcion();
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
        resultado = _tipoSuscripcionManager.eliminarTipoSuscripcion();
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
        resultado = _tipoSuscripcionManager.altaTipoSuscripcion();
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


int TipoSuscripcionMenu::seleccionOpcion()
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
