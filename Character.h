#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"

class Character//: public Object
{
    public:
        sf::RectangleShape sprite;
        sf::Vector2f pos;
        void update(sf::RenderWindow& window);
        Character();
};