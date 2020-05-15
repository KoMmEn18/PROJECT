#ifndef BALL_H
#define BALL_H

#include "State.h"
#include "DEFINITIONS.h"

class Ball : public State
{
    public:
        Ball(sf::Color kolor, float x, float y, float radius);
        ~Ball() = default;
        void update(sf::Vector2f howmany);

        float left();
        float right();
        float top();
        float bottom();

        float getPositionX();
        float getPositionY();
        float getRadius();

        void setBallPosition(float x, float y);

    private:
        sf::CircleShape circle;
        float ballRadius;
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif