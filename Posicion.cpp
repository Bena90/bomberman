#include "Posicion.h"

Posicion::Posicion()
{
    x = 0;
    y = 0;
}

Posicion::Posicion(int x, int y)
{
    this->x = x;
    this->y = y;
}

int Posicion::getX()
{
    return x;
}

int Posicion::getY()
{
    return y;
}

void Posicion::setX(int x)
{
    this->x = x;
}

void Posicion::setY(int y)
{
    this->y = y;
}
