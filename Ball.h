#ifndef BALL_H
#define BALL_H

#include "Form.h"
#include "DEFINITIONS.h"

class Ball : public Form
{
    public:
        Ball(sf::Color kolor, float x, float y, float radius);
        ~Ball() = default;
        void update(sf::Vector2f howmany);
        float left();
        float right();
        float top();
        float bottom();
        float getRadius();
        void setBallPosition(float x, float y);

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        friend float getX(const Ball *);
        friend float getY(const Ball *);
        friend float operator+(const Ball &, const Ball &);

        sf::CircleShape circle;
        float ballRadius;
};

#endif