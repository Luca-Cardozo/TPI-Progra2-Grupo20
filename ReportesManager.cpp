#include <iostream>
#include "ReportesManager.h"
#include "rlutil.h"

using namespace std;

void ReportesManager::cantConsumosPorSuscriptor(Fecha f1, Fecha f2)
{
    int cantRegistrosSuscriptores = _repoSuscriptor.getCantidadRegistros();
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    int* pConsumosPorSuscriptor = new int [cantRegistrosSuscriptores] {};
    Suscriptor* pSuscriptores = new Suscriptor [cantRegistrosSuscriptores];
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];


    if(cantRegistrosSuscriptores == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay suscriptores cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        return;
    }
    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        return;
    }
    if(pConsumosPorSuscriptor == nullptr || pSuscriptores == nullptr || pConsumos == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        return;
    }

    _repoSuscriptor.leer(pSuscriptores, cantRegistrosSuscriptores);
    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getFechaAcceso() >= f1 && pConsumos[i].getFechaAcceso() <= f2)
        {
            pConsumosPorSuscriptor[pConsumos[i].getIdSuscriptor() - 1]++;
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    system("cls");
    cout << "==================================== CONSUMOS POR SUSCRIPTOR ====================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << endl;
    cout << "++++++ Fecha inicial: ";
    f1.mostrar();
    cout << endl;
    cout << "++++++ Fecha final: ";
    f2.mostrar();
    rlutil::setColor(rlutil::GREEN);
    cout << endl;
    for(int i = 0; i < cantRegistrosSuscriptores; i++)
    {
        if(pSuscriptores[i].getEliminado()) continue;
        string email = pSuscriptores[i].getEmail();
        int anchoColumna = 25;
        int espacios = anchoColumna - email.length();
        if (espacios < 1) espacios = 1;
        cout << "ID #" << i + 1 << ":   " << email;
        for (int j = 0; j < espacios; j++) cout << ' ';
        cout << "->               CONSUMOS:   " << pConsumosPorSuscriptor[i] << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pConsumosPorSuscriptor;
    delete [] pSuscriptores;
    delete [] pConsumos;
}

void ReportesManager::cantConsumosPorTitulo(Fecha f1, Fecha f2)
{
    int cantRegistrosPeliculas = _repoPelicula.getCantidadRegistros();
    int cantRegistrosSeries = _repoSerie.getCantidadRegistros();
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    int* pConsumosPorPelicula = new int [cantRegistrosPeliculas] {};
    int* pConsumosPorSerie = new int [cantRegistrosSeries] {};
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];
    Pelicula* pPeliculas = new Pelicula [cantRegistrosPeliculas];
    Serie* pSeries = new Serie [cantRegistrosSeries];

    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorPelicula;
        delete [] pConsumosPorSerie;
        delete [] pConsumos;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }
    if(cantRegistrosPeliculas == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay peliculas cargadas..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorPelicula;
        delete [] pConsumosPorSerie;
        delete [] pConsumos;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }
    if(cantRegistrosSeries == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay series cargadas..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorPelicula;
        delete [] pConsumosPorSerie;
        delete [] pConsumos;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }

    if(pConsumosPorPelicula == nullptr || pConsumosPorSerie == nullptr || pConsumos == nullptr || pPeliculas == nullptr || pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorPelicula;
        delete [] pConsumosPorSerie;
        delete [] pConsumos;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }

    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);
    _repoPelicula.leer(pPeliculas, cantRegistrosPeliculas);
    _repoSerie.leer(pSeries, cantRegistrosSeries);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getFechaAcceso() >= f1 && pConsumos[i].getFechaAcceso() <= f2)
        {
            if(pConsumos[i].getIdTipoContenido() == 1)
            {
                pConsumosPorPelicula[pConsumos[i].getIdContenido() - 1]++;
            }
            else if(pConsumos[i].getIdTipoContenido() == 2)
            {
                pConsumosPorSerie[pConsumos[i].getIdContenido() - 1]++;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    system("cls");
    cout << "==================================== CONSUMOS POR TITULO ====================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << endl;
    cout << "++++++ Fecha inicial: ";
    f1.mostrar();
    cout << endl;
    cout << "++++++ Fecha final: ";
    f2.mostrar();
    cout << endl;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "+++++++++++++++++++++++++++++ PELICULAS ++++++++++++++++++++++++++++++" << endl;
    rlutil::setColor(rlutil::GREEN);
    cout << endl;
    for(int i = 0; i < cantRegistrosPeliculas; i++)
    {
        if(pPeliculas[i].getEliminado()) continue;
        string titulo = pPeliculas[i].getTitulo();
        int anchoColumna = 25;
        int espacios = anchoColumna - titulo.length();
        if (espacios < 1) espacios = 1;
        cout << "ID #" << i + 1 << ":   " << titulo;
        for (int j = 0; j < espacios; j++) cout << ' ';
        cout << "->               CONSUMOS:   " << pConsumosPorPelicula[i] << endl;
    }
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << endl;
    cout << "++++++++++++++++++++++++++++++ SERIES +++++++++++++++++++++++++++++++" << endl;
    rlutil::setColor(rlutil::GREEN);
    cout << endl;
    for(int i = 0; i < cantRegistrosSeries; i++)
    {
        if(pSeries[i].getEliminado()) continue;
        string titulo = pSeries[i].getTitulo();
        int anchoColumna = 25;
        int espacios = anchoColumna - titulo.length();
        if (espacios < 1) espacios = 1;
        cout << "ID #" << i + 1 << ":   " << titulo;
        for (int j = 0; j < espacios; j++) cout << ' ';
        cout << "->               CONSUMOS:   " << pConsumosPorSerie[i] << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pConsumosPorPelicula;
    delete [] pConsumosPorSerie;
    delete [] pConsumos;
    delete [] pPeliculas;
    delete [] pSeries;
}

void ReportesManager::cantConsumosPorTipoContenido(Hora h1, Hora h2)
{
    int cantConsumosPeliculas = 0;
    int cantConsumosSeries = 0;
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];

    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumos;
        return;
    }
    if(pConsumos == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumos;
        return;
    }

    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getHoraAcceso() >= h1 && pConsumos[i].getHoraAcceso() <= h2)
        {
            if(pConsumos[i].getIdTipoContenido() == 1)
            {
                cantConsumosPeliculas++;
            }
            else if(pConsumos[i].getIdTipoContenido() == 2)
            {
                cantConsumosSeries++;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    system("cls");
    cout << "================ CONSUMOS POR TIPO DE CONTENIDO ================" << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << endl;
    cout << "++++++ Hora inicial: ";
    h1.mostrar();
    cout << endl;
    cout << "++++++ Hora final: ";
    h2.mostrar();
    cout << endl;
    rlutil::setColor(rlutil::GREEN);
    cout << endl;
    cout << "++++++++++++++++++++++++++++++++++" << endl;
    cout << "+++ PELICULAS:   " << cantConsumosPeliculas << " CONSUMO/S +++" << endl;
    cout << endl;
    cout << "+++ SERIES:      " << cantConsumosSeries << " CONSUMOS/S +++" << endl;
    cout << "++++++++++++++++++++++++++++++++++" << endl;
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pConsumos;
}

void ReportesManager::top5SuscriptoresMayorVisualizacion(int anio)
{
    int cantRegistrosSuscriptores = _repoSuscriptor.getCantidadRegistros();
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    int* pMinutosConsumidosPorSuscriptor = new int [cantRegistrosSuscriptores] {};
    Suscriptor* pSuscriptores = new Suscriptor [cantRegistrosSuscriptores];
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];
    int activosConConsumo, id, limite, fila, colId, colEmail, colTiempo;

    if(cantRegistrosSuscriptores == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay suscriptores cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pMinutosConsumidosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        return;
    }
    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pMinutosConsumidosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        return;
    }
    if(pMinutosConsumidosPorSuscriptor == nullptr || pSuscriptores == nullptr || pConsumos == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pMinutosConsumidosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        return;
    }

    _repoSuscriptor.leer(pSuscriptores, cantRegistrosSuscriptores);
    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getFechaAcceso().getAnio() == anio)
        {
            pMinutosConsumidosPorSuscriptor[pConsumos[i].getIdSuscriptor() - 1] += pConsumos[i].getDuracionVista();
        }
    }

    activosConConsumo = 0;
    for (int i = 0; i < cantRegistrosSuscriptores; i++)
    {
        if (!pSuscriptores[i].getEliminado() && pMinutosConsumidosPorSuscriptor[i] > 0)
        {
            activosConConsumo++;
        }
    }

    Suscriptor* pSuscriptoresActivos = new Suscriptor[activosConConsumo];
    int* pMinutosConsumidosPorSuscriptorActivo = new int[activosConConsumo];

    if(pSuscriptoresActivos == nullptr || pMinutosConsumidosPorSuscriptorActivo == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        delete [] pMinutosConsumidosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        delete [] pSuscriptoresActivos;
        delete [] pMinutosConsumidosPorSuscriptorActivo;
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    fila = 3;
    colId = 5;
    colEmail = 30;
    colTiempo = 65;
    rlutil::locate(10, fila++);

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "================ TOP 5 SUSCRIPTORES CON MAYOR TIEMPO CONSUMIDO ================" << endl;
    fila += 2;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(colId, fila);
    cout << "+++ " << anio << endl;
    fila++;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(colId, fila++);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::LIGHTBLUE);
    rlutil::locate(colId, fila);
    cout << "ID";
    rlutil::locate(colEmail, fila);
    cout << "EMAIL";
    rlutil::locate(colTiempo, fila++);
    cout << "TIEMPO (MIN)";
    rlutil::locate(colId, fila++);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);

    if (activosConConsumo == 0)
    {
        rlutil::setColor(rlutil::RED);
        rlutil::locate(colId, fila);
        cout << "No hay consumos registrados en " << anio << " para suscriptores activos." << endl;
        rlutil::locate(colId, fila + 2);
        rlutil::setColor(rlutil::WHITE);
        delete [] pMinutosConsumidosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        delete [] pSuscriptoresActivos;
        delete [] pMinutosConsumidosPorSuscriptorActivo;
        return;
    }

    id = 0;
    for (int i = 0; i < cantRegistrosSuscriptores; i++)
    {
        if (!pSuscriptores[i].getEliminado() && pMinutosConsumidosPorSuscriptor[i] > 0)
        {
            pSuscriptoresActivos[id] = pSuscriptores[i];
            pMinutosConsumidosPorSuscriptorActivo[id] = pMinutosConsumidosPorSuscriptor[i];
            id++;
        }
    }

    for (int i = 0; i < activosConConsumo - 1; i++)
    {
        for (int j = i + 1; j < activosConConsumo; j++)
        {
            if (pMinutosConsumidosPorSuscriptorActivo[j] > pMinutosConsumidosPorSuscriptorActivo[i])
            {
                int aux1 = pMinutosConsumidosPorSuscriptorActivo[i];
                pMinutosConsumidosPorSuscriptorActivo[i] = pMinutosConsumidosPorSuscriptorActivo[j];
                pMinutosConsumidosPorSuscriptorActivo[j] = aux1;

                Suscriptor aux2 = pSuscriptoresActivos[i];
                pSuscriptoresActivos[i] = pSuscriptoresActivos[j];
                pSuscriptoresActivos[j] = aux2;
            }
        }
    }

    limite = (activosConConsumo < 5) ? activosConConsumo : 5;
    for(int i = 0; i < limite; i++)
    {
        rlutil::locate(colId, fila);
        cout << pSuscriptoresActivos[i].getId();
        rlutil::locate(colEmail, fila);
        cout << pSuscriptoresActivos[i].getEmail();
        rlutil::locate(colTiempo + 2, fila);
        cout << pMinutosConsumidosPorSuscriptorActivo[i] << endl;
        fila++;
    }

    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(colId, fila++);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pMinutosConsumidosPorSuscriptor;
    delete [] pSuscriptores;
    delete [] pConsumos;
    delete [] pSuscriptoresActivos;
    delete [] pMinutosConsumidosPorSuscriptorActivo;
}

