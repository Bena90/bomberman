#include <SFML/Graphics.hpp>
#include "Menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Bomberman");
    window.setFramerateLimit(60);

    Menu menu;

    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (auto* click = event->getIf<sf::Event::MouseButtonPressed>())
            {
                int boton = menu.detectarClick(sf::Vector2f(click->position));
                if (boton == 2)
                    window.close();
            }
        }

        menu.actualizarHover(mousePos);

        window.clear(sf::Color(30, 30, 30));
        menu.dibujar(window);
        window.display();
    }

    return 0;
}
