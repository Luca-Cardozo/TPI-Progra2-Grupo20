#include <iostream>
#include "ReportesMenu.h"
#include "rlutil.h"
#include "utils.h"

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
    rlutil::setColor(rlutil::BROWN);
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
    rlutil::setColor(rlutil::WHITE);
}

void ReportesMenu::ejecutarOpcion(int opcion)
{
    Fecha f1, f2;
    Hora h1, h2;
    int anio, mes;
    switch(opcion)
    {
    case 1:
        pedir2FechasValidas(f1, f2);
        _reportesManager.cantConsumosPorSuscriptor(f1, f2);
        break;
    case 2:
        pedir2FechasValidas(f1, f2);
        _reportesManager.cantConsumosPorTitulo(f1, f2);
        break;
    case 3:
        pedir2HorariosValidos(h1, h2);
        _reportesManager.cantConsumosPorTipoContenido(h1, h2);
        break;
    case 4:
        anio = pedirAnioValido();
        _reportesManager.top5SuscriptoresMayorVisualizacion(anio);
        break;
    case 5:
        anio = pedirAnioValido();
        _reportesManager.top10ContenidoMasConsumido(anio);
        break;
    case 6:
        anio = pedirAnioValido();
        _reportesManager.consumosPorGenero(anio);
        break;
    case 7:
        anio = pedirAnioValido();
        _reportesManager.minutosConsumidosPorTipoContenido(anio);
        break;
    case 8:
        anio = pedirAnioValido();
        _reportesManager.promedioMensualMinutosConsumidosPorTipoSuscripcion(anio);
        break;
    case 9:
        mes = pedirMesValido();
        anio = pedirAnioValido();
        _reportesManager.promedioDiarioMinutosConsumidosPorSuscriptor(mes, anio);
        break;
    case 10 :
        anio = pedirAnioValido();
        _reportesManager.porcentajeMensualTiempoConsumidoPorTipoContenido(anio);
        break;
    }
}


int ReportesMenu::seleccionOpcion()
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
        cin >> opcion;
        rlutil::setColor(rlutil::WHITE);
    }
    return opcion;
}
