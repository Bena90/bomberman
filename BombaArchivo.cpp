#include "BombaArchivo.h"
#include <cstdio>
#include <cstring>

BombaArchivo::BombaArchivo()
{
    strcpy(nombre, "datos/Bombas.dat");
}

BombaArchivo::BombaArchivo(const char* nombre)
{
    strncpy(this->nombre, nombre, 49);
    this->nombre[49] = '\0';
}

bool BombaArchivo::guardar(Bomba bomba)
{
    FILE* archivo = fopen(nombre, "ab");
    if (archivo == nullptr)
        return false;

    int escrito = fwrite(&bomba, sizeof(Bomba), 1, archivo);
    fclose(archivo);
    return escrito == 1;
}

Bomba BombaArchivo::leer(int indice)
{
    Bomba bomba;
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == nullptr)
        return bomba;

    fseek(archivo, indice * sizeof(Bomba), SEEK_SET);
    fread(&bomba, sizeof(Bomba), 1, archivo);
    fclose(archivo);
    return bomba;
}

int BombaArchivo::cantidadRegistros()
{
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == nullptr)
        return 0;

    fseek(archivo, 0, SEEK_END);
    int cantidad = ftell(archivo) / sizeof(Bomba);
    fclose(archivo);
    return cantidad;
}

bool BombaArchivo::actualizar(Bomba bomba, int indice)
{
    FILE* archivo = fopen(nombre, "r+b");
    if (archivo == nullptr)
        return false;

    fseek(archivo, indice * sizeof(Bomba), SEEK_SET);
    int escrito = fwrite(&bomba, sizeof(Bomba), 1, archivo);
    fclose(archivo);
    return escrito == 1;
}
