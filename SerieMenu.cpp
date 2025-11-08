#include <iostream>
#include "SerieMenu.h"
#include "rlutil.h"
#include "utils.h"

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
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "--- MENU SERIES ---" << endl;
    cout << "1 - CARGAR SERIE" << endl;
    cout << "2 - MODIFICAR SERIE" << endl;
    cout << "3 - ELIMINAR SERIE" << endl;
    cout << "4 - ALTA SERIE" << endl;
    cout << "---------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "---------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void SerieMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _serieManager.cargarSerie();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _serieManager.modificarSerie();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _serieManager.eliminarSerie();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _serieManager.altaSerie();
        validarAlta(resultado);
        break;
    }
}


int SerieMenu::seleccionOpcion()
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
