#ifndef BOMBAARCHIVO_H
#define BOMBAARCHIVO_H

#include "Bomba.h"

class BombaArchivo
{
private:
    char nombre[50];

public:
    BombaArchivo();
    BombaArchivo(const char* nombre);
    bool guardar(Bomba bomba);
    Bomba leer(int indice);
    int cantidadRegistros();
    bool actualizar(Bomba bomba, int indice);
};

#endif
