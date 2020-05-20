#include "GameOver.h"

void GameOver::setGameOverScreen()
{
    GameOver::gameOverBackground();
    GameOver::setFont("Sources/fonts/font.ttf");
    GameOver::setGameOverMessage();
    GameOver::setOptionText();
}

void GameOver::moveUp()
{
    if (GameOver::selectedItemIndex - 1 >= 0)
    {
        options[selectedItemIndex].setOutlineThickness(1);
        selectedItemIndex--;
        options[selectedItemIndex].setOutlineThickness(4);
    }
}

void GameOver::moveDown()
{
    if (GameOver::selectedItemIndex + 1 < NUMBER_OF_ITEMS_GAMEOVER)
    {
        options[selectedItemIndex].setOutlineThickness(1);
        selectedItemIndex++;
        options[selectedItemIndex].setOutlineThickness(4);
    }
}

void GameOver::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(spriteBackground);
    target.draw(gameOverMessage);
    target.draw(line);

    for (sf::Text& i : options)
    {
        target.draw(i);
    }
}

void GameOver::gameOverBackground()
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

void GameOver::setFont(const char *name)
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

sf::RectangleShape GameOver::lineMaker()
{
    sf::RectangleShape line(sf::Vector2f(350.f, 3.f));
    line.setPosition((WINDOW_WIDTH - line.getLocalBounds().width) / 2, 100);

    return line;
}

void GameOver::setGameOverMessage()
{
    gameOverMessage.setOutlineThickness(0.5);
    gameOverMessage.setOutlineColor(sf::Color::Black);
    gameOverMessage.setFont(font);
    gameOverMessage.setString("Game Over!");
    gameOverMessage.setCharacterSize(40);
    gameOverMessage.setOrigin(gameOverMessage.getLocalBounds().width / 2.0f, gameOverMessage.getLocalBounds().height / 2.0f);
    gameOverMessage.setPosition(WINDOW_WIDTH / 2, 50);
}

void GameOver::setOptionText()
{
    for (sf::Text& i : options)
    {
        i.setFont(font);
        i.setCharacterSize(50);
        i.setFillColor(sf::Color::White);
        i.setOutlineColor(sf::Color::Black);
    }

    options[0].setString("Play Again");
    sf::FloatRect textRect = options[0].getLocalBounds();
    options[0].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    options[0].setPosition(WINDOW_WIDTH / 2, 450);
    options[0].setOutlineThickness(4);

    options[1].setString("Quit");
    options[1].setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
    options[1].setPosition(WINDOW_WIDTH / 2, 550);
    options[1].setOutlineThickness(1);
}