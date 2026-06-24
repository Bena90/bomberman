#ifndef BALLOOM_H
#define BALLOOM_H

#include "Enemigo.h"

class Balloom : public Enemigo
{
private:
    int direccion;

public:
    Balloom();
    Balloom(Posicion posicion, int nivel);
    void mover(int anchoMapa, int altoMapa, int* celdas, Posicion posJugador) override;
};

#endif
