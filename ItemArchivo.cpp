#include "ItemArchivo.h"
#include <cstdio>
#include <cstring>

ItemArchivo::ItemArchivo()
{
    strcpy(nombre, "datos/Items.dat");
}

ItemArchivo::ItemArchivo(const char* nombre)
{
    strncpy(this->nombre, nombre, 49);
    this->nombre[49] = '\0';
}

bool ItemArchivo::guardar(Item item)
{
    FILE* archivo = fopen(nombre, "ab");
    if (archivo == nullptr)
        return false;

    int escrito = fwrite(&item, sizeof(Item), 1, archivo);
    fclose(archivo);
    return escrito == 1;
}

Item ItemArchivo::leer(int indice)
{
    Item item;
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == nullptr)
        return item;

    fseek(archivo, indice * sizeof(Item), SEEK_SET);
    fread(&item, sizeof(Item), 1, archivo);
    fclose(archivo);
    return item;
}

int ItemArchivo::cantidadRegistros()
{
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == nullptr)
        return 0;

    fseek(archivo, 0, SEEK_END);
    int cantidad = ftell(archivo) / sizeof(Item);
    fclose(archivo);
    return cantidad;
}

bool ItemArchivo::actualizar(Item item, int indice)
{
    FILE* archivo = fopen(nombre, "r+b");
    if (archivo == nullptr)
        return false;

    fseek(archivo, indice * sizeof(Item), SEEK_SET);
    int escrito = fwrite(&item, sizeof(Item), 1, archivo);
    fclose(archivo);
    return escrito == 1;
}
