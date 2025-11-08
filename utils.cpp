#include <iostream>
#include "rlutil.h"
#include "utils.h"

using namespace std;

std::string cargarCadena()
{
    std::string texto;

    if(std::cin.peek() == '\n')
    {
        std::cin.ignore();
    }

    std::getline(std::cin, texto);

    return texto;
}


bool fechaDecreciente(Fecha f1, Fecha f2)
{
    return f1 > f2;
}

bool fechaCreciente(Fecha f1, Fecha f2)
{
    return f1 < f2;
}

bool fechaHoraCreciente(Fecha f1, Fecha f2, Hora h1, Hora h2)
{
    if (f1 < f2) return true;
    if (f1 > f2) return false;
    return h1 < h2;
}

bool fechaHoraDecreciente(Fecha f1, Fecha f2, Hora h1, Hora h2)
{
    if (f1 > f2) return true;
    if (f1 < f2) return false;
    return h1 > h2;
}

bool intDecreciente(int n1, int n2)
{
    return n1 > n2;
}

bool intCreciente(int n1, int n2)
{
    return n1 < n2;
}

int validarPositivo(int num)
{
    while(num <= 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << "El valor solo puede ser positivo... Intentelo nuevamente..." << endl;
        rlutil::setColor(rlutil::LIGHTBLUE);
        cout << "Ingrese un valor positivo: " << endl;
        rlutil::setColor(rlutil::WHITE);
        cin >> num;
    }
    return num;
}

void validarCarga(bool resultado)
{
    if(resultado)
    {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << endl;
        cout << "CARGA EXITOSA!" << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "NO SE PUDO REALIZAR LA CARGA..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
}

void validarModificacion(bool resultado)
{
    if(resultado)
    {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << endl;
        cout << "MODIFICACION EXITOSA!" << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "NO SE PUDO REALIZAR LA MODIFICACION..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
}

void validarBaja(bool resultado)
{
    if(resultado)
    {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << endl;
        cout << "BAJA EXITOSA!" << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "NO SE PUDO REALIZAR LA BAJA..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
}

void validarAlta(bool resultado)
{
    if(resultado)
    {
        rlutil::setColor(rlutil::LIGHTGREEN);
        cout << endl;
        cout << "ALTA EXITOSA!" << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
    else
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "NO SE PUDO REALIZAR EL ALTA..." << endl;
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
    }
}

int preguntarOrdenCrecienteDecreciente()
{
    int respuesta;
    rlutil::setColor(rlutil::YELLOW);
    cout << endl;
    cout << "1- Orden creciente" << endl;
    cout << "2- Orden decreciente" << endl;
    cout << endl;
    rlutil::setColor(rlutil::LIGHTCYAN);
    cout << "Ingrese respuesta: " << endl;
    rlutil::setColor(rlutil::WHITE);
    cin >> respuesta;
    while(respuesta != 1 && respuesta != 2)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Respuesta incorrecta... Vuelva a intentarlo..." << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << endl;
        cout << "1- Orden creciente" << endl;
        cout << "2- Orden decreciente" << endl;
        cout << endl;
        rlutil::setColor(rlutil::LIGHTCYAN);
        cout << "Ingrese respuesta: " << endl;
        rlutil::setColor(rlutil::WHITE);
        cin >> respuesta;
    }
    rlutil::setColor(rlutil::WHITE);
    return respuesta;
}

string pedirCadena(string texto)
{
    string cadena;
    cout << endl;
    rlutil::setColor(rlutil::YELLOW);
    cout << "Ingrese " << texto << ": " << endl;
    cout << endl;
    rlutil::setColor(rlutil::WHITE);
    cadena = cargarCadena();
    cout << endl;
    return cadena;
}

int pedirIdValido(int cantRegistros)
{
    int id;
    do
    {
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Ingrese un ID de la lista o 0 para salir: ";
        cout << endl;
        rlutil::setColor(rlutil::WHITE);
        cin >> id;
        if(id > cantRegistros || id < 0)
        {
            cout << endl;
            rlutil::setColor(rlutil::RED);
            cout << "No existe el ID ingresado..." << endl;
            rlutil::setColor(rlutil::WHITE);
        }
        else if(id == 0)
        {
            return 0;
        }
        else
        {
            return id;
        }
    }
    while(true);
}

void pedir2FechasValidas(Fecha &f1, Fecha &f2)
{
    do
    {
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Ingrese dos fechas: (la segunda debe ser posterior a la primera)" << endl;
        cout << "Ingrese la primera fecha: " << endl;
        rlutil::setColor(rlutil::WHITE);
        f1.cargar();
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Ingrese la segunda fecha: " << endl;
        rlutil::setColor(rlutil::WHITE);
        f2.cargar();
    }
    while(f1 >= f2);
}

void pedir2HorariosValidos(Hora &h1, Hora &h2)
{
    do
    {
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Ingrese dos horarios: (el segundo debe ser posterior al primero)" << endl;
        cout << "Ingrese el primer horario: " << endl;
        rlutil::setColor(rlutil::WHITE);
        h1.cargar();
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Ingrese el segundo horario: " << endl;
        rlutil::setColor(rlutil::WHITE);
        h2.cargar();
    }
    while(h1 >= h2);
}

int pedirAnioValido()
{
    int anio;
    do
    {
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Ingrese un anio valido: " << endl;
        rlutil::setColor(rlutil::WHITE);
        cin >> anio;
    }
    while(anio <= 0);
    return anio;
}

int pedirMesValido()
{
    int mes;
    do
    {
        cout << endl;
        rlutil::setColor(rlutil::YELLOW);
        cout << "Ingrese un mes valido: " << endl;
        rlutil::setColor(rlutil::WHITE);
        cin >> mes;
    }
    while(mes <= 0 || mes > 12);
    return mes;
}

bool confirmarAccion(string mensaje)
{
    char respuesta;
    rlutil::setColor(rlutil::CYAN);
    cout << mensaje << " (S/N): ";
    rlutil::setColor(rlutil::WHITE);
    cin >> respuesta;

    while(respuesta != 's' && respuesta != 'S' && respuesta != 'n' && respuesta != 'N')
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Respuesta incorrecta, vuelva a intentarlo..." << endl;
        rlutil::setColor(rlutil::CYAN);
        cout << endl;
        cout << mensaje << " (S/N): ";
        rlutil::setColor(rlutil::WHITE);
        cin >> respuesta;
    }
    return (respuesta == 's' || respuesta == 'S');
}

bool deseaCancelar(string mensaje)
{
    int opcion;
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << mensaje << endl;
    rlutil::setColor(rlutil::WHITE);
    cin >> opcion;
    if(opcion == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl;
        cout << "Operacion cancelada..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return true;
    }
    return false;
}

bool pedirIdConCancelacion(string mensaje, int &id)
{
    rlutil::setColor(rlutil::LIGHTMAGENTA);
    cout << mensaje << endl;
    rlutil::setColor(rlutil::WHITE);
    cin >> id;
    if (id == 0)
    {
        rlutil::setColor(rlutil::RED);
        cout << endl << "Operacion anulada..." << endl;
        rlutil::setColor(rlutil::WHITE);
        return true;
    }
    return false;
}
