#ifndef FORM_H
#define FORM_H

#include "State.h"

class Form : public State
{
    public:
        virtual void update(sf::Vector2f howmany) = 0;
};

#endif