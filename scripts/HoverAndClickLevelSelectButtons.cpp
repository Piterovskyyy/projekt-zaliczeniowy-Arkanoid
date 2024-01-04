#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "HoverAndClickMainMenuButtons.h"
#include <iostream>
#include "Menu.h"

using namespace sf;
using namespace std;

void HoverAndClickLevelSelectButtons(RenderWindow &window, Event &event, int x, bool &LevelSelectButtonIsHover, string levelNumberString) {
    const int buttonYPosition = 130;
    const int buttonWidth = 50;
    const int buttonHeight = 50;
    if (Mouse::getPosition(window).x >= x && Mouse::getPosition(window).x <= x + buttonWidth &&
        Mouse::getPosition(window).y >= buttonYPosition &&
        Mouse::getPosition(window).y <= buttonYPosition + buttonHeight) {
        LevelSelectButtonIsHover = true;
        Texture ButtonHoverTexture;
        ButtonHoverTexture.loadFromFile("../images/leveliconhover.png");
        RectangleShape levelButtonHoverRect;
        levelButtonHoverRect.setSize(Vector2f(50,50));
        levelButtonHoverRect.setPosition(x,130);
        levelButtonHoverRect.setTexture(&ButtonHoverTexture);
        Font font;
        font.loadFromFile("../fonts/RubikDoodleShadow-Regular.ttf");
        Text levelNumber;
        levelNumber.setFont(font);
        levelNumber.setCharacterSize(32);
        levelNumber.setStyle(Text::Bold);
        levelNumber.setFillColor(Color::Black);
        levelNumber.setString(levelNumberString);
        levelNumber.setPosition(x+15,133);
        window.draw(levelButtonHoverRect);
        window.draw(levelNumber);
        window.display();

    }

    if (!(Mouse::getPosition(window).x >= x && Mouse::getPosition(window).x <= x + buttonWidth &&
          Mouse::getPosition(window).y >= buttonYPosition &&
          Mouse::getPosition(window).y <= buttonYPosition + buttonHeight)) {
        LevelSelectButtonIsHover = false;
    }


}
