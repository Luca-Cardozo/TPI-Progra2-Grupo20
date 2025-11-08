#include <iostream>
#include "SuscriptorMenu.h"
#include "rlutil.h"
#include "utils.h"

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
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "--- MENU SUSCRIPTORES ---" << endl;
    cout << "1 - NUEVO SUSCRIPTOR" << endl;
    cout << "2 - MODIFICAR SUSCRIPTOR" << endl;
    cout << "3 - ELIMINAR SUSCRIPTOR" << endl;
    cout << "4 - ALTA SUSCRIPTOR" << endl;
    cout << "-------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void SuscriptorMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _suscriptorManager.cargarSuscriptor();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _suscriptorManager.modificarSuscriptor();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _suscriptorManager.eliminarSuscriptor();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _suscriptorManager.altaSuscriptor();
        validarAlta(resultado);
        break;
    }
}


int SuscriptorMenu::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    rlutil::setColor(rlutil::YELLOW);
    cout << "--------------------" << endl;
    cout << "SELECCIONE UNA OPCION: ";
    rlutil::setColor(rlutil::WHITE);
    cin >> opcion;
    while(opcion < 0 || opcion > _cantidadOpciones)
    {
        rlutil::setColor(rlutil::RED);
        cout << "---------------" << endl;
        cout << "Opcion incorrecta... Vuelva a intentarlo por favor..." << endl;
        cout << "---------------" << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "SELECCIONE UNA OPCION: ";
        rlutil::setColor(rlutil::WHITE);
        cin >> opcion;
    }
    return opcion;
}
