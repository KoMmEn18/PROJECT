#include "ActualGame.h"

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
}

void ActualGame::setActualGame()
{
    ActualGame::gameBackground();
    ActualGame::gamePlayerSet();
}

void ActualGame::gamePlayerSet()
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