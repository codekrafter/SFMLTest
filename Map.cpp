#include <SFML/Graphics.hpp>
#include <iostream>
#include "Object.h"
#include "main.h"

class Map
{
    public:
        std::vector<sf::RectangleShape> sprites;
        int l;
        bool ready = false;
        
        /// Creates a new map, ww is window width, ww is window height, tw is tile width and th is tile height
        Map(int ww, int wh, int tw, int th)
        {
            /*if (ww % tw != 0) || (wh % th != 0))
            {
                throw std::length_error("tiles do not fit evenly in the window size. Please correct that.");
                return;
            }*/

            int w = ww/tw;
            int h = wh/th;
            int tileNum = w*h;
            int i = 0;
            while (i < tileNum)
            {
                sf::RectangleShape tile = sf::RectangleShape(sf::Vector2f(tw,th));
                if(i % 2)
                {
                    tile.setFillColor(sf::Color::Yellow);
                }
                else
                {
                    tile.setFillColor(sf::Color::Red);
                }
                sf::Vector2f pos = sf::Vector2f();
                pos.x = i/w;
                pos.x = pos.x*tw;
                //std::cout << i << std::endl << std::flush;
                pos.y = i%10;
                pos.y = pos.y * th;
                //std::cout << pos.x << "," << pos.y << std::endl << std::flush;
                tile.setPosition(pos);
                sprites.push_back(tile);
                l++;
                i++;
            }
            ready = true;
        }
        void update(sf::RenderWindow& window)
        {
            if (ready = false)
                return;
            int i = 0;
            while(i < l-1)
            {
                try {
                    window.draw(sprites.at(i));
                } catch (const std::exception e)
                {
                    return;
                }
                i++;
            }
        }
};