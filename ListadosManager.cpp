#include <iostream>
#include "ListadosManager.h"
#include "rlutil.h"

using namespace std;

void ListadosManager::listarSuscriptoresApellido()
{
    int cantRegistros = _repoSuscriptor.getCantidadRegistros();
    Suscriptor* pSuscriptores = new Suscriptor [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay suscriptores para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSuscriptores;
        return;
    }
    if(pSuscriptores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSuscriptores;
        return;
    }

    _repoSuscriptor.leer(pSuscriptores, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (strcasecmp(pSuscriptores[i].getApellido(), pSuscriptores[j].getApellido()) > 0)
            {
                Suscriptor aux = pSuscriptores[i];
                pSuscriptores[i] = pSuscriptores[j];
                pSuscriptores[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "==================================== LISTADO DE SUSCRIPTORES ====================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(10, 5);
    cout << "NOMBRE";
    rlutil::locate(20, 5);
    cout << "APELLIDO";
    rlutil::locate(30, 5);
    cout << "EMAIL";
    rlutil::locate(50, 5);
    cout << "TEL";
    rlutil::locate(65, 5);
    cout << "ALTA";
    rlutil::locate(80, 5);
    cout << "TIPO SUSC";
    rlutil::locate(95, 5);
    cout << "ELIMINADO";
    rlutil::locate(100, 5);
    rlutil::locate(5, 6);
    cout << "--------------------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pSuscriptores[i].getId();
        rlutil::locate(10, 7 + i);
        cout << pSuscriptores[i].getNombre();
        rlutil::locate(20, 7 + i);
        cout << pSuscriptores[i].getApellido();
        rlutil::locate(30, 7 + i);
        cout << pSuscriptores[i].getEmail();
        rlutil::locate(50, 7 + i);
        cout << pSuscriptores[i].getTelefono();
        rlutil::locate(65, 7 + i);
        pSuscriptores[i].getFechaAlta().mostrar();
        rlutil::locate(80, 7 + i);
        if (pSuscriptores[i].getTipoSuscripcion() == 1) cout << "BASICO";
        else if (pSuscriptores[i].getTipoSuscripcion() == 2) cout << "ESTANDAR";
        else if (pSuscriptores[i].getTipoSuscripcion() == 3) cout << "PREMIUM";
        rlutil::locate(95, 7 + i);
        cout << (pSuscriptores[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(100, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pSuscriptores;
}

void ListadosManager::listarSuscriptoresFechaAlta(bool criterio(Fecha, Fecha))
{
    int cantRegistros = _repoSuscriptor.getCantidadRegistros();
    Suscriptor* pSuscriptores = new Suscriptor [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay suscriptores para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSuscriptores;
        return;
    }
    if(pSuscriptores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSuscriptores;
        return;
    }

    _repoSuscriptor.leer(pSuscriptores, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (criterio(pSuscriptores[j].getFechaAlta(), pSuscriptores[i].getFechaAlta()))
            {
                Suscriptor aux = pSuscriptores[i];
                pSuscriptores[i] = pSuscriptores[j];
                pSuscriptores[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "==================================== LISTADO DE SUSCRIPTORES ====================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(10, 5);
    cout << "NOMBRE";
    rlutil::locate(20, 5);
    cout << "APELLIDO";
    rlutil::locate(30, 5);
    cout << "EMAIL";
    rlutil::locate(50, 5);
    cout << "TEL";
    rlutil::locate(65, 5);
    cout << "ALTA";
    rlutil::locate(80, 5);
    cout << "TIPO SUSC";
    rlutil::locate(95, 5);
    cout << "ELIMINADO";
    rlutil::locate(100, 5);
    rlutil::locate(5, 6);
    cout << "--------------------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pSuscriptores[i].getId();
        rlutil::locate(10, 7 + i);
        cout << pSuscriptores[i].getNombre();
        rlutil::locate(20, 7 + i);
        cout << pSuscriptores[i].getApellido();
        rlutil::locate(30, 7 + i);
        cout << pSuscriptores[i].getEmail();
        rlutil::locate(50, 7 + i);
        cout << pSuscriptores[i].getTelefono();
        rlutil::locate(65, 7 + i);
        pSuscriptores[i].getFechaAlta().mostrar();
        rlutil::locate(80, 7 + i);
        if (pSuscriptores[i].getTipoSuscripcion() == 1) cout << "BASICO";
        else if (pSuscriptores[i].getTipoSuscripcion() == 2) cout << "ESTANDAR";
        else if (pSuscriptores[i].getTipoSuscripcion() == 3) cout << "PREMIUM";
        rlutil::locate(95, 7 + i);
        cout << (pSuscriptores[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(100, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pSuscriptores;
}

void ListadosManager::listarPeliculasTitulo()
{
    int cantRegistros = _repoPelicula.getCantidadRegistros();
    Pelicula* pPeliculas = new Pelicula [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay peliculas para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pPeliculas;
        return;
    }
    if(pPeliculas == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pPeliculas;
        return;
    }

    _repoPelicula.leer(pPeliculas, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (strcasecmp(pPeliculas[i].getTitulo(), pPeliculas[j].getTitulo()) > 0)
            {
                Pelicula aux = pPeliculas[i];
                pPeliculas[i] = pPeliculas[j];
                pPeliculas[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "================================ LISTADO DE PELICULAS ================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "TITULO";
    rlutil::locate(40, 5);
    cout << "ESTRENO";
    rlutil::locate(55, 5);
    cout << "DURACION";
    rlutil::locate(70, 5);
    cout << "ELIMINADO";
    rlutil::locate(80, 5);
    rlutil::locate(5, 6);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pPeliculas[i].getId();
        rlutil::locate(15, 7 + i);
        cout << pPeliculas[i].getTitulo();
        rlutil::locate(40, 7 + i);
        pPeliculas[i].getFechaEstreno().mostrar();
        rlutil::locate(55, 7 + i);
        cout << pPeliculas[i].getDuracion() << " min";
        rlutil::locate(70, 7 + i);
        cout << (pPeliculas[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(80, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pPeliculas;
}

void ListadosManager::listarPeliculasFechaEstreno(bool criterio(Fecha, Fecha))
{
    int cantRegistros = _repoPelicula.getCantidadRegistros();
    Pelicula* pPeliculas = new Pelicula [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay peliculas para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pPeliculas;
        return;
    }
    if(pPeliculas == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pPeliculas;
        return;
    }

    _repoPelicula.leer(pPeliculas, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (criterio(pPeliculas[j].getFechaEstreno(), pPeliculas[i].getFechaEstreno()))
            {
                Pelicula aux = pPeliculas[i];
                pPeliculas[i] = pPeliculas[j];
                pPeliculas[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "================================ LISTADO DE PELICULAS ================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "TITULO";
    rlutil::locate(40, 5);
    cout << "ESTRENO";
    rlutil::locate(55, 5);
    cout << "DURACION";
    rlutil::locate(70, 5);
    cout << "ELIMINADO";
    rlutil::locate(80, 5);
    rlutil::locate(5, 6);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pPeliculas[i].getId();
        rlutil::locate(15, 7 + i);
        cout << pPeliculas[i].getTitulo();
        rlutil::locate(40, 7 + i);
        pPeliculas[i].getFechaEstreno().mostrar();
        rlutil::locate(55, 7 + i);
        cout << pPeliculas[i].getDuracion() << " min";
        rlutil::locate(70, 7 + i);
        cout << (pPeliculas[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(80, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pPeliculas;
}

void ListadosManager::listarPeliculasDuracion(bool criterio(int, int))
{
    int cantRegistros = _repoPelicula.getCantidadRegistros();
    Pelicula* pPeliculas = new Pelicula [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay peliculas para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pPeliculas;
        return;
    }
    if(pPeliculas == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pPeliculas;
        return;
    }

    _repoPelicula.leer(pPeliculas, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (criterio(pPeliculas[j].getDuracion(), pPeliculas[i].getDuracion()))
            {
                Pelicula aux = pPeliculas[i];
                pPeliculas[i] = pPeliculas[j];
                pPeliculas[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "================================ LISTADO DE PELICULAS ================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "TITULO";
    rlutil::locate(40, 5);
    cout << "ESTRENO";
    rlutil::locate(55, 5);
    cout << "DURACION";
    rlutil::locate(70, 5);
    cout << "ELIMINADO";
    rlutil::locate(80, 5);
    rlutil::locate(5, 6);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pPeliculas[i].getId();
        rlutil::locate(15, 7 + i);
        cout << pPeliculas[i].getTitulo();
        rlutil::locate(40, 7 + i);
        pPeliculas[i].getFechaEstreno().mostrar();
        rlutil::locate(55, 7 + i);
        cout << pPeliculas[i].getDuracion() << " min";
        rlutil::locate(70, 7 + i);
        cout << (pPeliculas[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(80, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pPeliculas;
}

void ListadosManager::listarSeriesTitulo()
{
    int cantRegistros = _repoSerie.getCantidadRegistros();
    Serie* pSeries = new Serie [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay series para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSeries;
        return;
    }
    if(pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSeries;
        return;
    }

    _repoSerie.leer(pSeries, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (strcasecmp(pSeries[i].getTitulo(), pSeries[j].getTitulo()) > 0)
            {
                Serie aux = pSeries[i];
                pSeries[i] = pSeries[j];
                pSeries[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "================================ LISTADO DE SERIES ================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "TITULO";
    rlutil::locate(40, 5);
    cout << "ESTRENO";
    rlutil::locate(55, 5);
    cout << "TEMPS";
    rlutil::locate(70, 5);
    cout << "CAPS";
    rlutil::locate(80, 5);
    cout << "ELIMINADO";
    rlutil::locate(85, 5);
    rlutil::locate(5, 6);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pSeries[i].getId();
        rlutil::locate(15, 7 + i);
        cout << pSeries[i].getTitulo();
        rlutil::locate(40, 7 + i);
        pSeries[i].getFechaEstreno().mostrar();
        rlutil::locate(55, 7 + i);
        cout << pSeries[i].getTemporadas();
        rlutil::locate(70, 7 + i);
        cout << pSeries[i].getCapitulos();
        rlutil::locate(80, 7 + i);
        cout << (pSeries[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(85, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pSeries;
}

void ListadosManager::listarSeriesFechaEstreno(bool criterio(Fecha, Fecha))
{
    int cantRegistros = _repoSerie.getCantidadRegistros();
    Serie* pSeries = new Serie [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay series para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSeries;
        return;
    }
    if(pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSeries;
        return;
    }

    _repoSerie.leer(pSeries, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (criterio(pSeries[j].getFechaEstreno(), pSeries[i].getFechaEstreno()))
            {
                Serie aux = pSeries[i];
                pSeries[i] = pSeries[j];
                pSeries[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "================================ LISTADO DE SERIES ================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "TITULO";
    rlutil::locate(40, 5);
    cout << "ESTRENO";
    rlutil::locate(55, 5);
    cout << "TEMPS";
    rlutil::locate(70, 5);
    cout << "CAPS";
    rlutil::locate(80, 5);
    cout << "ELIMINADO";
    rlutil::locate(85, 5);
    rlutil::locate(5, 6);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pSeries[i].getId();
        rlutil::locate(15, 7 + i);
        cout << pSeries[i].getTitulo();
        rlutil::locate(40, 7 + i);
        pSeries[i].getFechaEstreno().mostrar();
        rlutil::locate(55, 7 + i);
        cout << pSeries[i].getTemporadas();
        rlutil::locate(70, 7 + i);
        cout << pSeries[i].getCapitulos();
        rlutil::locate(80, 7 + i);
        cout << (pSeries[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(85, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pSeries;
}

void ListadosManager::listarSeriesCapitulos(bool criterio(int, int))
{
    int cantRegistros = _repoSerie.getCantidadRegistros();
    Serie* pSeries = new Serie [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay series para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSeries;
        return;
    }
    if(pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pSeries;
        return;
    }

    _repoSerie.leer(pSeries, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (criterio(pSeries[j].getCapitulos(), pSeries[i].getCapitulos()))
            {
                Serie aux = pSeries[i];
                pSeries[i] = pSeries[j];
                pSeries[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "================================ LISTADO DE SERIES ================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "TITULO";
    rlutil::locate(40, 5);
    cout << "ESTRENO";
    rlutil::locate(55, 5);
    cout << "TEMPS";
    rlutil::locate(70, 5);
    cout << "CAPS";
    rlutil::locate(80, 5);
    cout << "ELIMINADO";
    rlutil::locate(85, 5);
    rlutil::locate(5, 6);
    cout << "-------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pSeries[i].getId();
        rlutil::locate(15, 7 + i);
        cout << pSeries[i].getTitulo();
        rlutil::locate(40, 7 + i);
        pSeries[i].getFechaEstreno().mostrar();
        rlutil::locate(55, 7 + i);
        cout << pSeries[i].getTemporadas();
        rlutil::locate(70, 7 + i);
        cout << pSeries[i].getCapitulos();
        rlutil::locate(80, 7 + i);
        cout << (pSeries[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(85, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pSeries;
}

void ListadosManager::listarDirectoresApellido()
{
    int cantRegistros = _repoDirector.getCantidadRegistros();
    Director* pDirectores = new Director [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay directores para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pDirectores;
        return;
    }
    if(pDirectores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pDirectores;
        return;
    }

    _repoDirector.leer(pDirectores, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (strcasecmp(pDirectores[i].getApellido(), pDirectores[j].getApellido()) > 0)
            {
                Director aux = pDirectores[i];
                pDirectores[i] = pDirectores[j];
                pDirectores[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "==================================== LISTADO DE DIRECTORES ====================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(10, 5);
    cout << "NOMBRE";
    rlutil::locate(25, 5);
    cout << "APELLIDO";
    rlutil::locate(40, 5);
    cout << "NACIONALIDAD";
    rlutil::locate(55, 5);
    cout << "FECHA NAC";
    rlutil::locate(70, 5);
    cout << "RESIDENCIA";
    rlutil::locate(85, 5);
    cout << "ELIMINADO";
    rlutil::locate(95, 5);
    rlutil::locate(5, 6);
    cout << "------------------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pDirectores[i].getId();
        rlutil::locate(10, 7 + i);
        cout << pDirectores[i].getNombre();
        rlutil::locate(25, 7 + i);
        cout << pDirectores[i].getApellido();
        rlutil::locate(40, 7 + i);
        cout << pDirectores[i].getNacionalidad();
        rlutil::locate(55, 7 + i);
        pDirectores[i].getFechaNacimiento().mostrar();
        rlutil::locate(70, 7 + i);
        cout << pDirectores[i].getPaisResidencia();
        rlutil::locate(85, 7 + i);
        cout << (pDirectores[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(95, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pDirectores;
}

void ListadosManager::listarConsumosFechaAcceso(bool criterio(Fecha, Fecha, Hora, Hora))
{
    int cantRegistros = _repoConsumo.getCantidadRegistros();
    Consumo* pConsumos = new Consumo [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos para listar..." << endl;
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

    _repoConsumo.leer(pConsumos, cantRegistros);

    for(int i = 0; i < cantRegistros - 1; i++)
    {
        for(int j = i + 1; j < cantRegistros; j++)
        {
            if (criterio(pConsumos[j].getFechaAcceso(), pConsumos[i].getFechaAcceso(), pConsumos[j].getHoraAcceso(), pConsumos[i].getHoraAcceso()))
            {
                Consumo aux = pConsumos[i];
                pConsumos[i] = pConsumos[j];
                pConsumos[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "==================================== LISTADO DE CONSUMOS ====================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(10, 5);
    cout << "SUSC.";
    rlutil::locate(20, 5);
    cout << "CONT.";
    rlutil::locate(30, 5);
    cout << "TIPO CONT.";
    rlutil::locate(50, 5);
    cout << "FECHA ACCESO";
    rlutil::locate(65, 5);
    cout << "HORA ACCESO";
    rlutil::locate(80, 5);
    cout << "DUR. VISTA";
    rlutil::locate(95, 5);
    cout << "ELIMINADO";
    rlutil::locate(100, 5);
    rlutil::locate(5, 6);
    cout << "--------------------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pConsumos[i].getIdAcceso();
        rlutil::locate(12, 7 + i);
        cout << pConsumos[i].getIdSuscriptor();
        rlutil::locate(22, 7 + i);
        cout << pConsumos[i].getIdContenido();
        rlutil::locate(30, 7 + i);
        if (pConsumos[i].getIdTipoContenido() == 1) cout << "PELICULA";
        else if (pConsumos[i].getIdTipoContenido() == 2) cout << "SERIE";
        rlutil::locate(50, 7 + i);
        pConsumos[i].getFechaAcceso().mostrar();
        rlutil::locate(65, 7 + i);
        pConsumos[i].getHoraAcceso().mostrar();
        rlutil::locate(80, 7 + i);
        cout << pConsumos[i].getDuracionVista() << " min";
        rlutil::locate(95, 7 + i);
        cout << (pConsumos[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(100, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pConsumos;
}

void ListadosManager::listarConsumosIdSuscriptor()
{
    int cantRegistros = _repoConsumo.getCantidadRegistros();
    Consumo* pConsumos = new Consumo [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay consumos para listar..." << endl;
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

    _repoConsumo.leer(pConsumos, cantRegistros);

    for (int i = 0; i < cantRegistros - 1; i++)
    {
        for (int j = i + 1; j < cantRegistros; j++)
        {
            bool intercambiar = false;
            if (pConsumos[j].getIdSuscriptor() < pConsumos[i].getIdSuscriptor())
            {
                intercambiar = true;
            }
            else if (pConsumos[j].getIdSuscriptor() == pConsumos[i].getIdSuscriptor())
            {
                if (pConsumos[j].getFechaAcceso() < pConsumos[i].getFechaAcceso())
                {
                    intercambiar = true;
                }
                else if (pConsumos[j].getFechaAcceso() == pConsumos[i].getFechaAcceso())
                {
                    if (pConsumos[j].getHoraAcceso() < pConsumos[i].getHoraAcceso())
                    {
                        intercambiar = true;
                    }
                }
            }
            if (intercambiar)
            {
                Consumo aux = pConsumos[i];
                pConsumos[i] = pConsumos[j];
                pConsumos[j] = aux;
            }
        }
    }

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "==================================== LISTADO DE CONSUMOS ====================================" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(10, 5);
    cout << "SUSC.";
    rlutil::locate(20, 5);
    cout << "CONT.";
    rlutil::locate(30, 5);
    cout << "TIPO CONT.";
    rlutil::locate(50, 5);
    cout << "FECHA ACCESO";
    rlutil::locate(65, 5);
    cout << "HORA ACCESO";
    rlutil::locate(80, 5);
    cout << "DUR. VISTA";
    rlutil::locate(95, 5);
    cout << "ELIMINADO";
    rlutil::locate(100, 5);
    rlutil::locate(5, 6);
    cout << "--------------------------------------------------------------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pConsumos[i].getIdAcceso();
        rlutil::locate(12, 7 + i);
        cout << pConsumos[i].getIdSuscriptor();
        rlutil::locate(22, 7 + i);
        cout << pConsumos[i].getIdContenido();
        rlutil::locate(30, 7 + i);
        if (pConsumos[i].getIdTipoContenido() == 1) cout << "PELICULA";
        else if (pConsumos[i].getIdTipoContenido() == 2) cout << "SERIE";
        rlutil::locate(50, 7 + i);
        pConsumos[i].getFechaAcceso().mostrar();
        rlutil::locate(65, 7 + i);
        pConsumos[i].getHoraAcceso().mostrar();
        rlutil::locate(80, 7 + i);
        cout << pConsumos[i].getDuracionVista() << " min";
        rlutil::locate(95, 7 + i);
        cout << (pConsumos[i].getEliminado() ? "SI" : "NO");
        rlutil::locate(100, 7 + i);
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pConsumos;
}

void ListadosManager::listarGeneros()
{
    int cantRegistros = _repoGenero.getCantidadRegistros();
    Genero* pGeneros = new Genero [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay generos para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pGeneros;
        return;
    }
    if(pGeneros == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pGeneros;
        return;
    }

    _repoGenero.leer(pGeneros, cantRegistros);

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "============= LISTADO DE GENEROS =============" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "DESCRIPCION";
    rlutil::locate(40, 5);
    cout << "ELIMINADO";
    rlutil::locate(5, 6);
    cout << "----------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pGeneros[i].getIdGenero();
        rlutil::locate(15, 7 + i);
        cout << pGeneros[i].getDescripcion();
        rlutil::locate(43, 7 + i);
        cout << (pGeneros[i].getEliminado() ? "SI" : "NO");
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pGeneros;
}

void ListadosManager::listarClasificaciones()
{
    int cantRegistros = _repoClasificacion.getCantidadRegistros();
    Clasificacion* pClasificaciones = new Clasificacion [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay clasificaciones para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pClasificaciones;
        return;
    }
    if(pClasificaciones == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pClasificaciones;
        return;
    }

    _repoClasificacion.leer(pClasificaciones, cantRegistros);

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "======== LISTADO DE CLASIFICACIONES ========" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "DESCRIPCION";
    rlutil::locate(40, 5);
    cout << "ELIMINADO";
    rlutil::locate(5, 6);
    cout << "----------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pClasificaciones[i].getIdClasificacion();
        rlutil::locate(18, 7 + i);
        cout << pClasificaciones[i].getDescripcion();
        rlutil::locate(43, 7 + i);
        cout << (pClasificaciones[i].getEliminado() ? "SI" : "NO");
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pClasificaciones;
}

void ListadosManager::listarTiposContenido()
{
    int cantRegistros = _repoTipoContenido.getCantidadRegistros();
    TipoContenido* pTiposContenido = new TipoContenido [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay tipos de contenido para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pTiposContenido;
        return;
    }
    if(pTiposContenido == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pTiposContenido;
        return;
    }

    _repoTipoContenido.leer(pTiposContenido, cantRegistros);

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "======= LISTADO DE TIPOS DE CONTENIDO ========" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "DESCRIPCION";
    rlutil::locate(40, 5);
    cout << "ELIMINADO";
    rlutil::locate(5, 6);
    cout << "----------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pTiposContenido[i].getIdTipoContenido();
        rlutil::locate(15, 7 + i);
        cout << pTiposContenido[i].getDescripcion();
        rlutil::locate(43, 7 + i);
        cout << (pTiposContenido[i].getEliminado() ? "SI" : "NO");
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pTiposContenido;
}

void ListadosManager::listarTiposSuscripcion()
{
    int cantRegistros = _repoTipoSuscripcion.getCantidadRegistros();
    TipoSuscripcion* pTiposSuscripcion = new TipoSuscripcion [cantRegistros];

    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay tipos de contenido para listar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pTiposSuscripcion;
        return;
    }
    if(pTiposSuscripcion == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        delete [] pTiposSuscripcion;
        return;
    }

    _repoTipoSuscripcion.leer(pTiposSuscripcion, cantRegistros);

    rlutil::setColor(rlutil::YELLOW);
    rlutil::locate(5, 2);
    cout << "====== LISTADO DE TIPOS DE SUSCRIPCION ======" << endl;
    rlutil::setColor(rlutil::CYAN);
    rlutil::locate(5, 5);
    cout << "ID";
    rlutil::locate(15, 5);
    cout << "DESCRIPCION";
    rlutil::locate(40, 5);
    cout << "ELIMINADO";
    rlutil::locate(5, 6);
    cout << "----------------------------------------------";
    rlutil::setColor(rlutil::GREEN);
    rlutil::locate(5, 7);

    for(int i = 0; i < cantRegistros; i++)
    {
        rlutil::locate(5, 7 + i);
        cout << pTiposSuscripcion[i].getIdTipoSuscripcion();
        rlutil::locate(15, 7 + i);
        cout << pTiposSuscripcion[i].getDescripcion();
        rlutil::locate(43, 7 + i);
        cout << (pTiposSuscripcion[i].getEliminado() ? "SI" : "NO");
    }

    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;

    delete [] pTiposSuscripcion;
}