void ReportesManager::top10ContenidoMasConsumido(int anio)
{
    int cantRegistrosPeliculas = _repoPelicula.getCantidadRegistros();
    int cantRegistrosSeries = _repoSerie.getCantidadRegistros();
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    int* pConsumosPorPelicula = new int [cantRegistrosPeliculas] {};
    int* pConsumosPorSerie = new int [cantRegistrosSeries] {};
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];
    Pelicula* pPeliculas = new Pelicula [cantRegistrosPeliculas];
    Serie* pSeries = new Serie [cantRegistrosSeries];
    int peliculasActivasConConsumo, seriesActivasConConsumo, fila, colId, colTitulo, colConsumos, limite, id;

    if(cantRegistrosPeliculas == 0 && cantRegistrosSeries == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay contenidos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorPelicula;
        delete [] pConsumosPorSerie;
        delete [] pConsumos;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }
    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorPelicula;
        delete [] pConsumosPorSerie;
        delete [] pConsumos;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }

    if(pConsumosPorPelicula == nullptr || pConsumosPorSerie == nullptr || pConsumos == nullptr || pPeliculas == nullptr || pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        delete [] pConsumosPorPelicula;
        delete [] pConsumosPorSerie;
        delete [] pConsumos;
        delete [] pPeliculas;
        delete [] pSeries;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    _repoPelicula.leer(pPeliculas, cantRegistrosPeliculas);
    _repoSerie.leer(pSeries, cantRegistrosSeries);
    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getFechaAcceso().getAnio() == anio)
        {
            if(pConsumos[i].getIdTipoContenido() == 1)
            {
                pConsumosPorPelicula[pConsumos[i].getIdContenido() - 1]++;
            }
            else if(pConsumos[i].getIdTipoContenido() == 2)
            {
                pConsumosPorSerie[pConsumos[i].getIdContenido() - 1]++;
            }
        }
    }

    peliculasActivasConConsumo = 0;
    for (int i = 0; i < cantRegistrosPeliculas; i++)
    {
        if (!pPeliculas[i].getEliminado() && pConsumosPorPelicula[i] > 0)
        {
            peliculasActivasConConsumo++;
        }
    }

    seriesActivasConConsumo = 0;
    for (int i = 0; i < cantRegistrosSeries; i++)
    {
        if (!pSeries[i].getEliminado() && pConsumosPorSerie[i] > 0)
        {
            seriesActivasConConsumo++;
        }
    }

    Pelicula* pPeliculasActivas = new Pelicula[peliculasActivasConConsumo];
    int* pConsumosPorPeliculaActiva = new int[peliculasActivasConConsumo];
    Serie* pSeriesActivas = new Serie[seriesActivasConConsumo];
    int* pConsumosPorSerieActiva = new int[seriesActivasConConsumo];

    if(pPeliculasActivas == nullptr || pConsumosPorPeliculaActiva == nullptr || pSeriesActivas == nullptr || pConsumosPorSerieActiva == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        delete [] pConsumosPorPelicula;
        delete [] pConsumosPorSerie;
        delete [] pConsumos;
        delete [] pPeliculas;
        delete [] pSeries;
        delete [] pPeliculasActivas;
        delete [] pConsumosPorPeliculaActiva;
        delete [] pSeriesActivas;
        delete [] pConsumosPorSerieActiva;
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    fila = 3;
    colId = 5;
    colTitulo = 30;
    colConsumos = 65;
    rlutil::locate(10, fila++);

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "================ TOP 10 PELICULAS MAS CONSUMIDAS ================" << endl;
    fila += 2;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(colId, fila);
    cout << "+++ " << anio << endl;
    fila++;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(colId, fila++);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::LIGHTBLUE);
    rlutil::locate(colId, fila);
    cout << "ID";
    rlutil::locate(colTitulo, fila);
    cout << "TITULO";
    rlutil::locate(colConsumos, fila++);
    cout << "CONSUMOS";
    rlutil::locate(colId, fila++);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);

    if (peliculasActivasConConsumo == 0)
    {
        rlutil::setColor(rlutil::RED);
        rlutil::locate(colId, fila);
        cout << "No hay consumos registrados en " << anio << " para peliculas activas." << endl;
        fila += 2;
    }
    else
    {
        id = 0;
        for (int i = 0; i < cantRegistrosPeliculas; i++)
        {
            if (!pPeliculas[i].getEliminado() && pConsumosPorPelicula[i] > 0)
            {
                pPeliculasActivas[id] = pPeliculas[i];
                pConsumosPorPeliculaActiva[id] = pConsumosPorPelicula[i];
                id++;
            }
        }

        for (int i = 0; i < peliculasActivasConConsumo - 1; i++)
        {
            for (int j = i + 1; j < peliculasActivasConConsumo; j++)
            {
                if (pConsumosPorPeliculaActiva[j] > pConsumosPorPeliculaActiva[i])
                {
                    int aux1 = pConsumosPorPeliculaActiva[i];
                    pConsumosPorPeliculaActiva[i] = pConsumosPorPeliculaActiva[j];
                    pConsumosPorPeliculaActiva[j] = aux1;

                    Pelicula aux2 = pPeliculasActivas[i];
                    pPeliculasActivas[i] = pPeliculasActivas[j];
                    pPeliculasActivas[j] = aux2;
                }
            }
        }

        limite = (peliculasActivasConConsumo < 10) ? peliculasActivasConConsumo : 10;
        for(int i = 0; i < limite; i++)
        {
            rlutil::locate(colId, fila);
            cout << pPeliculasActivas[i].getId();
            rlutil::locate(colTitulo, fila);
            cout << pPeliculasActivas[i].getTitulo();
            rlutil::locate(colConsumos + 2, fila++);
            cout << pConsumosPorPeliculaActiva[i] << endl;
            fila++;
        }
    }
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(colId, fila++);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::YELLOW);
    fila += 5;
    rlutil::locate(10, fila++);
    cout << "================ TOP 10 SERIES MAS CONSUMIDAS ================" << endl;
    fila += 2;
    rlutil::setColor(rlutil::CYAN);
    fila++;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(colId, fila++);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::LIGHTBLUE);
    rlutil::locate(colId, fila);
    cout << "ID";
    rlutil::locate(colTitulo, fila);
    cout << "TITULO";
    rlutil::locate(colConsumos, fila++);
    cout << "CONSUMOS";
    rlutil::locate(colId, fila++);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);

    if (seriesActivasConConsumo == 0)
    {
        rlutil::setColor(rlutil::RED);
        rlutil::locate(colId, fila);
        cout << "No hay consumos registrados en " << anio << " para series activas." << endl;
        fila += 2;
    }
    else
    {
        id = 0;
        for (int i = 0; i < cantRegistrosSeries; i++)
        {
            if (!pSeries[i].getEliminado() && pConsumosPorSerie[i] > 0)
            {
                pSeriesActivas[id] = pSeries[i];
                pConsumosPorSerieActiva[id] = pConsumosPorSerie[i];
                id++;
            }
        }

        for (int i = 0; i < seriesActivasConConsumo - 1; i++)
        {
            for (int j = i + 1; j < seriesActivasConConsumo; j++)
            {
                if (pConsumosPorSerieActiva[j] > pConsumosPorSerieActiva[i])
                {
                    int aux1 = pConsumosPorSerieActiva[i];
                    pConsumosPorSerieActiva[i] = pConsumosPorSerieActiva[j];
                    pConsumosPorSerieActiva[j] = aux1;

                    Serie aux2 = pSeriesActivas[i];
                    pSeriesActivas[i] = pSeriesActivas[j];
                    pSeriesActivas[j] = aux2;
                }
            }
        }

        limite = (seriesActivasConConsumo < 10) ? seriesActivasConConsumo : 10;
        for(int i = 0; i < limite; i++)
        {
            rlutil::locate(colId, fila);
            cout << pSeriesActivas[i].getId();
            rlutil::locate(colTitulo, fila);
            cout << pSeriesActivas[i].getTitulo();
            rlutil::locate(colConsumos + 2, fila++);
            cout << pConsumosPorSerieActiva[i] << endl;
            fila++;
        }
    }
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(colId, fila++);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;
    delete [] pConsumosPorPelicula;
    delete [] pConsumosPorSerie;
    delete [] pConsumos;
    delete [] pPeliculas;
    delete [] pSeries;
    delete [] pPeliculasActivas;
    delete [] pConsumosPorPeliculaActiva;
    delete [] pSeriesActivas;
    delete [] pConsumosPorSerieActiva;
}

