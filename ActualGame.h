#ifndef ACTUAL_GAME_H
#define ACTUAL_GAME_H

#include "State.h"
#include "DEFINITIONS.h"

class ActualGame : public State
{
    public:
        static void setActualGame();

        static void player1move(sf::Vector2f howmany);
        static void player2move(sf::Vector2f howmany);

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        static void gamePlayerSet();

        static void gameBackground();

    protected:
        inline static sf::Texture textureBackground;
        inline static sf::Sprite spriteBackground;

        inline static sf::Texture player1Texture;
        inline static sf::Sprite player1Sprite;

        inline static sf::Texture player2Texture;
        inline static sf::Sprite player2Sprite;
};

#endif