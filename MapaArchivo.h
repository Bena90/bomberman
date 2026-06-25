#ifndef MAPAARCHIVO_H
#define MAPAARCHIVO_H

#include "Mapa.h"

class MapaArchivo
{
private:
    char nombreMapa[50];
    char nombreCeldas[50];

public:
    MapaArchivo();
    bool guardar(Mapa& mapa);
    bool leer(Mapa& mapa);
};

#endif