void ReportesManager::consumosPorGenero(int anio)
{
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    int cantRegistrosGenero = _repoGenero.getCantidadRegistros();
    int cantRegistrosPeliculas = _repoPelicula.getCantidadRegistros();
    int cantRegistrosSeries = _repoSerie.getCantidadRegistros();
    int totalConsumos = 0;
    int fila, colGenero, colConsumos, colPorcentaje;
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];
    Genero* pGeneros = new Genero [cantRegistrosGenero];
    int* pConsumosPorGenero = new int [cantRegistrosGenero] {};
    Pelicula* pPeliculas = new Pelicula [cantRegistrosPeliculas];
    Serie* pSeries = new Serie [cantRegistrosSeries];

    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorGenero;
        delete [] pConsumos;
        delete [] pGeneros;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }
    if(cantRegistrosPeliculas == 0 && cantRegistrosSeries == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay contenidos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorGenero;
        delete [] pConsumos;
        delete [] pGeneros;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }
    if(cantRegistrosGenero == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay generos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorGenero;
        delete [] pConsumos;
        delete [] pGeneros;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }

    if(pConsumos == nullptr || pGeneros == nullptr || pConsumosPorGenero == nullptr || pPeliculas == nullptr || pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorGenero;
        delete [] pConsumos;
        delete [] pGeneros;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }

    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);
    _repoGenero.leer(pGeneros, cantRegistrosGenero);
    _repoPelicula.leer(pPeliculas, cantRegistrosPeliculas);
    _repoSerie.leer(pSeries, cantRegistrosSeries);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getFechaAcceso().getAnio() == anio)
        {
            if(pConsumos[i].getIdTipoContenido() == 1 && !pPeliculas[pConsumos[i].getIdContenido() - 1].getEliminado() && !pGeneros[pPeliculas[pConsumos[i].getIdContenido() - 1].getGenero()].getEliminado())
            {
                pConsumosPorGenero[pPeliculas[pConsumos[i].getIdContenido() - 1].getGenero() - 1]++;
                totalConsumos++;
            }
            if(pConsumos[i].getIdTipoContenido() == 2 && !pSeries[pConsumos[i].getIdContenido() - 1].getEliminado() && !pGeneros[pSeries[pConsumos[i].getIdContenido() - 1].getGenero()].getEliminado())
            {
                pConsumosPorGenero[pSeries[pConsumos[i].getIdContenido() - 1].getGenero() - 1]++;
                totalConsumos++;
            }
        }
    }

    fila = 3;
    colGenero = 5;
    colConsumos = 30;
    colPorcentaje = 50;

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(10, fila++);
    cout << "================ CONSUMOS POR GENERO ================" << endl;
    fila += 2;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(colGenero, fila);
    cout << "+++ " << anio << endl;
    rlutil::locate(colPorcentaje, fila++);
    cout << "TOTAL CONSUMOS: " << totalConsumos;
    fila++;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(colGenero, fila++);
    cout << "----------------------------------------------------------";
    rlutil::setColor(rlutil::LIGHTBLUE);
    rlutil::locate(colGenero, fila);
    cout << "GENERO";
    rlutil::locate(colConsumos, fila);
    cout << "CONSUMOS";
    rlutil::locate(colPorcentaje, fila++);
    cout << "PORCENTAJE";
    rlutil::locate(colGenero, fila++);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "----------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);

    if(totalConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "NO SE ENCONTRARON CONSUMOS POR GENERO PARA MOSTRAR..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumosPorGenero;
        delete [] pConsumos;
        delete [] pGeneros;
        delete [] pPeliculas;
        delete [] pSeries;
        return;
    }

    for(int i = 0; i < cantRegistrosGenero; i++)
    {
        if(pGeneros[i].getEliminado()) continue;
        rlutil::locate(colGenero, fila);
        cout << pGeneros[i].getDescripcion();
        rlutil::locate(colConsumos, fila);
        cout << pConsumosPorGenero[i];
        rlutil::locate(colPorcentaje, fila);
        cout << (float)pConsumosPorGenero[i] / totalConsumos * 100 << " %" << endl;
        fila++;
    }

    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(colGenero, fila++);
    cout << "----------------------------------------------------------";
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pConsumosPorGenero;
    delete [] pConsumos;
    delete [] pGeneros;
    delete [] pPeliculas;
    delete [] pSeries;
}

