#include <iostream>
#include "Game.h"

void Game::start()
{
    if(_gameState != Game::Uninitialized)
        return;

    _gameState = Game::Menu;
    running = true;

    window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Ice Hockey");
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(1920/2 - WINDOW_WIDTH/2 , 1080/2 - WINDOW_HEIGHT/2));

    if(_gameState == Game::Menu)
        MainMenu::setMenu();

    InfoScreen::setInfoScreen();
    ActualGame::setActualGame();

    while(running)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {   
            switch(event.type)
            {
                case sf::Event::Closed:
                    quit();
                    break;

                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Escape)
                    {
                        quit();
                    }
                    else if(event.key.code == sf::Keyboard::Up)
                    {   
                        if(_gameState == Game::Menu)
                            MainMenu::moveUp();
                    }
                    else if(event.key.code == sf::Keyboard::Down)
                    {
                        if(_gameState == Game::Menu)
                            MainMenu::moveDown();
                    }
                    else if(event.key.code == sf::Keyboard::Enter)
                    {
                        if(_gameState == Game::Menu)
                        {
                            switch(MainMenu::selectedItemIndex)
                            {
                                case 0:
                                    Game::addState("ActualGame", new ActualGame);
                                    Game::setCurrentState("ActualGame");
                                    _gameState = Game::Playing;
                                    break;
                                case 1:
                                    Game::addState("InfoScreen", new InfoScreen);
                                    Game::setCurrentState("InfoScreen");
                                    _gameState = Game::InfoPage;
                                    break;
                                case 2:
                                    quit();
                                    break;
                            }
                        }
                        else if(_gameState == Game::InfoPage)
                        {
                            Game::setCurrentState("MainMenu");
                            _gameState = Game::Menu;
                        }
                    }

                    break;
                
            }
        }
        window.clear(sf::Color::Black);
        window.draw(*m_currentState);
        window.display();
    }
}

void Game::addState(const std::string &name, State *state)
{
    m_states.emplace(name, std::unique_ptr<State>(state));
}

void Game::setCurrentState(const std::string &name)
{
    State * previous = m_currentState;
    m_currentState = m_states.at(name).get();
    m_currentState->setPrevious(previous);
}

void Game::quit()
{
    running = false;
}