#ifndef ONEAL_H
#define ONEAL_H

#include "Enemigo.h"

class Oneal : public Enemigo
{
public:
    Oneal();
    Oneal(Posicion posicion, int nivel);
    void mover(int anchoMapa, int altoMapa, int* celdas, Posicion posJugador) override;
};

#endif
