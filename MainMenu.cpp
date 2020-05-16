#include <iostream>
#include "MainMenu.h"

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(spriteBackground);
    target.draw(welcomeMessage);
    target.draw(line);

    for (int i = 0; i < NUMBER_OF_ITEMS_MENU; i++)
    {
        target.draw(options[i]);
    }
}

void MainMenu::setMenu()
{
    MainMenu::menuBackground();
    MainMenu::setFont("Sources/fonts/font.ttf");
    MainMenu::setWelcomeMessage();
    MainMenu::setOptionText();
}

void MainMenu::menuBackground()
{
    if (!textureBackground.loadFromFile("Sources/img/menu.jpg", sf::IntRect(600, 200, 1920, 1080)))
    {
        exit(EXIT_FAILURE);
    }
    textureBackground.setSmooth(true);

    spriteBackground.setTexture(textureBackground);
}

void MainMenu::setFont(const char *name)
{
    if (!font.loadFromFile(name))
    {
        exit(EXIT_FAILURE);
    }
}

void MainMenu::setWelcomeMessage()
{
    welcomeMessage.setOutlineThickness(0.5);
    welcomeMessage.setOutlineColor(sf::Color::Black);
    welcomeMessage.setFont(font);
    welcomeMessage.setString("Welcome to HockeyGame!");
    welcomeMessage.setCharacterSize(40);
    welcomeMessage.setOrigin(welcomeMessage.getLocalBounds().width / 2.0f, welcomeMessage.getLocalBounds().height / 2.0f);
    welcomeMessage.setPosition(WINDOW_WIDTH / 2, 50);
}

sf::RectangleShape MainMenu::lineMaker()
{
    sf::RectangleShape line(sf::Vector2f(350.f, 3.f));
    line.setPosition((WINDOW_WIDTH - line.getLocalBounds().width) / 2, 100);

    return line;
}

void MainMenu::setOptionText()
{

    for (int i = 0; i < NUMBER_OF_ITEMS_MENU; i++)
    {
        options[i].setFont(font);
        options[i].setCharacterSize(50);
        options[i].setFillColor(sf::Color::White);
        options[i].setOutlineColor(sf::Color::Black);
    }

    options[0].setString("Play");
    sf::FloatRect textRect = options[0].getLocalBounds();
    options[0].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    options[0].setPosition(WINDOW_WIDTH / 2, 450);
    options[0].setOutlineThickness(4);

    options[1].setString("Info");
    options[1].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    options[1].setPosition(WINDOW_WIDTH / 2, 550);
    options[1].setOutlineThickness(1);

    options[2].setString("Exit");
    options[2].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    options[2].setPosition(WINDOW_WIDTH / 2, 650);
    options[2].setOutlineThickness(1);
}

void MainMenu::moveUp()
{
    if (MainMenu::selectedItemIndex - 1 >= 0)
    {
        options[selectedItemIndex].setOutlineThickness(1);
        selectedItemIndex--;
        options[selectedItemIndex].setOutlineThickness(4);
    }
}

void MainMenu::moveDown()
{
    if (MainMenu::selectedItemIndex + 1 < NUMBER_OF_ITEMS_MENU)
    {
        options[selectedItemIndex].setOutlineThickness(1);
        selectedItemIndex++;
        options[selectedItemIndex].setOutlineThickness(4);
    }
}