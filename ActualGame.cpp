#include "ActualGame.h"


void ActualGame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(spriteBackground);
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