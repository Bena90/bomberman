#include "EnemigoArchivo.h"
#include <cstdio>
#include <cstring>

EnemigoArchivo::EnemigoArchivo()
{
    strcpy(nombre, "datos/Enemigos.dat");
}

EnemigoArchivo::EnemigoArchivo(const char* nombre)
{
    strncpy(this->nombre, nombre, 49);
    this->nombre[49] = '\0';
}

bool EnemigoArchivo::guardar(Enemigo enemigo)
{
    FILE* archivo = fopen(nombre, "ab");
    if (archivo == nullptr)
        return false;

    int escrito = fwrite(&enemigo, sizeof(Enemigo), 1, archivo);
    fclose(archivo);
    return escrito == 1;
}

Enemigo EnemigoArchivo::leer(int indice)
{
    Enemigo enemigo;
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == nullptr)
        return enemigo;

    fseek(archivo, indice * sizeof(Enemigo), SEEK_SET);
    fread(&enemigo, sizeof(Enemigo), 1, archivo);
    fclose(archivo);
    return enemigo;
}

int EnemigoArchivo::cantidadRegistros()
{
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == nullptr)
        return 0;

    fseek(archivo, 0, SEEK_END);
    int cantidad = ftell(archivo) / sizeof(Enemigo);
    fclose(archivo);
    return cantidad;
}

bool EnemigoArchivo::actualizar(Enemigo enemigo, int indice)
{
    FILE* archivo = fopen(nombre, "r+b");
    if (archivo == nullptr)
        return false;

    fseek(archivo, indice * sizeof(Enemigo), SEEK_SET);
    int escrito = fwrite(&enemigo, sizeof(Enemigo), 1, archivo);
    fclose(archivo);
    return escrito == 1;
}
