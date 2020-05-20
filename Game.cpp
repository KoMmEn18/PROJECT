#include <iostream>
#include "Game.h"

void Game::start()
{
    if(_gameState != Game::Uninitialized)
        return;

    _gameState = Game::Menu;
    running = true;

    window.create(sf::VideoMode(WINDOW_WIDTH,WINDOW_HEIGHT), "Hockey Game");
    window.setFramerateLimit(60);
    window.setPosition(sf::Vector2i(1920/2 - WINDOW_WIDTH/2 , 1080/2 - WINDOW_HEIGHT/2));

    if(_gameState == Game::Menu)
        MainMenu::setMenu();
    
    InfoScreen::setInfoScreen();
    ActualGame::setActualGame();
    GameOver::setGameOverScreen();

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
                        if(_gameState == Game::Menu)
                            quit();
                    }
                    else if(event.key.code == sf::Keyboard::Up)
                    {   
                        if(_gameState == Game::Menu)
                            MainMenu::moveUp();
                        else if(_gameState == Game::OverPage)
                            GameOver::moveUp();
                    }
                    else if(event.key.code == sf::Keyboard::Down)
                    {
                        if(_gameState == Game::Menu)
                            MainMenu::moveDown();
                        else if(_gameState == Game::OverPage)
                            GameOver::moveDown();
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
                        else if(_gameState == Game::OverPage)
                        {
                            switch(GameOver::selectedItemIndex)
                            {
                                case 0:
                                    ActualGame::setStartSetup();
                                    Game::setCurrentState("ActualGame");
                                    _gameState = Game::Playing;
                                    break;
                                case 1:
                                    quit();
                                    break;
                            }
                        }
                    }
                    break;
            }
        }

        if(_gameState == Game::Playing)
        {
            ActualGame::playerUpdate();
            ActualGame::ballUpdate();
            if((ActualGame::getPlayer1Score() == 5 || ActualGame::getPlayer2Score() == 5) && ActualGame::canOpenGameOverPage)
            {
                Game::addState("GameOver", new GameOver);
                Game::setCurrentState("GameOver");
                _gameState = Game::OverPage;
                ActualGame::canOpenGameOverPage = false;
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