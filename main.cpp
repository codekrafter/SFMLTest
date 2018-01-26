#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.cpp"
#include "Map.cpp"
#include "main.h"

void ckprint(std::string m, float f)
{
     std::cout << m << f << std::endl << std::flush;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Game Engine");
    sf::RectangleShape shape(sf::Vector2f(100,100));
    sf::Vector2f pos(0,0);
    Character character = Character();
    Map map = Map(500,500,50,50);

    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos);
    ckprint("", 0 % 2);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            /*if (event.type == sf::Event::MouseButtonPressed)
                shape.setFillColor(sf::Color::Red);*/
            if (event.type == sf::Event::KeyPressed)
                //std::cout << event.key.code << std::endl << std::flush;
               switch (event.key.code)
                {
                    case 73:
                        pos.y = pos.y - 50;
                        break;
                    case 74:
                        pos.y = pos.y + 50;
                        break;
                    case 71:
                        pos.x = pos.x - 50;
                        break;
                    case 72:
                        pos.x = pos.x + 50;
                        break;
                }

        }

        window.clear();
        //shape.setPosition(pos);
        character.pos = pos;
        map.update(window);
        character.update(window);
        //window.draw(shape);
        window.display();
    }

    return 0;
}