#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>

class Menu
{
private:
    sf::Font font;
    sf::Text titulo;
    sf::RectangleShape botones[3];
    sf::Text textos[3];
    int botonSeleccionado;

public:
    Menu();
    void dibujar(sf::RenderWindow& window);
    int detectarClick(sf::Vector2f posClick);
    void actualizarHover(sf::Vector2i posMouse);
    int getBotonSeleccionado();
};

#endif
