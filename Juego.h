#ifndef JUEGO_H
#define JUEGO_H

#include <SFML/Graphics.hpp>
#include "Mapa.h"

class Juego
{
private:
    Mapa mapa;
    bool jugando;
    int tamCelda;
    int offsetX;
    int offsetY;

    void generarMapa(int ancho, int alto);

public:
    Juego();
    void iniciarNivel(int nivel);
    void dibujar(sf::RenderWindow& window);
    bool estaJugando();
};

#endif
