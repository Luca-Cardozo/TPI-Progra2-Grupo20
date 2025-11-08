#include <iostream>
#include "ConsumoMenu.h"
#include "rlutil.h"
#include "utils.h"

using namespace std;

ConsumoMenu::ConsumoMenu()
{
    _cantidadOpciones = 4;
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
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "--- MENU CONSUMOS ---" << endl;
    cout << "1 - NUEVO CONSUMO" << endl;
    cout << "2 - MODIFICAR CONSUMO" << endl;
    cout << "3 - ELIMINAR CONSUMO" << endl;
    cout << "4 - ALTA CONSUMO" << endl;
    cout << "-----------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-----------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void ConsumoMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _consumoManager.cargarConsumo();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _consumoManager.modificarConsumo();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _consumoManager.eliminarConsumo();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _consumoManager.altaConsumo();
        validarAlta(resultado);
        break;
    }
}


int ConsumoMenu::seleccionOpcion()
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
