#ifndef INFO_SCREEN_H
#define INFO_SCREEN_H

#include "State.h"
#include "DEFINITIONS.h"

class InfoScreen : public State
{
    public:
        static void setInfoScreen();
        
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        static void setFont(const char *name);
        static void infoScreenBackground();
        static void setMessage();
        static void setInfoMessage();
        static void setOptionText();
        static sf::RectangleShape lineMaker();
        
        inline static sf::Texture textureBackground;
        inline static sf::Sprite spriteBackground;
        inline static sf::Text option;
        inline static sf::Text message[NUMBER_OF_LINES];
        inline static sf::Font font;
        inline static sf::RectangleShape line = InfoScreen::lineMaker();
        inline static sf::Text infoMessage;
};

#endif