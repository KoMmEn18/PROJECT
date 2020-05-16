#ifndef GAME_OVER
#define GAME_OVER

#include "State.h"
#include "DEFINITIONS.h"

class GameOver : public State
{
    public:
        static void setGameOverScreen();
        inline static int selectedItemIndex = 0;
        static void moveUp();
        static void moveDown();

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        static void gameOverBackground();
        static void setFont(const char *name);
        static sf::RectangleShape lineMaker();
        static void setGameOverMessage();
        static void setOptionText();

        inline static sf::Texture textureBackground;
        inline static sf::Sprite spriteBackground;
        inline static sf::Font font;
        inline static sf::Text gameOverMessage;

        inline static sf::Text options[NUMBER_OF_ITEMS_GAMEOVER];

        inline static sf::RectangleShape line = GameOver::lineMaker();
};

#endif