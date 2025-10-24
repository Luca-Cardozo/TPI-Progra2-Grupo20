#pragma once
#include "DirectorArchivo.h"

class DirectorManager
{
private:
    DirectorArchivo _repoDirector;
public:
    bool cargarDirector();
    bool modificarDirector();
    bool eliminarDirector();
};

