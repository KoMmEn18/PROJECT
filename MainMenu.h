#ifndef MAIN_MENU_H
#define MAIN_MENU_H

#include "State.h"
#include "DEFINITIONS.h"

class MainMenu : public State
{
    public:
        static void setMenu();
        static void moveUp();
        static void moveDown();
        inline static int selectedItemIndex;

    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        static void menuBackground();
        static void setFont(const char *name);
        static void setWelcomeMessage();
        static sf::RectangleShape lineMaker();
        static void setOptionText();

    protected:
        inline static sf::RectangleShape line = MainMenu::lineMaker();
        inline static sf::Texture textureBackground;
        inline static sf::Sprite spriteBackground;
        inline static sf::Font font;
        inline static sf::Text welcomeMessage;
        inline static sf::Text options[NUMBER_OF_ITEMS_MENU];
};

#endif