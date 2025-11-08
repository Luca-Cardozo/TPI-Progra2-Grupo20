#include <iostream>
#include "ConsultasMenu.h"
#include "rlutil.h"
#include "utils.h"

using namespace std;

ConsultasMenu::ConsultasMenu()
{
    _cantidadOpciones = 15;
}

void ConsultasMenu::mostrar()
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


void ConsultasMenu::mostrarOpciones()
{
    rlutil::setColor(rlutil::BROWN);
    cout << "------------------- MENU CONSULTAS -------------------" << endl;
    cout << "1 - CONSULTAR SUSCRIPTOR POR EMAIL" << endl;
    cout << "2 - CONSULTAR SUSCRIPTOR POR TELEFONO" << endl;
    cout << "3 - CONSULTAR SUSCRIPTORES POR TIPO DE SUSCRIPCION" << endl;
    cout << "4 - CONSULTAR PELICULA POR TITULO" << endl;
    cout << "5 - CONSULTAR PELICULAS POR DIRECTOR" << endl;
    cout << "6 - CONSULTAR PELICULAS POR GENERO" << endl;
    cout << "7 - CONSULTAR PELICULAS POR CLASIFICACION" << endl;
    cout << "8 - CONSULTAR SERIE POR TITULO" << endl;
    cout << "9 - CONSULTAR SERIES POR DIRECTOR" << endl;
    cout << "10 - CONSULTAR SERIES POR GENERO" << endl;
    cout << "11 - CONSULTAR SERIES POR CLASIFICACION" << endl;
    cout << "12 - CONSULTAR DIRECTOR POR NOMBRE Y APELLIDO" << endl;
    cout << "13 - CONSULTAR CONSUMOS POR SUSCRIPTOR" << endl;
    cout << "14 - CONSULTAR CONSUMOS POR PELICULA" << endl;
    cout << "15 - CONSULTAR CONSUMOS POR SERIE" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "------------------------------------------------------" << endl;
    rlutil::setColor(rlutil::WHITE);
}

void ConsultasMenu::ejecutarOpcion(int opcion)
{
    string email, tel, tit, nom, ape;
    int id;
    switch(opcion)
    {
    case 1:
        email = pedirCadena("email");
        _consultasManager.consultarSuscriptorEmail(email.c_str());
        break;
    case 2:
        tel = pedirCadena("telefono");
        _consultasManager.consultarSuscriptorTelefono(tel.c_str());
        break;
    case 3:
        system("cls");
        _listadosManager.listarTiposSuscripcion();
        id = pedirIdValido(_repoTipoSuscripcion.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarSuscriptorTipoSuscripcion(id);
        break;
    case 4:
        tit = pedirCadena("titulo");
        _consultasManager.consultarPeliculaTitulo(tit.c_str());
        break;
    case 5:
        system("cls");
        _listadosManager.listarDirectoresApellido();
        id = pedirIdValido(_repoDirector.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarPeliculaDirector(id);
        break;
    case 6:
        system("cls");
        _listadosManager.listarGeneros();
        id = pedirIdValido(_repoGenero.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarPeliculaGenero(id);
        break;
    case 7:
        system("cls");
        _listadosManager.listarClasificaciones();
        id = pedirIdValido(_repoClasificacion.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarPeliculaClasificacion(id);
        break;
    case 8:
        tit = pedirCadena("titulo");
        _consultasManager.consultarSerieTitulo(tit.c_str());
        break;
    case 9:
        system("cls");
        _listadosManager.listarDirectoresApellido();
        id = pedirIdValido(_repoDirector.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarSerieDirector(id);
        break;
    case 10 :
        system("cls");
        _listadosManager.listarGeneros();
        id = pedirIdValido(_repoGenero.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarSerieGenero(id);
        break;
    case 11:
        system("cls");
        _listadosManager.listarClasificaciones();
        id = pedirIdValido(_repoClasificacion.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarSerieClasificacion(id);
        break;
    case 12:
        nom = pedirCadena();
        ape = pedirCadena("apellido");
        _consultasManager.consultarDirectorNombreApellido(nom.c_str(), ape.c_str());
        break;
    case 13:
        system("cls");
        _listadosManager.listarSuscriptoresApellido();
        id = pedirIdValido(_repoSuscriptor.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarConsumosPorSuscriptor(id);
        break;
    case 14:
        system("cls");
        _listadosManager.listarPeliculasTitulo();
        id = pedirIdValido(_repoPelicula.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarConsumosPorPelicula(id);
        break;
    case 15:
        system("cls");
        _listadosManager.listarSeriesTitulo();
        id = pedirIdValido(_repoSerie.getCantidadRegistros());
        if(id != 0) _consultasManager.consultarConsumosPorSerie(id);
        break;
    }
}


int ConsultasMenu::seleccionOpcion()
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
