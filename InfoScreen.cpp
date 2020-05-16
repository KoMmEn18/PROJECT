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
    if(!textureBackground.loadFromFile("Sources/img/menu.jpg", sf::IntRect(600, 200,1920,1080)))
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
    option.setCharacterSize(50);
    option.setFillColor(sf::Color::White);
    option.setOutlineColor(sf::Color::Black);
    sf::FloatRect textRect = option.getLocalBounds();
    option.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    option.setPosition(WINDOW_WIDTH/2, 650);
}

void InfoScreen::setFont(const char *name)
{
    if(!InfoScreen::font.loadFromFile(name))
    {
        exit(EXIT_FAILURE);
    }
}
