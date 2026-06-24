#include "Menu.h"

Menu::Menu() : font("assets/font/BOMBERMA.TTF"),
               titulo(font, "BOMBERMAN", 72),
               textos{sf::Text(font, "", 36), sf::Text(font, "", 36), sf::Text(font, "", 36)},
               botonSeleccionado(-1)
{
    titulo.setFillColor(sf::Color::White);
    titulo.setPosition({800 / 2.f - titulo.getGlobalBounds().size.x / 2.f, 60.f});

    sf::String etiquetas[3] = {"JUGAR", "PUNTAJES", "SALIR"};

    for (int i = 0; i < 3; i++)
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
}

void Menu::dibujar(sf::RenderWindow& window)
{
    window.draw(titulo);
    for (int i = 0; i < 3; i++)
    {
        window.draw(botones[i]);
        window.draw(textos[i]);
    }
}

int Menu::detectarClick(sf::Vector2f posClick)
{
    for (int i = 0; i < 3; i++)
    {
        if (botones[i].getGlobalBounds().contains(posClick))
        {
            botonSeleccionado = i;
            return i;
        }
    }
    return -1;
}

void Menu::actualizarHover(sf::Vector2i posMouse)
{
    for (int i = 0; i < 3; i++)
    {
        if (botones[i].getGlobalBounds().contains(sf::Vector2f(posMouse)))
            botones[i].setFillColor(sf::Color(100, 100, 100));
        else
            botones[i].setFillColor(sf::Color(50, 50, 50));
    }
}

int Menu::getBotonSeleccionado()
{
    return botonSeleccionado;
}
