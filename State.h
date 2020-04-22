#ifndef STATE_H
#define STATE_H

#include <SFML/Graphics.hpp>

class State : public sf::Drawable
{
    public:
        State();
        virtual ~State() {}
        void setPrevious(State *);

    private:
        State *m_previous;
};
#endif