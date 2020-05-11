#include "ActualGame.h"
#include <iostream>

void ActualGame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    /*
    sf::CircleShape circle(30);
    circle.setPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
    circle.setFillColor(sf::Color::White);
    circle.setOrigin(30, 30);
    target.draw(circle);
    */
    target.draw(spriteBackground);
    target.draw(player1Sprite);
    target.draw(player2Sprite);
    target.draw(ballSprite);
}

int ActualGame::didCollided()
{
    if(player1Sprite.getGlobalBounds().intersects(player2Sprite.getGlobalBounds()))
    {
        std::cout << "idk" << std::endl;
        return 0;
    }
    
    return 1;
}

void ActualGame::setActualGame()
{
    ActualGame::gameBackground();
    ActualGame::playerSet();
    ActualGame::ballSet();
}

void ActualGame::ballUpdate()
{
    ballSprite.move(velocity);

    if(ActualGame::ballLeft() < 5)
    {
        velocity.x = ballVelocity;
    }
    else if(ActualGame::ballRight() > WINDOW_WIDTH-5)
    {
        velocity.x = -ballVelocity;
    }
    else if(ActualGame::ballTop() < 5)
    {
        velocity.y = ballVelocity;
    }
    else if(ActualGame::ballBottom() > WINDOW_HEIGHT-5)
    {
        velocity.y = -ballVelocity;
    }

}

void ActualGame::playerSet()
{
    player1Texture.loadFromFile("Sources/img/Red.png");
    player1Sprite.setTexture(player1Texture);
    player1Sprite.setPosition(WINDOW_WIDTH/2,40);
    player1Sprite.setOrigin(25, 25);

    player2Texture.loadFromFile("Sources/img/Yellow.png");
    player2Sprite.setTexture(player2Texture);
    player2Sprite.setPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT-40);
    player2Sprite.setOrigin(25, 25);
}

void ActualGame::ballSet()
{
    ballTexture.loadFromFile("Sources/img/Red.png");
    ballSprite.setTexture(ballTexture);
    ballSprite.setPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
    ballSprite.setOrigin(25, 25);
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

void ActualGame::player1move(sf::Vector2f howmany)
{
    player1Sprite.move(howmany * SPEED);
}

void ActualGame::player2move(sf::Vector2f howmany)
{
    player2Sprite.move(howmany * SPEED);
}

float ActualGame::ballLeft()
{
    return ballSprite.getPosition().x - 25.0;
}

float ActualGame::ballRight()
{
    return ballSprite.getPosition().x + 25.0;
}

float ActualGame::ballTop()
{
    return ballSprite.getPosition().y - 25.0;
}

float ActualGame::ballBottom()
{
    return ballSprite.getPosition().y + 25.0;
}