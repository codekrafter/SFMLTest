#include <SFML/Graphics.hpp>
#include <iostream>

enum class MOVEDIRECTION
{
    X,
    Y
};

class Movement
{
    public:
        void move(MOVEDIRECTION dir, float force);
        void update(sf::Vector2f &pos);
    private:
        float xAccel;
        float xAccelOld;
        float yAccel;
        float yAccelOld;
};