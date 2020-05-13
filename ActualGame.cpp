#include "ActualGame.h"
#include <iostream>
#include <cmath>

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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && player1->top() > 7 && canMove())
        --movementControlplayer1.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && player1->bottom() < WINDOW_HEIGHT - 7 && canMove2())
        ++movementControlplayer1.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && player1->left() > 7 && canMove4())
        --movementControlplayer1.x;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && player1->right() < WINDOW_WIDTH - 7 && canMove3())
        ++movementControlplayer1.x;
    sf::Vector2f movement1(movementControlplayer1);
    if (movementControlplayer1.x != 0 && movementControlplayer1.y != 0)
        movement1 *= 0.707f;
    player1move(movement1);

    sf::Vector2i movementControlplayer2;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player2->top() > 7 && canMove2())
        --movementControlplayer2.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player2->bottom() < WINDOW_HEIGHT - 7 && canMove())
        ++movementControlplayer2.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player2->left() > 7 && canMove3())
        --movementControlplayer2.x;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player2->right() < WINDOW_WIDTH - 7 && canMove4())
        ++movementControlplayer2.x;
    sf::Vector2f movement2(movementControlplayer2);
    if (movementControlplayer2.x != 0 && movementControlplayer2.y != 0)
        movement2 *= 0.707f;
    player2move(movement2);
}

bool ActualGame::didPlayersCollided()
{
    sf::FloatRect shape1 = player1->circle.getGlobalBounds();
	sf::FloatRect shape2 = player2->circle.getGlobalBounds();

	float dx = (player1->circle.getPosition().x + (shape1.width / 2)) - (player2->circle.getPosition().x + (shape2.width / 2));
	float dy = (player1->circle.getPosition().y + (shape1.height / 2)) - (player2->circle.getPosition().y + (shape2.height / 2));
	float distance = std::sqrt((dx * dx) + (dy * dy));

	if (distance <= (shape1.width / 2) + (shape2.width / 2))
	{
		return true;
	}
	
    return false;
}

bool ActualGame::didBallAndPlayer1Collided()
{
    sf::FloatRect shape1 = player1->circle.getGlobalBounds();
	sf::FloatRect shape2 = ball->circle.getGlobalBounds();

	float dx = (player1->circle.getPosition().x + 12.5) - (ball->circle.getPosition().x + 7.5);
	float dy = (player1->circle.getPosition().y + 12.5) - (ball->circle.getPosition().y + 7.5);
	float distance = std::sqrt((dx * dx) + (dy * dy));

	if (distance <= (shape1.width / 2) + (shape2.width / 2))
	{
		return true;
	}
	
    return false;
}

bool ActualGame::didBallAndPlayer2Collided()
{
    sf::FloatRect shape1 = player2->circle.getGlobalBounds();
	sf::FloatRect shape2 = ball->circle.getGlobalBounds();

	float dx = (player2->circle.getPosition().x + (shape1.width / 2)) - (ball->circle.getPosition().x + (shape2.width / 2));
	float dy = (player2->circle.getPosition().y + (shape1.height / 2)) - (ball->circle.getPosition().y + (shape2.height / 2));
	float distance = std::sqrt((dx * dx) + (dy * dy));

	if (distance <= (shape1.width / 2) + (shape2.width / 2))
	{
		return true;
	}
	
    return false;
}


bool ActualGame::canMove()
{
    if(didPlayersCollided() && (player1->circle.getPosition().y > player2->circle.getPosition().y))
        return false;

    return true;
}

bool ActualGame::canMove2()
{
    if(didPlayersCollided() && (player1->circle.getPosition().y < player2->circle.getPosition().y))
        return false;

    return true;
}

bool ActualGame::canMove3()
{
    if(didPlayersCollided() && (player1->circle.getPosition().x < player2->circle.getPosition().x))
        return false;

    return true;
}

bool ActualGame::canMove4()
{
    if(didPlayersCollided() && (player1->circle.getPosition().x > player2->circle.getPosition().x))
        return false;

    return true;
}

void ActualGame::setActualGame()
{
    ActualGame::gameBackground();
}

void ActualGame::ballUpdate()
{
    //ball->update(velocity);

    if(ball->left() < 5)
    {
        velocity.x = ballVelocity;
    }
    else if(ball->right() > WINDOW_WIDTH-5)
    {
        velocity.x = -ballVelocity;
    }
    else if(ball->top() < 5)
    {
        velocity.y = ballVelocity;
    }
    else if(ball->bottom() > WINDOW_HEIGHT-5)
    {
        velocity.y = -ballVelocity;
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