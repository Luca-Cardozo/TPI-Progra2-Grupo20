#include <iostream>
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
    while(num < 0)
    {
        cout << "El valor solo puede ser positivo... Intentelo nuevamente..." << endl;
        cout << "Ingrese un valor positivo: " << endl;
        cin >> num;
    }
    return num;
}
