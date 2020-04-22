#include "InfoScreen.h"

void InfoScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(spriteBackground);
    target.draw(option);
}

void InfoScreen::setInfoScreen()
{
    InfoScreen::infoScreenBackground();
    InfoScreen::setFont("Sources/fonts/font.ttf");
    InfoScreen::setOptionText();
}

void InfoScreen::infoScreenBackground()
{
    if(!textureBackground.loadFromFile("Sources/img/info.jpg", sf::IntRect(600, 200,1920,1080)))
    {
        exit(EXIT_FAILURE);
    }
    textureBackground.setSmooth(true);

    spriteBackground.setTexture(textureBackground);
}

void InfoScreen::setOptionText()
{
    option.setString("Back");
    option.setOutlineThickness(4);
    option.setFont(font);
    option.setCharacterSize(40);
    option.setFillColor(sf::Color::White);
    option.setOutlineColor(sf::Color::Black);
    option.setOrigin(279.5, 20.5);
    option.setPosition(WINDOW_WIDTH/2, 480);
}

void InfoScreen::setFont(const char *name)
{
    if(!InfoScreen::font.loadFromFile(name))
    {
        exit(EXIT_FAILURE);
    }
}
