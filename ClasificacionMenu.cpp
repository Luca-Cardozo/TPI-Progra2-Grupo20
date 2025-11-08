#include <iostream>
#include "ClasificacionMenu.h"
#include "rlutil.h"
#include "utils.h"

using namespace std;

ClasificacionMenu::ClasificacionMenu()
{
    _cantidadOpciones = 4;
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
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "--- MENU CLASIFICACIONES ---" << endl;
    cout << "1 - CARGAR CLASIFICACION" << endl;
    cout << "2 - MODIFICAR CLASIFICACION" << endl;
    cout << "3 - ELIMINAR CLASIFICACION" << endl;
    cout << "4 - ALTA CLASIFICACION" << endl;
    cout << "-----------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-----------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void ClasificacionMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _clasificacionManager.cargarClasificacion();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _clasificacionManager.modificarClasificacion();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _clasificacionManager.eliminarClasificacion();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _clasificacionManager.altaClasificacion();
        validarAlta(resultado);
        break;
    }
}


int ClasificacionMenu::seleccionOpcion()
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
