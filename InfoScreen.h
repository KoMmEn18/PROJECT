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
        static void setOptionText();
        inline static sf::Texture textureBackground;
        inline static sf::Sprite spriteBackground;
        inline static sf::Text option;
        inline static sf::Font font;
};

#endif