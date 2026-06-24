#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Bomberman");
    window.setFramerateLimit(60);

    sf::Font font("assets/font/BOMBERMA.TTF");

    sf::Text titulo(font, "BOMBERMAN", 72);
    titulo.setFillColor(sf::Color::White);
    titulo.setPosition({800 / 2.f - titulo.getGlobalBounds().size.x / 2.f, 60.f});

    const int cantBotones = 3;
    sf::String etiquetas[cantBotones] = {"JUGAR", "PUNTAJES", "SALIR"};

    sf::RectangleShape botones[cantBotones];
    sf::Text textos[cantBotones] = {
        sf::Text(font, "", 36),
        sf::Text(font, "", 36),
        sf::Text(font, "", 36)
    };

    for (int i = 0; i < cantBotones; i++)
    {
        botones[i].setSize({300.f, 60.f});
        botones[i].setFillColor(sf::Color(50, 50, 50));
        botones[i].setOutlineColor(sf::Color::White);
        botones[i].setOutlineThickness(2.f);
        botones[i].setPosition({800 / 2.f - 150.f, 220.f + i * 100.f});

        textos[i].setString(etiquetas[i]);
        textos[i].setFillColor(sf::Color::White);
        float textoX = botones[i].getPosition().x + 150.f - textos[i].getGlobalBounds().size.x / 2.f;
        float textoY = botones[i].getPosition().y + 10.f;
        textos[i].setPosition({textoX, textoY});
    }

    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        while (auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (auto* click = event->getIf<sf::Event::MouseButtonPressed>())
            {
                for (int i = 0; i < cantBotones; i++)
                {
                    if (botones[i].getGlobalBounds().contains(sf::Vector2f(click->position)))
                    {
                        if (i == 2)
                            window.close();
                    }
                }
            }
        }

        for (int i = 0; i < cantBotones; i++)
        {
            if (botones[i].getGlobalBounds().contains(sf::Vector2f(mousePos)))
                botones[i].setFillColor(sf::Color(100, 100, 100));
            else
                botones[i].setFillColor(sf::Color(50, 50, 50));
        }

        window.clear(sf::Color(30, 30, 30));
        window.draw(titulo);
        for (int i = 0; i < cantBotones; i++)
        {
            window.draw(botones[i]);
            window.draw(textos[i]);
        }
        window.display();
    }

    return 0;
}
