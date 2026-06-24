#ifndef BOMBA_H
#define BOMBA_H

#include "Posicion.h"

class Bomba
{
private:
    int jugadorId;
    bool activa;
    float tiempoRestante;
    int radio;
    Posicion posicion;

public:
    Bomba();
    Bomba(int jugadorId, Posicion posicion, int radio);
    int getJugadorId();
    void setJugadorId(int jugadorId);
    bool getActiva();
    void setActiva(bool activa);
    float getTiempoRestante();
    void setTiempoRestante(float tiempoRestante);
    int getRadio();
    void setRadio(int radio);
    Posicion getPosicion();
    void setPosicion(Posicion posicion);
    void actualizar(float deltaTiempo);
    bool exploto();
};

#endif
