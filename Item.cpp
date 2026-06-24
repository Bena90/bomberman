#include "Item.h"

Item::Item()
{
    tipo = 0;
    posicion = Posicion(0, 0);
    activo = false;
}

Item::Item(int tipo, Posicion posicion)
{
    this->tipo = tipo;
    this->posicion = posicion;
    this->activo = true;
}

int Item::getTipo()
{
    return tipo;
}

void Item::setTipo(int tipo)
{
    this->tipo = tipo;
}

Posicion Item::getPosicion()
{
    return posicion;
}

void Item::setPosicion(Posicion posicion)
{
    this->posicion = posicion;
}

bool Item::getActivo()
{
    return activo;
}

void Item::setActivo(bool activo)
{
    this->activo = activo;
}
