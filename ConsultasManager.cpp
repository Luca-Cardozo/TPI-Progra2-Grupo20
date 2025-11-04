#include <iostream>
#include "ConsultasManager.h"
#include "rlutil.h"

using namespace std;


void ConsultasManager::consultarSuscriptorEmail(const char* email)
{
    int cantRegistros = _repoSuscriptor.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay suscriptores para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Suscriptor* pSuscriptores;
    pSuscriptores = new Suscriptor [cantRegistros];
    if(pSuscriptores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    _repoSuscriptor.leer(pSuscriptores, cantRegistros);
    bool sinCoincidencias = true;
    system("cls");
    cout << endl;
    cout << endl;
    for(int i = 0; i < cantRegistros; i++)
    {
        if (strcasecmp(pSuscriptores[i].getEmail(), email) == 0)
        {
            rlutil::setColor(rlutil::BROWN);
            cout << "=========================================" << endl;
            cout << "+++++++ RESULTADO DE LA CONSULTA ++++++++" << endl;
            cout << "=========================================" << endl;
            cout << endl;
            rlutil::setColor(rlutil::CYAN);
            cout << "--------- DATOS DEL SUSCRIPTOR ---------" << endl;
            rlutil::setColor(rlutil::YELLOW);
            cout << endl;
            cout << "ID: " << pSuscriptores[i].getId() << endl;
            cout << "------------------------------------------" << endl;
            cout << "NOMBRE: " << pSuscriptores[i].getNombre() << endl;
            cout << "------------------------------------------" << endl;
            cout << "APELLIDO: " << pSuscriptores[i].getApellido() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "NACIONALIDAD: " << pSuscriptores[i].getNacionalidad() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "FECHA DE NACIMIENTO: ";
            pSuscriptores[i].getFechaNacimiento().mostrar();
            cout << "-----------------------------------------" << endl;
            cout << "EMAIL: " << pSuscriptores[i].getEmail() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "TELEFONO: " << pSuscriptores[i].getTelefono() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "FECHA DE ALTA: ";
            pSuscriptores[i].getFechaAlta().mostrar();
            cout << "-----------------------------------------" << endl;
            cout << "TIPO SUSCRIPCION: ";
            if (pSuscriptores[i].getTipoSuscripcion() == 1) cout << "BASICO" << endl;
            else if (pSuscriptores[i].getTipoSuscripcion() == 2) cout << "ESTANDAR" << endl;
            else if (pSuscriptores[i].getTipoSuscripcion() == 3) cout << "PREMIUM" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "ELIMINADO: " << (pSuscriptores[i].getEliminado() ? "SI" : "NO") << endl;
            cout << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
            sinCoincidencias = false;
            rlutil::setColor(rlutil::WHITE);
        }
    }
    if(sinCoincidencias)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "No se encontro ningun registro con ese email..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    delete [] pSuscriptores;
}

void ConsultasManager::consultarSuscriptorTelefono(const char* tel)
{
    int cantRegistros = _repoSuscriptor.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay suscriptores para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Suscriptor* pSuscriptores;
    pSuscriptores = new Suscriptor [cantRegistros];
    if(pSuscriptores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    _repoSuscriptor.leer(pSuscriptores, cantRegistros);
    bool sinCoincidencias = true;
    system("cls");
    cout << endl;
    cout << endl;
    for(int i = 0; i < cantRegistros; i++)
    {
        if (strcmp(pSuscriptores[i].getTelefono(), tel) == 0)
        {
            rlutil::setColor(rlutil::BROWN);
            cout << "=========================================" << endl;
            cout << "+++++++ RESULTADO DE LA CONSULTA ++++++++" << endl;
            cout << "=========================================" << endl;
            cout << endl;
            rlutil::setColor(rlutil::CYAN);
            cout << "--------- DATOS DEL SUSCRIPTOR ---------" << endl;
            rlutil::setColor(rlutil::YELLOW);
            cout << endl;
            cout << "ID: " << pSuscriptores[i].getId() << endl;
            cout << "------------------------------------------" << endl;
            cout << "NOMBRE: " << pSuscriptores[i].getNombre() << endl;
            cout << "------------------------------------------" << endl;
            cout << "APELLIDO: " << pSuscriptores[i].getApellido() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "NACIONALIDAD: " << pSuscriptores[i].getNacionalidad() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "FECHA DE NACIMIENTO: ";
            pSuscriptores[i].getFechaNacimiento().mostrar();
            cout << "-----------------------------------------" << endl;
            cout << "EMAIL: " << pSuscriptores[i].getEmail() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "TELEFONO: " << pSuscriptores[i].getTelefono() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "FECHA DE ALTA: ";
            pSuscriptores[i].getFechaAlta().mostrar();
            cout << "-----------------------------------------" << endl;
            cout << "TIPO SUSCRIPCION: ";
            if (pSuscriptores[i].getTipoSuscripcion() == 1) cout << "BASICO" << endl;
            else if (pSuscriptores[i].getTipoSuscripcion() == 2) cout << "ESTANDAR" << endl;
            else if (pSuscriptores[i].getTipoSuscripcion() == 3) cout << "PREMIUM" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "ELIMINADO: " << (pSuscriptores[i].getEliminado() ? "SI" : "NO") << endl;
            cout << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
            sinCoincidencias = false;
            rlutil::setColor(rlutil::WHITE);
        }
    }
    if(sinCoincidencias)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "No se encontro ningun registro con ese telefono..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    delete [] pSuscriptores;
}

void ConsultasManager::consultarSuscriptorTipoSuscripcion(int id)
{
    int cantRegistros = _repoSuscriptor.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay suscriptores para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Suscriptor* pSuscriptores;
    pSuscriptores = new Suscriptor [cantRegistros];
    if(pSuscriptores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    system("cls");
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
    cout << "========================= SUSCRIPTORES POR TIPO DE SUSCRIPCION =========================" << endl;
    rlutil::locate(5, 3);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "+++++ TIPO DE SUSCRIPCION: " << _repoTipoSuscripcion.leer(id - 1).getDescripcion() << " +++++" << endl;
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
    int fila = 0;
    for(int i = 0; i < cantRegistros; i++)
    {
        if(pSuscriptores[i].getTipoSuscripcion() == id)
        {
            rlutil::locate(5, 7 + fila);
            cout << pSuscriptores[i].getId();
            rlutil::locate(10, 7 + fila);
            cout << pSuscriptores[i].getNombre();
            rlutil::locate(20, 7 + fila);
            cout << pSuscriptores[i].getApellido();
            rlutil::locate(30, 7 + fila);
            cout << pSuscriptores[i].getEmail();
            rlutil::locate(50, 7 + fila);
            cout << pSuscriptores[i].getTelefono();
            rlutil::locate(65, 7 + fila);
            pSuscriptores[i].getFechaAlta().mostrar();
            rlutil::locate(80, 7 + fila);
            if (pSuscriptores[i].getTipoSuscripcion() == 1) cout << "BASICO";
            else if (pSuscriptores[i].getTipoSuscripcion() == 2) cout << "ESTANDAR";
            else if (pSuscriptores[i].getTipoSuscripcion() == 3) cout << "PREMIUM";
            rlutil::locate(95, 7 + fila);
            cout << (pSuscriptores[i].getEliminado() ? "SI" : "NO");
            rlutil::locate(100, 7 + fila);
            fila++;
        }
    }
    if(fila == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No se encontraron suscriptores para el tipo de suscripcion especificado." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;
    delete [] pSuscriptores;
}

void ConsultasManager::consultarPeliculaTitulo(const char* titulo)
{
    int cantRegistros = _repoPelicula.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay peliculas para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Pelicula* pPeliculas;
    pPeliculas = new Pelicula [cantRegistros];
    if(pPeliculas == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    _repoPelicula.leer(pPeliculas, cantRegistros);
    bool sinCoincidencias = true;
    system("cls");
    cout << endl;
    cout << endl;
    for(int i = 0; i < cantRegistros; i++)
    {
        if (strcasecmp(pPeliculas[i].getTitulo(), titulo) == 0)
        {
            rlutil::setColor(rlutil::BROWN);
            cout << "=========================================" << endl;
            cout << "+++++++ RESULTADO DE LA CONSULTA ++++++++" << endl;
            cout << "=========================================" << endl;
            cout << endl;
            rlutil::setColor(rlutil::CYAN);
            cout << "--------- DATOS DE LA PELICULA ---------" << endl;
            rlutil::setColor(rlutil::YELLOW);
            cout << endl;
            cout << "ID: " << pPeliculas[i].getId() << endl;
            cout << "------------------------------------------" << endl;
            cout << "TITULO: " << pPeliculas[i].getTitulo() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "DIRECTOR: " << _repoDirector.leer(pPeliculas[i].getIdDirector() - 1).getNombre() << " " << _repoDirector.leer(pPeliculas[i].getIdDirector() - 1).getApellido() << " (ID " << pPeliculas[i].getIdDirector() << ")" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "GENERO: " << _repoGenero.leer(pPeliculas[i].getGenero() - 1).getDescripcion() << " (ID " << pPeliculas[i].getGenero() << ")" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "CLASIFICACION: " << _repoClasificacion.leer(pPeliculas[i].getClasificacion() - 1).getDescripcion() << " (ID " << pPeliculas[i].getClasificacion() << ")" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "FECHA DE ESTRENO: ";
            pPeliculas[i].getFechaEstreno().mostrar();
            cout << "-----------------------------------------" << endl;
            cout << "FECHA DE ALTA: ";
            pPeliculas[i].getFechaAlta().mostrar();
            cout << "-----------------------------------------" << endl;
            cout << "DURACION: " << pPeliculas[i].getDuracion() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "ELIMINADO: " << (pPeliculas[i].getEliminado() ? "SI" : "NO") << endl;
            cout << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
            sinCoincidencias = false;
            rlutil::setColor(rlutil::WHITE);

        }
    }
    if(sinCoincidencias)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "No se encontro ningun registro con ese titulo..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    delete [] pPeliculas;
}

void ConsultasManager::consultarPeliculaDirector(int id)
{
    int cantRegistros = _repoPelicula.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay peliculas para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Pelicula* pPeliculas;
    pPeliculas = new Pelicula [cantRegistros];
    if(pPeliculas == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    system("cls");
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
    cout << "============================== PELICULAS POR DIRECTOR ==============================" << endl;
    rlutil::locate(5, 3);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "+++++ DIRECTOR: " << _repoDirector.leer(id - 1).getNombre() << " " << _repoDirector.leer(id - 1).getApellido() << " +++++" << endl;
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
    int fila = 0;
    for(int i = 0; i < cantRegistros; i++)
    {
        if(pPeliculas[i].getIdDirector() == id)
        {
            rlutil::locate(5, 7 + fila);
            cout << pPeliculas[i].getId();
            rlutil::locate(15, 7 + fila);
            cout << pPeliculas[i].getTitulo();
            rlutil::locate(40, 7 + fila);
            pPeliculas[i].getFechaEstreno().mostrar();
            rlutil::locate(55, 7 + fila);
            cout << pPeliculas[i].getDuracion();
            rlutil::locate(70, 7 + fila);
            cout << (pPeliculas[i].getEliminado() ? "SI" : "NO");
            rlutil::locate(80, 7 + fila);
            fila++;
        }
    }
    if(fila == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No se encontraron películas para el director especificado." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;
    delete [] pPeliculas;
}

void ConsultasManager::consultarPeliculaGenero(int id)
{
    int cantRegistros = _repoPelicula.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay peliculas para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Pelicula* pPeliculas;
    pPeliculas = new Pelicula [cantRegistros];
    if(pPeliculas == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    system("cls");
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
    cout << "============================== PELICULAS POR GENERO ==============================" << endl;
    rlutil::locate(5, 3);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "+++++ GENERO: " << _repoGenero.leer(id - 1).getDescripcion() << " +++++" << endl;
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
    int fila = 0;
    for(int i = 0; i < cantRegistros; i++)
    {
        if(pPeliculas[i].getGenero() == id)
        {
            rlutil::locate(5, 7 + fila);
            cout << pPeliculas[i].getId();
            rlutil::locate(15, 7 + fila);
            cout << pPeliculas[i].getTitulo();
            rlutil::locate(40, 7 + fila);
            pPeliculas[i].getFechaEstreno().mostrar();
            rlutil::locate(55, 7 + fila);
            cout << pPeliculas[i].getDuracion();
            rlutil::locate(70, 7 + fila);
            cout << (pPeliculas[i].getEliminado() ? "SI" : "NO");
            rlutil::locate(80, 7 + fila);
            fila++;
        }
    }
    if(fila == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No se encontraron peliculas para el genero especificado." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;
    delete [] pPeliculas;
}

void ConsultasManager::consultarPeliculaClasificacion(int id)
{
    int cantRegistros = _repoPelicula.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay peliculas para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Pelicula* pPeliculas;
    pPeliculas = new Pelicula [cantRegistros];
    if(pPeliculas == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    system("cls");
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
    cout << "============================== PELICULAS POR CLASIFICACION ==============================" << endl;
    rlutil::locate(5, 3);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "+++++ CLASIFICACION: " << _repoClasificacion.leer(id - 1).getDescripcion() << " +++++" << endl;
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
    int fila = 0;
    for(int i = 0; i < cantRegistros; i++)
    {
        if(pPeliculas[i].getClasificacion() == id)
        {
            rlutil::locate(5, 7 + fila);
            cout << pPeliculas[i].getId();
            rlutil::locate(15, 7 + fila);
            cout << pPeliculas[i].getTitulo();
            rlutil::locate(40, 7 + fila);
            pPeliculas[i].getFechaEstreno().mostrar();
            rlutil::locate(55, 7 + fila);
            cout << pPeliculas[i].getDuracion();
            rlutil::locate(70, 7 + fila);
            cout << (pPeliculas[i].getEliminado() ? "SI" : "NO");
            rlutil::locate(80, 7 + fila);
            fila++;
        }
    }
    if(fila == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No se encontraron peliculas para la clasificacion especificada." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;
    delete [] pPeliculas;
}

void ConsultasManager::consultarSerieTitulo(const char* titulo)
{
    int cantRegistros = _repoSerie.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay series para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Serie* pSeries;
    pSeries = new Serie [cantRegistros];
    if(pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    _repoSerie.leer(pSeries, cantRegistros);
    bool sinCoincidencias = true;
    system("cls");
    cout << endl;
    cout << endl;
    for(int i = 0; i < cantRegistros; i++)
    {
        if (strcasecmp(pSeries[i].getTitulo(), titulo) == 0)
        {
            rlutil::setColor(rlutil::BROWN);
            cout << "=========================================" << endl;
            cout << "+++++++ RESULTADO DE LA CONSULTA ++++++++" << endl;
            cout << "=========================================" << endl;
            cout << endl;
            rlutil::setColor(rlutil::CYAN);
            cout << "--------- DATOS DE LA SERIE ---------" << endl;
            rlutil::setColor(rlutil::YELLOW);
            cout << endl;
            cout << "ID: " << pSeries[i].getId() << endl;
            cout << "------------------------------------------" << endl;
            cout << "TITULO: " << pSeries[i].getTitulo() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "DIRECTOR: " << _repoDirector.leer(pSeries[i].getIdDirector() - 1).getNombre() << " " << _repoDirector.leer(pSeries[i].getIdDirector() - 1).getApellido() << " (ID " << pSeries[i].getIdDirector() << ")" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "GENERO: " << _repoGenero.leer(pSeries[i].getGenero() - 1).getDescripcion() << " (ID " << pSeries[i].getGenero() << ")" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "CLASIFICACION: " << _repoClasificacion.leer(pSeries[i].getClasificacion() - 1).getDescripcion() << " (ID " << pSeries[i].getClasificacion() << ")" << endl;
            cout << "-----------------------------------------" << endl;
            cout << "FECHA DE ESTRENO: ";
            pSeries[i].getFechaEstreno().mostrar();
            cout << "-----------------------------------------" << endl;
            cout << "FECHA DE ALTA: ";
            pSeries[i].getFechaAlta().mostrar();
            cout << "-----------------------------------------" << endl;
            cout << "TEMPORADAS: " << pSeries[i].getTemporadas() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "CAPITULOS: " << pSeries[i].getCapitulos() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "ELIMINADO: " << (pSeries[i].getEliminado() ? "SI" : "NO") << endl;
            cout << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
            sinCoincidencias = false;
            rlutil::setColor(rlutil::WHITE);
        }
    }
    if(sinCoincidencias)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "No se encontro ningun registro con ese titulo..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    delete [] pSeries;
}

void ConsultasManager::consultarSerieDirector(int id)
{
    int cantRegistros = _repoSerie.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay series para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Serie* pSeries;
    pSeries = new Serie [cantRegistros];
    if(pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    system("cls");
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
    cout << "============================== SERIES POR DIRECTOR ==============================" << endl;
    rlutil::locate(5, 3);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "+++++ DIRECTOR: " << _repoDirector.leer(id - 1).getNombre() << " " << _repoDirector.leer(id - 1).getApellido() << " +++++" << endl;
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
    int fila = 0;
    for(int i = 0; i < cantRegistros; i++)
    {
        if(pSeries[i].getIdDirector() == id)
        {
            rlutil::locate(5, 7 + fila);
            cout << pSeries[i].getId();
            rlutil::locate(15, 7 + fila);
            cout << pSeries[i].getTitulo();
            rlutil::locate(40, 7 + fila);
            pSeries[i].getFechaEstreno().mostrar();
            rlutil::locate(55, 7 + fila);
            cout << pSeries[i].getTemporadas();
            rlutil::locate(70, 7 + fila);
            cout << pSeries[i].getCapitulos();
            rlutil::locate(80, 7 + fila);
            cout << (pSeries[i].getEliminado() ? "SI" : "NO");
            rlutil::locate(85, 7 + fila);
            fila++;
        }
    }
    if(fila == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No se encontraron series para el director especificado." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;
    delete [] pSeries;
}

void ConsultasManager::consultarSerieGenero(int id)
{
    int cantRegistros = _repoSerie.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay series para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Serie* pSeries;
    pSeries = new Serie [cantRegistros];
    if(pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    system("cls");
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
    cout << "============================== SERIES POR GENERO ==============================" << endl;
    rlutil::locate(5, 3);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "+++++ GENERO: " << _repoGenero.leer(id - 1).getDescripcion() << " +++++" << endl;
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
    int fila = 0;
    for(int i = 0; i < cantRegistros; i++)
    {
        if(pSeries[i].getGenero() == id)
        {
            rlutil::locate(5, 7 + fila);
            cout << pSeries[i].getId();
            rlutil::locate(15, 7 + fila);
            cout << pSeries[i].getTitulo();
            rlutil::locate(40, 7 + fila);
            pSeries[i].getFechaEstreno().mostrar();
            rlutil::locate(55, 7 + fila);
            cout << pSeries[i].getTemporadas();
            rlutil::locate(70, 7 + fila);
            cout << pSeries[i].getCapitulos();
            rlutil::locate(80, 7 + fila);
            cout << (pSeries[i].getEliminado() ? "SI" : "NO");
            rlutil::locate(85, 7 + fila);
            fila++;
        }
    }
    if(fila == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No se encontraron series para el genero especificado." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;
    delete [] pSeries;
}

void ConsultasManager::consultarSerieClasificacion(int id)
{
    int cantRegistros = _repoSerie.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay series para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Serie* pSeries;
    pSeries = new Serie [cantRegistros];
    if(pSeries == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    system("cls");
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
    cout << "============================== SERIES POR CLASIFICACION ==============================" << endl;
    rlutil::locate(5, 3);
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << "+++++ CLASIFICACION: " << _repoClasificacion.leer(id - 1).getDescripcion() << " +++++" << endl;
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
    int fila = 0;
    for(int i = 0; i < cantRegistros; i++)
    {
        if(pSeries[i].getClasificacion() == id)
        {
            rlutil::locate(5, 7 + fila);
            cout << pSeries[i].getId();
            rlutil::locate(15, 7 + fila);
            cout << pSeries[i].getTitulo();
            rlutil::locate(40, 7 + fila);
            pSeries[i].getFechaEstreno().mostrar();
            rlutil::locate(55, 7 + fila);
            cout << pSeries[i].getTemporadas();
            rlutil::locate(70, 7 + fila);
            cout << pSeries[i].getCapitulos();
            rlutil::locate(80, 7 + fila);
            cout << (pSeries[i].getEliminado() ? "SI" : "NO");
            rlutil::locate(85, 7 + fila);
            fila++;
        }
    }
    if(fila == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No se encontraron series para la clasificacion especificada." << endl;
    }
    rlutil::setColor(rlutil::WHITE);
    cout << endl;
    cout << endl;
    delete [] pSeries;
}

void ConsultasManager::consultarDirectorNombreApellido(const char* nom, const char* ape)
{
    int cantRegistros = _repoDirector.getCantidadRegistros();
    if(cantRegistros == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "No hay directores para mostrar..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    Director* pDirectores;
    pDirectores = new Director [cantRegistros];
    if(pDirectores == nullptr)
    {
        rlutil::setColor(rlutil::RED);
        cout << "Error al asignar memoria dinamica..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return;
    }
    _repoDirector.leer(pDirectores, cantRegistros);
    bool sinCoincidencias = true;
    system("cls");
    cout << endl;
    cout << endl;
    for(int i = 0; i < cantRegistros; i++)
    {
        if (strcasecmp(pDirectores[i].getNombre(), nom) == 0 && strcasecmp(pDirectores[i].getApellido(), ape) == 0)
        {
            rlutil::setColor(rlutil::BROWN);
            cout << "=========================================" << endl;
            cout << "+++++++ RESULTADO DE LA CONSULTA ++++++++" << endl;
            cout << "=========================================" << endl;
            cout << endl;
            rlutil::setColor(rlutil::CYAN);
            cout << "--------- DATOS DEL DIRECTOR ---------" << endl;
            rlutil::setColor(rlutil::YELLOW);
            cout << endl;
            cout << "ID: " << pDirectores[i].getId() << endl;
            cout << "------------------------------------------" << endl;
            cout << "NOMBRE: " << pDirectores[i].getNombre() << endl;
            cout << "------------------------------------------" << endl;
            cout << "APELLIDO: " << pDirectores[i].getApellido() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "NACIONALIDAD: " << pDirectores[i].getNacionalidad() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "FECHA DE NACIMIENTO: ";
            pDirectores[i].getFechaNacimiento().mostrar();
            cout << "-----------------------------------------" << endl;
            cout << "PAIS DE RESIDENCIA: " << pDirectores[i].getPaisResidencia() << endl;
            cout << "-----------------------------------------" << endl;
            cout << "ELIMINADO: " << (pDirectores[i].getEliminado() ? "SI" : "NO") << endl;
            cout << endl;
            cout << "-----------------------------------------" << endl;
            cout << endl;
            sinCoincidencias = false;
            rlutil::setColor(rlutil::WHITE);
        }
    }
    if(sinCoincidencias)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "No se encontro ningun registro con ese email..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    delete [] pDirectores;
}
