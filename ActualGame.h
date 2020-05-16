#ifndef ACTUAL_GAME_H
#define ACTUAL_GAME_H

#include "State.h"
#include "Ball.h"
#include "DEFINITIONS.h"
#include <string>
#include <iostream>
#include <cmath>
#include <unistd.h>

class ActualGame : public State
{
    public:
        static void setActualGame();

        static void player1move(sf::Vector2f howmany);
        static void player2move(sf::Vector2f howmany);

        static void ballUpdate();
        static void playerUpdate();

        static int getPlayer1Score();
        static int getPlayer2Score();

        static void setStartSetup();

        inline static bool canOpenGameOverPage = false;

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        static void gameBackground();

        static bool didCollided(Ball* first, Ball* second);
        static void ballCollision();

        static bool canMove(Ball* first, Ball* second);
        static bool canMove2(Ball* first, Ball* second);
        static bool canMove3(Ball* first, Ball* second);
        static bool canMove4(Ball* first, Ball* second);

        static void setAfterPlayer1Scores();
        static void setAfterPlayer2Scores();

        static void setPlayerScoresMsg(sf::Text * playerText, std::string msg, float change, sf::Color color);
        static void setPlayerScore(sf::Text * player, sf::Color color, float change);

        static void updatePlayerScore(sf::Text * player, std::string score);

        static void setFont(const char *name);

        inline static float ballVelocity = 0.0f;
        inline static sf::Vector2f velocity{ballVelocity, ballVelocity};

        inline static Ball* player1 = new Ball(sf::Color::Red, WINDOW_WIDTH/2,40, 25.0);
        inline static Ball* player2 = new Ball(sf::Color::Blue, WINDOW_WIDTH/2,WINDOW_HEIGHT-40, 25.0);

        inline static Ball* ball = new Ball(sf::Color::Green, WINDOW_WIDTH/2,WINDOW_HEIGHT/2, 15.0);

        inline static sf::Texture textureBackground;
        inline static sf::Sprite spriteBackground;

        inline static int player1Score = 0;
        inline static int player2Score = 0;
        inline static sf::Text player1Scoretxt;
        inline static sf::Text player2Scoretxt;

        inline static sf::Font font;
        inline static sf::Text player1ScoresMsg;
        inline static sf::Text player2ScoresMsg;

        inline static bool mark1 = false;
        inline static bool mark2 = false;

};

#endif