#ifndef ITEMARCHIVO_H
#define ITEMARCHIVO_H

#include "Item.h"

class ItemArchivo
{
private:
    char nombre[50];

public:
    ItemArchivo();
    ItemArchivo(const char* nombre);
    bool guardar(Item item);
    Item leer(int indice);
    int cantidadRegistros();
    bool actualizar(Item item, int indice);
};

#endif
