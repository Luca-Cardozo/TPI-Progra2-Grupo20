#include <iostream>
#include "GeneroMenu.h"
#include "rlutil.h"
#include "utils.h"

using namespace std;

GeneroMenu::GeneroMenu()
{
    _cantidadOpciones = 4;
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
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "--- MENU GENEROS ---" << endl;
    cout << "1 - CARGAR GENERO" << endl;
    cout << "2 - MODIFICAR GENERO" << endl;
    cout << "3 - ELIMINAR GENERO" << endl;
    cout << "4 - ALTA GENERO" << endl;
    cout << "--------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "--------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void GeneroMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _generoManager.cargarGenero();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _generoManager.modificarGenero();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _generoManager.eliminarGenero();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _generoManager.altaGenero();
        validarAlta(resultado);
        break;
    }
}


int GeneroMenu::seleccionOpcion()
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
