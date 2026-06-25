#include "MapaArchivo.h"
#include <cstdio>
#include <cstring>

MapaArchivo::MapaArchivo()
{
    strcpy(nombreMapa, "datos/Mapa.dat");
    strcpy(nombreCeldas, "datos/MapaCeldas.dat");
}

bool MapaArchivo::guardar(Mapa& mapa)
{
    FILE* archivo = fopen(nombreMapa, "wb");
    if (archivo == nullptr)
        return false;

    int datos[4];
    datos[0] = mapa.getId();
    datos[1] = mapa.getNivel();
    datos[2] = mapa.getAncho();
    datos[3] = mapa.getAlto();

    fwrite(datos, sizeof(int), 4, archivo);
    fclose(archivo);

    archivo = fopen(nombreCeldas, "wb");
    if (archivo == nullptr)
        return false;

    int total = mapa.getAncho() * mapa.getAlto();
    fwrite(mapa.getCeldas(), sizeof(int), total, archivo);
    fclose(archivo);

    return true;
}

bool MapaArchivo::leer(Mapa& mapa)
{
    FILE* archivo = fopen(nombreMapa, "rb");
    if (archivo == nullptr)
        return false;

    int datos[4];
    fread(datos, sizeof(int), 4, archivo);
    fclose(archivo);

    int id = datos[0];
    int nivel = datos[1];
    int ancho = datos[2];
    int alto = datos[3];

    mapa.inicializar(id, nivel, ancho, alto);

    archivo = fopen(nombreCeldas, "rb");
    if (archivo == nullptr)
        return false;

    fread(mapa.getCeldas(), sizeof(int), ancho * alto, archivo);
    fclose(archivo);

    return true;
}