void ReportesManager::minutosConsumidosPorTipoContenido(int anio)
{
    string meses[12] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
    int minutosConsumidosPeliculas[12] = {};
    int minutosConsumidosSeries[12] = {};
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];
    int filaBase;

    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    if(pConsumos == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getFechaAcceso().getAnio() == anio)
        {
            if(pConsumos[i].getIdTipoContenido() == 1)
            {
                minutosConsumidosPeliculas[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
            }
            else if(pConsumos[i].getIdTipoContenido() == 2)
            {
                minutosConsumidosSeries[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
            }
        }
    }

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "================ CONSUMOS POR TIPO DE CONTENIDO ================" << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << endl;
    cout << "++++++ CONSUMOS MENSUALES DE " << anio << endl;
    cout << endl;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << endl;
    cout << "++++++++++++++++++++++++++++++++++++" << endl;
    cout << "+++ PELICULAS:             ++++++++" << endl;
    rlutil::setColor(rlutil::GREEN);

    filaBase = 10;
    for(int i = 0; i < 12; i++)
    {
        rlutil::locate(5, filaBase + i);
        cout << "+++ " << meses[i];
        rlutil::locate(25, filaBase + i);
        cout << minutosConsumidosPeliculas[i] << " MINUTO/S";
    }
    filaBase += 18;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(1, filaBase - 4);
    cout << endl;
    cout << "+++ SERIES:                ++++++++" << endl;
    rlutil::setColor(rlutil::GREEN);

    for(int i = 0; i < 12; i++)
    {
        rlutil::locate(5, filaBase + i);
        cout << "+++ " << meses[i];
        rlutil::locate(25, filaBase + i);
        cout << minutosConsumidosSeries[i] << " MINUTO/S";
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pConsumos;
}

void ReportesManager::promedioMensualMinutosConsumidosPorTipoSuscripcion(int anio)
{
    string meses[12] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
    int minutosConsumidosBasico[12] = {};
    int minutosConsumidosEstandar[12] = {};
    int minutosConsumidosPremium[12] = {};
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    int cantRegistrosSuscriptores = _repoSuscriptor.getCantidadRegistros();
    int totalMinutosPorMes[12] = {};
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];
    Suscriptor* pSuscriptores = new Suscriptor [cantRegistrosConsumos];
    int filaBase;

    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumos;
        delete [] pSuscriptores;
        return;
    }
    if(cantRegistrosSuscriptores == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay suscriptores cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumos;
        delete [] pSuscriptores;
        return;
    }
    if(pConsumos == nullptr || pSuscriptores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        delete [] pConsumos;
        delete [] pSuscriptores;
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);
    _repoSuscriptor.leer(pSuscriptores, cantRegistrosSuscriptores);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getFechaAcceso().getAnio() == anio)
        {
            if(pSuscriptores[pConsumos[i].getIdSuscriptor() - 1].getTipoSuscripcion() == 1 && !pSuscriptores[pConsumos[i].getIdSuscriptor() - 1].getEliminado())
            {
                minutosConsumidosBasico[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
                totalMinutosPorMes[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
            }
            else if(pSuscriptores[pConsumos[i].getIdSuscriptor() - 1].getTipoSuscripcion() == 2 && !pSuscriptores[pConsumos[i].getIdSuscriptor() - 1].getEliminado())
            {
                minutosConsumidosEstandar[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
                totalMinutosPorMes[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
            }
            else if(pSuscriptores[pConsumos[i].getIdSuscriptor() - 1].getTipoSuscripcion() == 3 && !pSuscriptores[pConsumos[i].getIdSuscriptor() - 1].getEliminado())
            {
                minutosConsumidosPremium[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
                totalMinutosPorMes[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
            }
        }
    }

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "================ CONSUMO PROMEDIO MENSUAL POR TIPO DE SUSCRIPCION ================" << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << endl;
    cout << "++++++ " << anio << endl;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(5, 7);
    cout << "MES";
    rlutil::locate(25, 7);
    cout << "BASICO";
    rlutil::locate(40, 7);
    cout << "ESTANDAR";
    rlutil::locate(55, 7);
    cout << "PREMIUM";
    cout << endl;
    rlutil::setColor(rlutil::GREEN);
    filaBase = 9;

    for (int i = 0; i < 12; i++)
    {
        rlutil::locate(5, filaBase + i);
        cout << meses[i];
        if (totalMinutosPorMes[i] == 0)
        {
            rlutil::locate(30, filaBase + i);
            cout << "         SIN CONSUMOS";
            continue;
        }
        rlutil::locate(25, filaBase + i);
        cout << (float)minutosConsumidosBasico[i] / totalMinutosPorMes[i] * 100;
        rlutil::locate(40, filaBase + i);
        cout << (float)minutosConsumidosEstandar[i] / totalMinutosPorMes[i] * 100;
        rlutil::locate(55, filaBase + i);
        cout << (float)minutosConsumidosPremium[i] / totalMinutosPorMes[i] * 100;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pConsumos;
    delete [] pSuscriptores;
}

void ReportesManager::promedioDiarioMinutosConsumidosPorSuscriptor(int mes, int anio)
{
    int diasPorMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) diasPorMes[1] = 29;
    string meses[12] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
    int cantRegistrosSuscriptores = _repoSuscriptor.getCantidadRegistros();
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    int* pMinutosConsumidosPorSuscriptor = new int [cantRegistrosSuscriptores] {};
    Suscriptor* pSuscriptores = new Suscriptor [cantRegistrosSuscriptores];
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];

    if(cantRegistrosSuscriptores == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay suscriptores cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pMinutosConsumidosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        return;
    }
    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pMinutosConsumidosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        return;
    }
    if(pMinutosConsumidosPorSuscriptor == nullptr || pSuscriptores == nullptr || pConsumos == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        delete [] pMinutosConsumidosPorSuscriptor;
        delete [] pSuscriptores;
        delete [] pConsumos;
        rlutil::setColor(rlutil::WHITE);
        return;
    }

    _repoSuscriptor.leer(pSuscriptores, cantRegistrosSuscriptores);
    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getFechaAcceso().getAnio() == anio && pConsumos[i].getFechaAcceso().getMes() == mes)
        {
            pMinutosConsumidosPorSuscriptor[pConsumos[i].getIdSuscriptor() - 1] += pConsumos[i].getDuracionVista();
        }
    }

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "==================== PROMEDIO DIARIO DE TIEMPO CONSUMIDO POR SUSCRIPTOR ====================" << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << endl;
    cout << "++++++ " << meses[mes - 1] << endl;
    cout << endl;
    cout << "++++++ " << anio << endl;
    rlutil::setColor(rlutil::GREEN);
    cout << endl;

    for(int i = 0; i < cantRegistrosSuscriptores; i++)
    {
        if(pSuscriptores[i].getEliminado()) continue;
        string email = pSuscriptores[i].getEmail();
        int anchoColumna = 25;
        int espacios = anchoColumna - email.length();
        if (espacios < 1) espacios = 1;
        cout << "ID #" << i + 1 << ":   " << email;
        for (int j = 0; j < espacios; j++) cout << ' ';
        cout << "->          MINUTOS CONSUMIDOS:   " << (float)pMinutosConsumidosPorSuscriptor[i] / diasPorMes[mes - 1] << endl;
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pMinutosConsumidosPorSuscriptor;
    delete [] pSuscriptores;
    delete [] pConsumos;
}

void ReportesManager::porcentajeMensualTiempoConsumidoPorTipoContenido(int anio)
{
    string meses[12] = {"ENERO", "FEBRERO", "MARZO", "ABRIL", "MAYO", "JUNIO", "JULIO", "AGOSTO", "SEPTIEMBRE", "OCTUBRE", "NOVIEMBRE", "DICIEMBRE"};
    int minutosConsumidosPeliculas[12] = {};
    int minutosConsumidosSeries[12] = {};
    int cantRegistrosConsumos = _repoConsumo.getCantidadRegistros();
    Consumo* pConsumos = new Consumo [cantRegistrosConsumos];
    int filaBase;

    if(cantRegistrosConsumos == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos cargados..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    if(pConsumos == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pConsumos;
        return;
    }

    _repoConsumo.leer(pConsumos, cantRegistrosConsumos);

    for(int i = 0; i < cantRegistrosConsumos; i++)
    {
        if(!pConsumos[i].getEliminado() && pConsumos[i].getFechaAcceso().getAnio() == anio)
        {
            if(pConsumos[i].getIdTipoContenido() == 1)
            {
                minutosConsumidosPeliculas[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
            }
            else if(pConsumos[i].getIdTipoContenido() == 2)
            {
                minutosConsumidosSeries[pConsumos[i].getFechaAcceso().getMes() - 1] += pConsumos[i].getDuracionVista();
            }
        }
    }

    system("cls");
    rlutil::setColor(rlutil::YELLOW);
    cout << "================ DISTRIBUCION MENSUAL POR TIPO DE CONTENIDO ================" << endl;
    rlutil::setColor(rlutil::CYAN);
    cout << endl;
    cout << "++++++ " << anio << endl;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    rlutil::locate(5, 7);
    cout << "MES";
    rlutil::locate(30, 7);
    cout << "PELICULAS (%)";
    rlutil::locate(50, 7);
    cout << "SERIES (%)";
    cout << endl;
    rlutil::setColor(rlutil::GREEN);
    filaBase = 9;

    for (int i = 0; i < 12; i++)
    {
        int totalMes = minutosConsumidosPeliculas[i] + minutosConsumidosSeries[i];
        rlutil::locate(5, filaBase + i);
        cout << meses[i];
        if (totalMes == 0)
        {
            rlutil::locate(25, filaBase + i);
            cout << "             SIN CONSUMOS";
            continue;
        }
        rlutil::locate(33, filaBase + i);
        cout << (float)minutosConsumidosPeliculas[i] / totalMes * 100 << "% ";
        rlutil::locate(53, filaBase + i);
        cout << (float)minutosConsumidosSeries[i] / totalMes * 100 << "% ";
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pConsumos;
}
