#ifndef JUGADORARCHIVO_H
#define JUGADORARCHIVO_H

#include "Jugador.h"

class JugadorArchivo
{
private:
    char nombre[50];

public:
    JugadorArchivo();
    JugadorArchivo(const char* nombre);
    bool guardar(Jugador jugador);
    Jugador leer(int indice);
    int cantidadRegistros();
    bool actualizar(Jugador jugador, int indice);
};

#endif
