#include "Bomba.h"

Bomba::Bomba()
{
    jugadorId = 0;
    activa = false;
    tiempoRestante = 3.0f;
    radio = 1;
    posicion = Posicion(0, 0);
}

Bomba::Bomba(int jugadorId, Posicion posicion, int radio)
{
    this->jugadorId = jugadorId;
    this->activa = true;
    this->tiempoRestante = 3.0f;
    this->radio = radio;
    this->posicion = posicion;
}

int Bomba::getJugadorId()
{
    return jugadorId;
}

void Bomba::setJugadorId(int jugadorId)
{
    this->jugadorId = jugadorId;
}

bool Bomba::getActiva()
{
    return activa;
}

void Bomba::setActiva(bool activa)
{
    this->activa = activa;
}

float Bomba::getTiempoRestante()
{
    return tiempoRestante;
}

void Bomba::setTiempoRestante(float tiempoRestante)
{
    this->tiempoRestante = tiempoRestante;
}

int Bomba::getRadio()
{
    return radio;
}

void Bomba::setRadio(int radio)
{
    this->radio = radio;
}

Posicion Bomba::getPosicion()
{
    return posicion;
}

void Bomba::setPosicion(Posicion posicion)
{
    this->posicion = posicion;
}

void Bomba::actualizar(float deltaTiempo)
{
    if (activa)
    {
        tiempoRestante -= deltaTiempo;
        if (tiempoRestante <= 0)
            activa = false;
    }
}

bool Bomba::exploto()
{
    return !activa && tiempoRestante <= 0;
}
