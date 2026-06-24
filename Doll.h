#ifndef DOLL_H
#define DOLL_H

#include "Enemigo.h"

class Doll : public Enemigo
{
public:
    Doll();
    Doll(Posicion posicion, int nivel);
    void mover(int anchoMapa, int altoMapa, int* celdas, Posicion posJugador) override;
};

#endif
