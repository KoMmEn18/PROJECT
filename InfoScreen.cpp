#include "InfoScreen.h"

void InfoScreen::setInfoScreen()
{
    InfoScreen::infoScreenBackground();
    InfoScreen::setFont("Sources/fonts/font.ttf");
    InfoScreen::setOptionText();
    InfoScreen::setMessage();
    InfoScreen::setInfoMessage();
}

void InfoScreen::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(spriteBackground);
    target.draw(option);
    target.draw(line);
    target.draw(infoMessage);
    for(int i = 0; i < NUMBER_OF_LINES ; i++)
    {
        target.draw(message[i]);
    }
    
}

void InfoScreen::setFont(const char *name)
{
   try
    {
        if (!font.loadFromFile(name))
        {
            throw "Font loading failed!";
        }
    }
    catch(...)
    {
        perror("Font loading failed!");
        exit(EXIT_FAILURE);
    }
}

void InfoScreen::infoScreenBackground()
{
    try
    {
        if(!textureBackground.loadFromFile("Sources/img/menu.jpg", sf::IntRect(600, 200,1920,1080)))
        {
            throw "Texture background loading failed!";
        }
    }
    catch(...)
    {
        perror("Texture background loading failed!");
        exit(EXIT_FAILURE);
    }
    
    textureBackground.setSmooth(true);

    spriteBackground.setTexture(textureBackground);
}

void InfoScreen::setMessage()
{
    message[0].setString("Hockey Game jest kopia popularnej");
    sf::FloatRect textRect = message[0].getLocalBounds();
    message[0].setPosition(25, 150);

    for(int i = 0; i < NUMBER_OF_LINES ; i++)
    {
        message[i].setOutlineThickness(0.5);
        message[i].setOutlineColor(sf::Color::Black);
        message[i].setFont(font);
        message[i].setCharacterSize(30);
        message[i].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    }


    message[1].setString("gry na telefon w ktorej zadaniem");
    message[1].setPosition(25, 200);

    message[2].setString("gracza jest strzelanie bramek.");
    message[2].setPosition(25, 250);

    message[3].setString("Jest to gra dla dwoch graczy.");
    message[3].setPosition(25, 300);

    message[4].setString("Gracz nr.1 porusza sie strzalkami, ");
    message[4].setPosition(25, 350);

    message[5].setString("natomiast gracz nr.2 WSAD'em.");
    message[5].setPosition(25, 400);

    message[6].setString("Rozgrywka trwa do 5 strzelonych");
    message[6].setPosition(25, 450);

    message[7].setString("bramek. Udanej rozgrywki! :)");
    message[7].setPosition(25, 500);
}

void InfoScreen::setInfoMessage()
{
    infoMessage.setOutlineThickness(0.5);
    infoMessage.setOutlineColor(sf::Color::Black);
    infoMessage.setFont(font);
    infoMessage.setString("Info");
    infoMessage.setCharacterSize(40);
    infoMessage.setOrigin(infoMessage.getLocalBounds().width / 2.0f, infoMessage.getLocalBounds().height / 2.0f);
    infoMessage.setPosition(WINDOW_WIDTH / 2, 50);
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

sf::RectangleShape InfoScreen::lineMaker()
{
    sf::RectangleShape line(sf::Vector2f(350.f, 3.f));
    line.setPosition((WINDOW_WIDTH - line.getLocalBounds().width) / 2, 100);

    return line;
}