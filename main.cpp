#include <iostream>
#include "App.h"
//#include "Genero.h"
//#include "TipoContenido.h"
//#include "TipoSuscripcion.h"
//include "Clasificacion.h"

using namespace std;

int main()
{
    /*
    FILE* pArchivo = fopen("generos.dat", "rb");
    Genero reg;
    for(int i = 0; i < 18; i++)
    {
        fread(&reg, sizeof(Genero), 1, pArchivo);
        reg.mostrar();
    }
    FILE* pArchivo2 = fopen("tipos_contenido.dat", "rb");
    TipoContenido reg2;
    for(int i = 0; i < 2; i++)
    {
        fread(&reg2, sizeof(TipoContenido), 1, pArchivo2);
        reg2.mostrar();
    }
    FILE* pArchivo3 = fopen("tipos_suscripcion.dat", "rb");
    TipoSuscripcion reg3;
    for(int i = 0; i < 3; i++)
    {
        fread(&reg3, sizeof(TipoSuscripcion), 1, pArchivo3);
        reg3.mostrar();
    }
    FILE* pArchivo4 = fopen("clasificaciones.dat", "rb");
    Clasificacion reg4;
    for(int i = 0; i < 5; i++)
    {
        fread(&reg4, sizeof(Clasificacion), 1, pArchivo4);
        reg4.mostrar();
    }
    */
    App app;
    app.run();
    return 0;
}
