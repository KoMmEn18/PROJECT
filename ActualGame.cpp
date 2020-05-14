#include "ActualGame.h"
#include <iostream>
#include <cmath>

void ActualGame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(spriteBackground);
    target.draw(*ball);
    target.draw(*player1);
    target.draw(*player2);
    if(didCollided(player1, ball))
    {
        printf("ta no\n");
    }
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
    sf::FloatRect shape1 = first->circle.getGlobalBounds();
	sf::FloatRect shape2 = second->circle.getGlobalBounds();

	float dx = (first->circle.getPosition().x) - (second->circle.getPosition().x);
	float dy = (first->circle.getPosition().y) - (second->circle.getPosition().y);
	float distance = std::sqrt((dx * dx) + (dy * dy));

	if (distance < first->circle.getRadius() + second->circle.getRadius())
	{
		return true;
	}
	
    return false;
}

bool ActualGame::canMove(Ball* first, Ball* second)
{
    if(didCollided(first, second) && (first->circle.getPosition().y > second->circle.getPosition().y))
        return false;

    return true;
}

bool ActualGame::canMove2(Ball* first, Ball* second)
{
    if(didCollided(first, second) && (first->circle.getPosition().y < second->circle.getPosition().y))
        return false;

    return true;
}

bool ActualGame::canMove3(Ball* first, Ball* second)
{
    if(didCollided(first, second) && (first->circle.getPosition().x < second->circle.getPosition().x))
        return false;

    return true;
}

bool ActualGame::canMove4(Ball* first, Ball* second)
{
    if(didCollided(first, second) && (first->circle.getPosition().x > second->circle.getPosition().x))
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