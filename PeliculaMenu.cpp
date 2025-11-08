#include <iostream>
#include "PeliculaMenu.h"
#include "rlutil.h"
#include "utils.h"

using namespace std;

PeliculaMenu::PeliculaMenu()
{
    _cantidadOpciones = 4;
}

void PeliculaMenu::mostrar()
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


void PeliculaMenu::mostrarOpciones()
{
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "--- MENU PELICULAS ---" << endl;
    cout << "1 - CARGAR PELICULA" << endl;
    cout << "2 - MODIFICAR PELICULA" << endl;
    cout << "3 - ELIMINAR PELICULA" << endl;
    cout << "4 - ALTA PELICULA" << endl;
    cout << "-----------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-----------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void PeliculaMenu::ejecutarOpcion(int opcion)
{
    bool resultado;
    switch(opcion)
    {
    case 1:
        system("cls");
        resultado = _peliculaManager.cargarPelicula();
        validarCarga(resultado);
        break;
    case 2:
        system("cls");
        resultado = _peliculaManager.modificarPelicula();
        validarModificacion(resultado);
        break;
    case 3:
        system("cls");
        resultado = _peliculaManager.eliminarPelicula();
        validarBaja(resultado);
        break;
    case 4:
        system("cls");
        resultado = _peliculaManager.altaPelicula();
        validarModificacion(resultado);
        break;
    }
}


int PeliculaMenu::seleccionOpcion()
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
