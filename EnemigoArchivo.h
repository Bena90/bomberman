#ifndef ENEMIGOARCHIVO_H
#define ENEMIGOARCHIVO_H

#include "Enemigo.h"

class EnemigoArchivo
{
private:
    char nombre[50];

public:
    EnemigoArchivo();
    EnemigoArchivo(const char* nombre);
    bool guardar(Enemigo enemigo);
    Enemigo leer(int indice);
    int cantidadRegistros();
    bool actualizar(Enemigo enemigo, int indice);
};

#endif
