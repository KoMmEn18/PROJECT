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


    sf::Clock clock;
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

        sf::Time frameTime{ clock.restart() };
		float dt1{ frameTime.asSeconds() };
		float dt2{ frameTime.asSeconds() };
        sf::Vector2i movementControlplayer1;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			--movementControlplayer1.y;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			++movementControlplayer1.y;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			--movementControlplayer1.x;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			++movementControlplayer1.x;
		sf::Vector2f movement1(movementControlplayer1);
		if (movementControlplayer1.x != 0 && movementControlplayer1.y != 0)
		    movement1 *= 0.707f;
        ActualGame::player1move(movement1 * dt1);

        sf::Vector2i movementControlplayer2;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			--movementControlplayer2.y;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			++movementControlplayer2.y;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			--movementControlplayer2.x;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			++movementControlplayer2.x;
        sf::Vector2f movement2(movementControlplayer2);
        if (movementControlplayer2.x != 0 && movementControlplayer2.y != 0)
		    movement2 *= 0.707f;
        ActualGame::player2move(movement2 * dt2);

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