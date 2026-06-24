#include "Enemigo.h"

Enemigo::Enemigo()
{
    vidas = 1;
    nivel = 1;
    puntos = 100;
    posicion = Posicion(0, 0);
}

Enemigo::Enemigo(int vidas, int nivel, int puntos, Posicion posicion)
{
    this->vidas = vidas;
    this->nivel = nivel;
    this->puntos = puntos;
    this->posicion = posicion;
}

int Enemigo::getVidas()
{
    return vidas;
}

void Enemigo::setVidas(int vidas)
{
    this->vidas = vidas;
}

int Enemigo::getNivel()
{
    return nivel;
}

void Enemigo::setNivel(int nivel)
{
    this->nivel = nivel;
}

int Enemigo::getPuntos()
{
    return puntos;
}

void Enemigo::setPuntos(int puntos)
{
    this->puntos = puntos;
}

Posicion Enemigo::getPosicion()
{
    return posicion;
}

void Enemigo::setPosicion(Posicion posicion)
{
    this->posicion = posicion;
}

bool Enemigo::estaVivo()
{
    return vidas > 0;
}

void Enemigo::recibirDanio()
{
    if (vidas > 0)
        vidas--;
}

void Enemigo::mover(int anchoMapa, int altoMapa, int* celdas, Posicion posJugador)
{
}
