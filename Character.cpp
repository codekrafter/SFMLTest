#include <SFML/Graphics.hpp>
#include <iostream>
#include "Character.h"
#include "Object.cpp"

    Character::Character() {
        sprite = sf::RectangleShape(sf::Vector2f(50,50));

        sprite.setFillColor(sf::Color::Green);
        sprite.setPosition(0,0);
}

void Character::update(sf::RenderWindow& window) {
    sprite.setPosition(pos);
    window.draw(sprite);
}