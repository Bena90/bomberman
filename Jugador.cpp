#include "Jugador.h"
#include <cstring>

Jugador::Jugador()
{
    strcpy(nombre, "");
    vidas = 3;
    puntaje = 0;
    cantBombas = 1;
    tipoBombas = 0;
    radioBombas = 1;
    posicion = Posicion(1, 1);
}

const char* Jugador::getNombre()
{
    return nombre;
}

void Jugador::setNombre(const char* nombre)
{
    strncpy(this->nombre, nombre, 29);
    this->nombre[29] = '\0';
}

int Jugador::getVidas()
{
    return vidas;
}

void Jugador::setVidas(int vidas)
{
    this->vidas = vidas;
}

int Jugador::getPuntaje()
{
    return puntaje;
}

void Jugador::setPuntaje(int puntaje)
{
    this->puntaje = puntaje;
}

int Jugador::getCantBombas()
{
    return cantBombas;
}

void Jugador::setCantBombas(int cantBombas)
{
    this->cantBombas = cantBombas;
}

int Jugador::getTipoBombas()
{
    return tipoBombas;
}

void Jugador::setTipoBombas(int tipoBombas)
{
    this->tipoBombas = tipoBombas;
}

int Jugador::getRadioBombas()
{
    return radioBombas;
}

void Jugador::setRadioBombas(int radioBombas)
{
    this->radioBombas = radioBombas;
}

Posicion Jugador::getPosicion()
{
    return posicion;
}

void Jugador::setPosicion(Posicion posicion)
{
    this->posicion = posicion;
}

void Jugador::sumarPuntos(int puntos)
{
    puntaje += puntos;
}

void Jugador::perderVida()
{
    if (vidas > 0)
        vidas--;
}

bool Jugador::estaVivo()
{
    return vidas > 0;
}
