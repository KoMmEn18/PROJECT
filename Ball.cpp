#include "Ball.h"

Ball::Ball(sf::Color kolor, float x, float y, float radius)
{
    circle.setRadius(radius);
    circle.setFillColor(kolor);
    circle.setOrigin(radius, radius);
    circle.setPosition(x, y);
    circle.setPointCount(200);
}

void Ball::update(sf::Vector2f howmany)
{
    circle.move(howmany);
}

float Ball::left()
{
    return circle.getPosition().x - circle.getRadius();
}

float Ball::right()
{
    return circle.getPosition().x + circle.getRadius();
}

float Ball::top()
{
    return circle.getPosition().y - circle.getRadius();
}

float Ball::bottom()
{
    return circle.getPosition().y + circle.getRadius();
}

float Ball::getRadius()
{
    return circle.getRadius();
}

void Ball::setBallPosition(float x, float y)
{
    circle.setPosition(x,y);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->circle);
}

float getX(const Ball *p)
{
    return p->circle.getPosition().x;
}

float getY(const Ball *p)
{
    return p->circle.getPosition().y;
}

float operator+(const Ball &b1, const Ball &b2)
{
    return b1.circle.getRadius() + b2.circle.getRadius();
}