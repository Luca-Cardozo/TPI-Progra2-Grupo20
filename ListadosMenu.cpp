#include <iostream>
#include "ListadosMenu.h"
#include "utils.h"

using namespace std;

ListadosMenu::ListadosMenu()
{
    _cantidadOpciones = 15;
}

void ListadosMenu::mostrar()
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


void ListadosMenu::mostrarOpciones()
{
    cout << "------------------ MENU LISTADOS ------------------" << endl;
    cout << "1 - SUSCRIPTORES ORDENADOS POR APELLIDO" << endl;
    cout << "2 - SUSCRIPTORES ORDENADOS POR FECHA DE ALTA" << endl;
    cout << "3 - PELICULAS ORDENADAS POR TITULO" << endl;
    cout << "4 - PELICULAS ORDENADAS POR FECHA DE ESTRENO" << endl;
    cout << "5 - PELICULAS ORDENADAS POR DURACION" << endl;
    cout << "6 - SERIES ORDENADAS POR TITULO" << endl;
    cout << "7 - SERIES ORDENADAS POR FECHA DE ESTRENO" << endl;
    cout << "8 - SERIES ORDENADAS POR CAPITULOS" << endl;
    cout << "9 - DIRECTORES ORDENADOS POR APELLIDO" << endl;
    cout << "10 - CONSUMOS ORDENADOS POR FECHA DE ACCESO" << endl;
    cout << "11 - CONSUMOS ORDENADOS POR ID DE SUSCRIPTOR" << endl;
    cout << "12 - GENEROS DISPONIBLES" << endl;
    cout << "13 - CLASIFICACIONES DISPONIBLES" << endl;
    cout << "14 - TIPOS DE CONTENIDO DISPONIBLES" << endl;
    cout << "15 - TIPOS DE SUSCRIPCIONES DISPONIBLES" << endl;
    cout << "-------------------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------------------------------------" << endl;
}

void ListadosMenu::ejecutarOpcion(int opcion)
{
    int respuesta;
    switch(opcion)
    {
    case 1:
        _listadosManager.listarSuscriptoresApellido();
        break;
    case 2:
        cout << "1- Orden creciente" << endl;
        cout << "2- Orden decreciente" << endl;
        cout << "Ingrese respuesta: " << endl;
        cin >> respuesta;
        while(respuesta != 1 && respuesta != 2)
        {
            cout << "Respuesta incorrecta... Vuelva a intentarlo..." << endl;
            cout << "1- Orden creciente" << endl;
            cout << "2- Orden decreciente" << endl;
            cout << "Ingrese respuesta: " << endl;
            cin >> respuesta;
        }
        system("cls");
        if(respuesta == 1) _listadosManager.listarSuscriptoresFechaAlta(fechaCreciente);
        else if(respuesta == 2) _listadosManager.listarSuscriptoresFechaAlta(fechaDecreciente);
        break;
    case 3:
        _listadosManager.listarPeliculasTitulo();
        break;
    case 4:
        cout << "1- Orden creciente" << endl;
        cout << "2- Orden decreciente" << endl;
        cout << "Ingrese respuesta: " << endl;
        cin >> respuesta;
        while(respuesta != 1 && respuesta != 2)
        {
            cout << "Respuesta incorrecta... Vuelva a intentarlo..." << endl;
            cout << "1- Orden creciente" << endl;
            cout << "2- Orden decreciente" << endl;
            cout << "Ingrese respuesta: " << endl;
            cin >> respuesta;
        }
        system("cls");
        if(respuesta == 1) _listadosManager.listarPeliculasFechaEstreno(fechaCreciente);
        else if(respuesta == 2) _listadosManager.listarPeliculasFechaEstreno(fechaDecreciente);
        break;
    case 5:
        cout << "1- Orden creciente" << endl;
        cout << "2- Orden decreciente" << endl;
        cout << "Ingrese respuesta: " << endl;
        cin >> respuesta;
        while(respuesta != 1 && respuesta != 2)
        {
            cout << "Respuesta incorrecta... Vuelva a intentarlo..." << endl;
            cout << "1- Orden creciente" << endl;
            cout << "2- Orden decreciente" << endl;
            cout << "Ingrese respuesta: " << endl;
            cin >> respuesta;
        }
        system("cls");
        if(respuesta == 1) _listadosManager.listarPeliculasDuracion(intCreciente);
        else if(respuesta == 2) _listadosManager.listarPeliculasDuracion(intDecreciente);
        break;
    case 6:
        _listadosManager.listarSeriesTitulo();
        break;
    case 7:
        cout << "1- Orden creciente" << endl;
        cout << "2- Orden decreciente" << endl;
        cout << "Ingrese respuesta: " << endl;
        cin >> respuesta;
        while(respuesta != 1 && respuesta != 2)
        {
            cout << "Respuesta incorrecta... Vuelva a intentarlo..." << endl;
            cout << "1- Orden creciente" << endl;
            cout << "2- Orden decreciente" << endl;
            cout << "Ingrese respuesta: " << endl;
            cin >> respuesta;
        }
        system("cls");
        if(respuesta == 1) _listadosManager.listarSeriesFechaEstreno(fechaCreciente);
        else if(respuesta == 2) _listadosManager.listarSeriesFechaEstreno(fechaDecreciente);
        break;
    case 8:
        cout << "1- Orden creciente" << endl;
        cout << "2- Orden decreciente" << endl;
        cout << "Ingrese respuesta: " << endl;
        cin >> respuesta;
        while(respuesta != 1 && respuesta != 2)
        {
            cout << "Respuesta incorrecta... Vuelva a intentarlo..." << endl;
            cout << "1- Orden creciente" << endl;
            cout << "2- Orden decreciente" << endl;
            cout << "Ingrese respuesta: " << endl;
            cin >> respuesta;
        }
        system("cls");
        if(respuesta == 1) _listadosManager.listarSeriesCapitulos(intCreciente);
        else if(respuesta == 2) _listadosManager.listarSeriesCapitulos(intDecreciente);
        break;
    case 9:
        _listadosManager.listarDirectoresApellido();
        break;
    case 10 :

        break;
    case 11:

        break;
    case 12:
        _listadosManager.listarGeneros();
        break;
    case 13:
        _listadosManager.listarClasificaciones();
        break;
    case 14:
        _listadosManager.listarTiposContenido();
        break;
    case 15:
        _listadosManager.listarTiposSuscripcion();
        break;
    }
}


int ListadosMenu::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    cout << "-------------------------------------------------" << endl;
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
