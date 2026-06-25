#include "Juego.h"
#include <cstdlib>

Juego::Juego()
{
    jugando = false;
    tamCelda = 40;
    offsetX = 100;
    offsetY = 60;
}

void Juego::iniciarNivel(int nivel)
{
    jugando = true;
    generarMapa(15, 13);
}

void Juego::generarMapa(int ancho, int alto)
{
    mapa.inicializar(1, 1, ancho, alto);

    for (int y = 0; y < alto; y++)
    {
        for (int x = 0; x < ancho; x++)
        {
            if (x == 0 || y == 0 || x == ancho - 1 || y == alto - 1)
                mapa.setCelda(x, y, 1);
            else if (x % 2 == 0 && y % 2 == 0)
                mapa.setCelda(x, y, 1);
            else if ((x == 1 && y == 1) || (x == 2 && y == 1) || (x == 1 && y == 2))
                mapa.setCelda(x, y, 0);
            else if (rand() % 100 < 40)
                mapa.setCelda(x, y, 2);
        }
    }
}

void Juego::dibujar(sf::RenderWindow& window)
{
    sf::RectangleShape celda(sf::Vector2f(tamCelda - 1, tamCelda - 1));

    for (int y = 0; y < mapa.getAlto(); y++)
    {
        for (int x = 0; x < mapa.getAncho(); x++)
        {
            int tipo = mapa.getCelda(x, y);

            if (tipo == 0)
                celda.setFillColor(sf::Color(100, 180, 100));  
            else if (tipo == 1)
                celda.setFillColor(sf::Color(80, 80, 80)); 
            else if (tipo == 2)
                celda.setFillColor(sf::Color(180, 120, 60));

            celda.setPosition(sf::Vector2f(offsetX + x * tamCelda, offsetY + y * tamCelda));
            window.draw(celda);
        }
    }
}

bool Juego::estaJugando()
{
    return jugando;
}
