#include "ActualGame.h"
#include <iostream>
#include <cmath>
#include <unistd.h>

void ActualGame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(spriteBackground);
    target.draw(*ball);
    target.draw(*player1);
    target.draw(*player2);
}

void ActualGame::playerUpdate()
{
    sf::Vector2i movementControlplayer1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player1->top() > 7 && canMove(player1, player2) && canMove(player1, ball))
        --movementControlplayer1.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player1->bottom() < WINDOW_HEIGHT - 7 && canMove2(player1, player2) && canMove2(player1, ball))
        ++movementControlplayer1.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player1->left() > 7 && canMove4(player1, player2) && canMove4(player1, ball))
        --movementControlplayer1.x;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player1->right() < WINDOW_WIDTH - 7 && canMove3(player1, player2) && canMove3(player1, ball))
        ++movementControlplayer1.x;
    sf::Vector2f movement1(movementControlplayer1);
    if (movementControlplayer1.x != 0 && movementControlplayer1.y != 0)
        movement1 *= 0.707f;
    player1move(movement1);

    sf::Vector2i movementControlplayer2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player2->top() > 7 && canMove2(player1, player2) && canMove2(ball, player2))
        --movementControlplayer2.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player2->bottom() < WINDOW_HEIGHT - 7 && canMove(player1, player2) && canMove(ball, player2))
        ++movementControlplayer2.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player2->left() > 7 && canMove3(player1, player2) && canMove3(player1, ball) && canMove3(ball, player2))
        --movementControlplayer2.x;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player2->right() < WINDOW_WIDTH - 7 && canMove4(player1, player2) && canMove4(ball, player2))
        ++movementControlplayer2.x;
    sf::Vector2f movement2(movementControlplayer2);
    if (movementControlplayer2.x != 0 && movementControlplayer2.y != 0)
        movement2 *= 0.707f;
    player2move(movement2);
}

bool ActualGame::didCollided(Ball* first, Ball* second)
{
	float dx = (first->getPositionX()) - (second->getPositionX());
	float dy = (first->getPositionY()) - (second->getPositionY());
	float distance = std::sqrt((dx * dx) + (dy * dy));

	if (distance < first->getRadius() + second->getRadius())
	{
		return true;
	}
	
    return false;
}

bool ActualGame::canMove(Ball* first, Ball* second)
{
    if(didCollided(first, second) && (first->getPositionY() > second->getPositionY()))
        return false;

    return true;
}

bool ActualGame::canMove2(Ball* first, Ball* second)
{
    if(didCollided(first, second) && (first->getPositionY() < second->getPositionY()))
        return false;

    return true;
}

bool ActualGame::canMove3(Ball* first, Ball* second)
{
    if(didCollided(first, second) && (first->getPositionX() < second->getPositionX()))
        return false;

    return true;
}

bool ActualGame::canMove4(Ball* first, Ball* second)
{
    if(didCollided(first, second) && (first->getPositionX() > second->getPositionX()))
        return false;

    return true;
}

void ActualGame::setActualGame()
{
    ActualGame::gameBackground();
}

void ActualGame::ballUpdate()
{
    ball->update(velocity);
    
    if(ball->left() < 5)
    {
        velocity.x = ballVelocity;
    }
    else if(ball->right() > WINDOW_WIDTH-5)
    {
        velocity.x = -ballVelocity;
    }
    else if(ball->top() < 5 && (ball->getPositionX() < 165 || ball->getPositionX() > 395))
    {
        velocity.y = ballVelocity;
    }
    else if(ball->bottom() > WINDOW_HEIGHT-5 && (ball->getPositionX() < 165 || ball->getPositionX() > 395))
    {
        velocity.y = -ballVelocity;
    }

    if(ball->getPositionY() + ball->getRadius() + 1 < 0)
    {
        std::cout << "Player 2 Goal" << std::endl;
        player2Score++;
        sleep(1);
        setAfterPlayer2Scores();
    }
    if(ball->getPositionY() - ball->getRadius() - 1 > WINDOW_HEIGHT)
    {
        std::cout << "Player 1 Goal" << std::endl;
        player1Score++;
        sleep(1);
        setAfterPlayer1Scores();
    }

    ballCollision();
}

void ActualGame::setAfterPlayer1Scores()
{
    player1->setBallPosition(WINDOW_WIDTH/2,40);
    player2->setBallPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT-40);
    ball->setBallPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 + 260);
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    sleep(1);
}

void ActualGame::setAfterPlayer2Scores()
{
    player1->setBallPosition(WINDOW_WIDTH/2,40);
    player2->setBallPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT-40);
    ball->setBallPosition(WINDOW_WIDTH/2, WINDOW_HEIGHT/2 - 260);
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    sleep(1);
}

void ActualGame::ballCollision()
{
    if(didCollided(ball, player1) && didCollided(ball, player2))
    {
        velocity.x = 0.0f;
        velocity.y = 0.0f;
    } 
    else if(didCollided(ball, player1))
    {
        ballVelocity = 4.0f;

        if(ball->getPositionY() > player1->getPositionY())
        {
            velocity.y = ballVelocity;
        }
        if(ball->getPositionY() < player1->getPositionY())
        {
            velocity.y = -ballVelocity;
        }
        if(ball->getPositionX() < player1->getPositionX())
        {
            velocity.x = -ballVelocity;
        }
        if(ball->getPositionX() > player1->getPositionX())
        {
            velocity.x = ballVelocity;
        }
    }

    else if(didCollided(ball, player2))
    {
        ballVelocity = 4.0f;

        if(ball->getPositionY() > player2->getPositionY())
        {
            velocity.y = ballVelocity;
        }
        if(ball->getPositionY() < player2->getPositionY())
        {
            velocity.y = -ballVelocity;
        }
        if(ball->getPositionX() < player2->getPositionX())
        {
            velocity.x = -ballVelocity;
        }
        if(ball->getPositionX() > player2->getPositionX())
        {
            velocity.x = ballVelocity;
        }
    }
}

void ActualGame::player1move(sf::Vector2f howmany)
{
    player1->update(howmany * SPEED);
}

void ActualGame::player2move(sf::Vector2f howmany)
{
    player2->update(howmany * SPEED);
}

void ActualGame::gameBackground()
{
    if(!textureBackground.loadFromFile("Sources/img/BlackBackground.png", sf::IntRect(0, 0,WINDOW_WIDTH,WINDOW_HEIGHT)))
    {
        exit(EXIT_FAILURE);
    }
    textureBackground.setSmooth(true);

    spriteBackground.setTexture(textureBackground);
}