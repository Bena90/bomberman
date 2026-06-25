#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Menu.h"
#include "Juego.h"

int main()
{
    srand(time(nullptr));

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Bomberman");
    window.setFramerateLimit(60);

    Menu menu;
    Juego juego;
    int estado = 0; // 0=menu, 1=jugando

    while (window.isOpen())
    {
        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (estado == 0)
            {
                if (auto* click = event->getIf<sf::Event::MouseButtonPressed>())
                {
                    int boton = menu.detectarClick(sf::Vector2f(click->position));
                    if (boton == 0)
                    {
                        juego.iniciarNivel(1);
                        estado = 1;
                    }
                    else if (boton == 2)
                        window.close();
                }
            }
            else if (estado == 1)
            {
                if (auto* keyEvent = event->getIf<sf::Event::KeyPressed>())
                {
                    if (keyEvent->code == sf::Keyboard::Key::Escape)
                        estado = 0;
                }
            }
        }

        window.clear(sf::Color(30, 30, 30));

        if (estado == 0)
        {
            menu.actualizarHover(sf::Mouse::getPosition(window));
            menu.dibujar(window);
        }
        else if (estado == 1)
        {
            juego.dibujar(window);
        }

        window.display();
    }

    return 0;
}
