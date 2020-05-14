#include "Ball.h"

Ball::Ball(sf::Color kolor, float x, float y, float radius)
{
    circle.setRadius(radius);
    circle.setFillColor(kolor);
    circle.setOrigin(radius, radius);
    circle.setPosition(x, y);
    circle.setPointCount(200);
}

void Ball::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(this->circle);
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
