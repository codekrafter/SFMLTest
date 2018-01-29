#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "Object.h"
#include "main.h"

class Map
{
    public:
        std::vector<sf::RectangleShape> sprites;
        int l;
        bool ready;
        
        /// Creates a new map, ww is window width, ww is window height, tw is tile width and th is tile height
        Map(int ww, int wh, int tw, int th)
        {
            if ((ww % tw != 0) || (wh % th != 0))
            {
                throw std::length_error("tiles do not fit evenly in the window size. Please correct that.");
                return;
            }

            int w = ww/tw;
            ckprint("", w);
            int h = wh/th;
            ckprint("", h);
            int tileNum = w*h;
            ckprint("", tileNum);
            int i = 0;
            int o = 0;
            bool toggle = false;
            while (i < tileNum)
            {
                /*if(i%2 && i > 0)
                {
                    o = 2;
                } else
                {
                    o = i;
                }*/
                sf::RectangleShape tile = sf::RectangleShape(sf::Vector2f(tw,th));
                int z = i/2;
                if(toggle)
                {
                    tile.setFillColor(sf::Color::White);
                    toggle = !toggle;
                }
                else
                {
                    tile.setFillColor(sf::Color(150,150,150));
                    toggle = !toggle;
                }
                sf::Vector2f pos = sf::Vector2f();
                pos.x = i/w;
                pos.x = pos.x*tw;
                //std::cout << i << std::endl << std::flush;
                pos.y = i%10;
                //pos.y = pos.y - o;
                pos.y = pos.y * th;
                //std::cout << i << "," << pos.x << "," << pos.y << "," << o << std::endl << std::flush;
                tile.setPosition(pos);
                sprites.push_back(tile);
                l++;
                i++;
                //tile = sf::RectangleShape();
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