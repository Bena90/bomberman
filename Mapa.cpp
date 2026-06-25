#include "Mapa.h"

Mapa::Mapa()
{
    id = 0;
    nivel = 1;
    ancho = 0;
    alto = 0;
    celdas = nullptr;
}

Mapa::Mapa(int id, int nivel, int ancho, int alto)
{
    this->id = id;
    this->nivel = nivel;
    this->ancho = ancho;
    this->alto = alto;
    this->celdas = new int[ancho * alto];

    for (int i = 0; i < ancho * alto; i++)
        celdas[i] = 0;
}

Mapa::~Mapa()
{
    if (celdas != nullptr)
        delete[] celdas;
}

int Mapa::getId()
{
    return id;
}

void Mapa::setId(int id)
{
    this->id = id;
}

int Mapa::getNivel()
{
    return nivel;
}

void Mapa::setNivel(int nivel)
{
    this->nivel = nivel;
}

int Mapa::getAncho()
{
    return ancho;
}

void Mapa::setAncho(int ancho)
{
    this->ancho = ancho;
}

int Mapa::getAlto()
{
    return alto;
}

void Mapa::setAlto(int alto)
{
    this->alto = alto;
}

int* Mapa::getCeldas()
{
    return celdas;
}

int Mapa::getCelda(int x, int y)
{
    if (x >= 0 && x < ancho && y >= 0 && y < alto)
        return celdas[y * ancho + x];
    return 1;
}

void Mapa::setCelda(int x, int y, int valor)
{
    if (x >= 0 && x < ancho && y >= 0 && y < alto)
        celdas[y * ancho + x] = valor;
}

void Mapa::inicializar(int id, int nivel, int ancho, int alto)
{
    if (celdas != nullptr)
        delete[] celdas;

    this->id = id;
    this->nivel = nivel;
    this->ancho = ancho;
    this->alto = alto;
    celdas = new int[ancho * alto];

    for (int i = 0; i < ancho * alto; i++)
        celdas[i] = 0;
}
