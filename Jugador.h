#ifndef JUGADOR_H
#define JUGADOR_H

#include "Posicion.h"

class Jugador
{
private:
    char nombre[30];
    int vidas;
    int puntaje;
    int cantBombas;
    int tipoBombas;
    Posicion posicion;

public:
    Jugador();
    const char* getNombre();
    void setNombre(const char* nombre);
    int getVidas();
    void setVidas(int vidas);
    int getPuntaje();
    void setPuntaje(int puntaje);
    int getCantBombas();
    void setCantBombas(int cantBombas);
    int getTipoBombas();
    void setTipoBombas(int tipoBombas);
    Posicion getPosicion();
    void setPosicion(Posicion posicion);
    void sumarPuntos(int puntos);
    void perderVida();
    bool estaVivo();
};

#endif
