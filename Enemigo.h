#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Posicion.h"

class Enemigo
{
private:
    int vidas;
    int nivel;
    int puntos;
    Posicion posicion;

public:
    Enemigo();
    Enemigo(int vidas, int nivel, int puntos, Posicion posicion);
    int getVidas();
    void setVidas(int vidas);
    int getNivel();
    void setNivel(int nivel);
    int getPuntos();
    void setPuntos(int puntos);
    Posicion getPosicion();
    void setPosicion(Posicion posicion);
    bool estaVivo();
    void recibirDanio();
    virtual void mover(int anchoMapa, int altoMapa, int* celdas, Posicion posJugador);
};

#endif
