#include <iostream>
#include "TipoContenidoMenu.h"
#include "rlutil.h"
#include "utils.h"

using namespace std;

TipoContenidoMenu::TipoContenidoMenu()
{
    _cantidadOpciones = 4;
}

void TipoContenidoMenu::mostrar()
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


void TipoContenidoMenu::mostrarOpciones()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "--- MENU TIPOS DE CONTENIDO ---" << endl;
    cout << "1 - CARGAR TIPO DE CONTENIDO" << endl;
    cout << "2 - MODIFICAR TIPO DE CONTENIDO" << endl;
    cout << "3 - ELIMINAR TIPO DE CONTENIDO" << endl;
    cout << "4 - ALTA TIPO DE CONTENIDO" << endl;
    cout << "---------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "---------------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void TipoContenidoMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _tipoContenidoManager.cargarTipoContenido();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _tipoContenidoManager.modificarTipoContenido();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _tipoContenidoManager.eliminarTipoContenido();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _tipoContenidoManager.altaTipoContenido();
        validarAlta(resultado);
        break;
    }
}


int TipoContenidoMenu::seleccionOpcion()
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
