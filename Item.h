#ifndef ITEM_H
#define ITEM_H

#include "Posicion.h"

class Item
{
private:
    int tipo;
    Posicion posicion;
    bool activo;

public:
    Item();
    Item(int tipo, Posicion posicion);
    int getTipo();
    void setTipo(int tipo);
    Posicion getPosicion();
    void setPosicion(Posicion posicion);
    bool getActivo();
    void setActivo(bool activo);
};

#endif
