#include <iostream>
#include "Game.h"

int main()
{
    Game::addState("MainMenu", new MainMenu);
    Game::setCurrentState("MainMenu");

    Game::start();
    return EXIT_SUCCESS;
}