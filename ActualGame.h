#ifndef ACTUAL_GAME_H
#define ACTUAL_GAME_H

#include "State.h"
#include "Ball.h"
#include "DEFINITIONS.h"

class ActualGame : public State
{
    public:
        static void setActualGame();

        static void player1move(sf::Vector2f howmany);
        static void player2move(sf::Vector2f howmany);

        static void ballUpdate();
        static void playerUpdate();

        static bool didPlayersCollided();
        static bool didBallAndPlayer1Collided();
        static bool didBallAndPlayer2Collided();

        static bool canMove();
        static bool canMove2();
        static bool canMove3();
        static bool canMove4();

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

        inline static Ball* player1 = new Ball(sf::Color::Red, WINDOW_WIDTH/2,40, 25.0);
        inline static Ball* player2 = new Ball(sf::Color::Blue, WINDOW_WIDTH/2,WINDOW_HEIGHT-40, 25.0);

        inline static Ball* ball = new Ball(sf::Color::Green, WINDOW_WIDTH/2,WINDOW_HEIGHT/2, 15.0);

    protected:
        inline static sf::Texture textureBackground;
        inline static sf::Sprite spriteBackground;
};

#endif