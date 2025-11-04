#include <iostream>
#include "ReportesMenu.h"

using namespace std;

ReportesMenu::ReportesMenu()
{
    _cantidadOpciones = 10;
}

void ReportesMenu::mostrar()
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


void ReportesMenu::mostrarOpciones()
{
    cout << "-------------------------------------- MENU REPORTES --------------------------------------" << endl;
    cout << "1 - CANTIDAD DE CONSUMOS POR SUSCRIPTOR EN UN RANGO DE FECHAS" << endl;
    cout << "2 - CANTIDAD DE CONSUMOS POR TITULO EN UN RANGO DE FECHAS" << endl;
    cout << "3 - CANTIDAD DE CONSUMOS TOTALES POR TIPO DE CONTENIDO EN UN RANGO HORARIO" << endl;
    cout << "4 - TOP 5 SUSCRIPTORES CON MAYOR TIEMPO DE VISUALIZACION EN UN ANIO DETERMINADO" << endl;
    cout << "5 - TOP 10 DE SERIES Y PELICULAS MAS CONSUMIDAS EN UN ANIO DETERMINADO" << endl;
    cout << "6 - CANTIDAD Y PORCENTAJE DE CONSUMOS POR GENERO EN UN ANIO DETERMINADO" << endl;
    cout << "7 - TOTAL DE MINUTOS CONSUMIDOS POR TIPO DE CONTENIDO POR MES EN UN ANIO DETERMINADO" << endl;
    cout << "8 - PROMEDIO MENSUAL DE MINUTOS CONSUMIDOS POR TIPO DE SUSCRIPCION EN UN ANIO DETERMINADO" << endl;
    cout << "9 - PROMEDIO DIARIO DE MINUTOS CONSUMIDOS POR SUSCRIPTOR EN UN DETERMINADO MES Y ANIO" << endl;
    cout << "10 - PORCENTAJE MENSUAL DE TIEMPO CONSUMIDO POR TIPO DE CONTENIDO EN UN ANIO DETERMINADO" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
}

void ReportesMenu::ejecutarOpcion(int opcion)
{
    switch(opcion)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;
    case 5:

        break;
    case 6:

        break;
    case 7:

        break;
    case 8:

        break;
    case 9:

        break;
    case 10 :

        break;
    }
}


int ReportesMenu::seleccionOpcion()
{
    int opcion;
    mostrarOpciones();
    cout << "-----------------------------------------------------------------------------------------" << endl;
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
