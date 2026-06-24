#include "JugadorArchivo.h"
#include <cstdio>
#include <cstring>

JugadorArchivo::JugadorArchivo()
{
    strcpy(nombre, "datos/Jugadores.dat");
}

JugadorArchivo::JugadorArchivo(const char* nombre)
{
    strncpy(this->nombre, nombre, 49);
    this->nombre[49] = '\0';
}

bool JugadorArchivo::guardar(Jugador jugador)
{
    FILE* archivo = fopen(nombre, "ab");
    if (archivo == nullptr)
        return false;

    int escrito = fwrite(&jugador, sizeof(Jugador), 1, archivo);
    fclose(archivo);
    return escrito == 1;
}

Jugador JugadorArchivo::leer(int indice)
{
    Jugador jugador;
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == nullptr)
        return jugador;

    fseek(archivo, indice * sizeof(Jugador), SEEK_SET);
    fread(&jugador, sizeof(Jugador), 1, archivo);
    fclose(archivo);
    return jugador;
}

int JugadorArchivo::cantidadRegistros()
{
    FILE* archivo = fopen(nombre, "rb");
    if (archivo == nullptr)
        return 0;

    fseek(archivo, 0, SEEK_END);
    int cantidad = ftell(archivo) / sizeof(Jugador);
    fclose(archivo);
    return cantidad;
}

bool JugadorArchivo::actualizar(Jugador jugador, int indice)
{
    FILE* archivo = fopen(nombre, "r+b");
    if (archivo == nullptr)
        return false;

    fseek(archivo, indice * sizeof(Jugador), SEEK_SET);
    int escrito = fwrite(&jugador, sizeof(Jugador), 1, archivo);
    fclose(archivo);
    return escrito == 1;
}
