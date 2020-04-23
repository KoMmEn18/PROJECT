#include "ActualGame.h"

void ActualGame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(spriteBackground);
    target.draw(ball);
}

void ActualGame::setActualGame()
{
    ActualGame::gameBackground();
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

sf::CircleShape ActualGame::ballMaker()
{
    sf::CircleShape ball(30.f);
    ball.setPosition(WINDOW_WIDTH/2,WINDOW_HEIGHT/2);
    ball.setFillColor(sf::Color::Magenta);
    ball.setOrigin(30, 30);

    return ball;
}