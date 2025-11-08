#include <iostream>
#include "DirectorMenu.h"
#include "rlutil.h"
#include "utils.h"

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
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "--- MENU DIRECTORES ---" << endl;
    cout << "1 - CARGAR DIRECTOR" << endl;
    cout << "2 - MODIFICAR DIRECTOR" << endl;
    cout << "3 - ELIMINAR DIRECTOR" << endl;
    cout << "4 - ALTA DIRECTOR" << endl;
    cout << "-----------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-----------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void DirectorMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _directorManager.cargarDirector();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _directorManager.modificarDirector();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _directorManager.eliminarDirector();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _directorManager.altaDirector();
        validarAlta(resultado);
        break;
    }
}


int DirectorMenu::seleccionOpcion()
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
