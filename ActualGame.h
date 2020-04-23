#ifndef ACTUAL_GAME_H
#define ACTUAL_GAME_H

#include "State.h"
#include "DEFINITIONS.h"

class ActualGame : public State
{
    public:
        static void setActualGame();
    
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        static void gameBackground();
        static void setBall();
        static sf::CircleShape ballMaker();

    protected:
        inline static sf::Texture textureBackground;
        inline static sf::Sprite spriteBackground;
        inline static sf::CircleShape ball = ballMaker();

};

#endif