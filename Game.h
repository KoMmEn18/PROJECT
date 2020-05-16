#ifndef MENU_H
#define MENU_H

#include "MainMenu.h"
#include "InfoScreen.h"
#include "ActualGame.h"
#include "GameOver.h"

class Game : public State
{
    public:
        static void start();
        static void addState(const std::string & name, State * state);
        static void setCurrentState(const std::string & name);
        static void quit();

    private:
        enum GameState
        {
            Uninitialized,
            Menu,
            InfoPage,
            Playing,
            OverPage
        };

    inline static GameState _gameState = Uninitialized;
    inline static std::map<std::string, std::unique_ptr<State>> m_states;
    inline static State *m_currentState = nullptr;
    inline static bool running = false;
    inline static sf::RenderWindow window;
};
#endif