#ifndef FORM_H
#define FORM_H

#include <SFML/Graphics.hpp>

class Form : public sf::Drawable
{
    public:
        virtual void update(sf::Vector2f howmany) = 0;
};

#endif