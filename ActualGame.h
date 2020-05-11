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

        static void ballUpdate();

        static int didCollided();

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        static void playerSet();
        static void ballSet();
        static float ballLeft();
        static float ballRight();
        static float ballTop();
        static float ballBottom();
        static void gameBackground();
        inline static float ballVelocity = 3.0f;
        inline static sf::Vector2f velocity{ballVelocity, ballVelocity};

    protected:
        inline static sf::Texture textureBackground;
        inline static sf::Sprite spriteBackground;

        inline static sf::Texture player1Texture;
        inline static sf::Sprite player1Sprite;

        inline static sf::Texture player2Texture;
        inline static sf::Sprite player2Sprite;

        inline static sf::Texture ballTexture;
        inline static sf::Sprite ballSprite;
};

#endif