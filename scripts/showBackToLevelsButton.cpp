#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;
void showBackToLevelsButton(RenderWindow &window, Texture &buttonTexture){
    RectangleShape buttonBackToLevelsRect;
    buttonBackToLevelsRect.setSize(Vector2f (50, 50));
    buttonBackToLevelsRect.setPosition(250,300);
    buttonBackToLevelsRect.setTexture(&buttonTexture);
    window.draw(buttonBackToLevelsRect);

};
void hoverAndClickBackToLevelsButton(RenderWindow &window, Event &event, bool &buttonBackToLevelsIsHover){
    const int buttonYPosition = 300;
    const int buttonWidth = 50;
    const int buttonHeight = 50;
    if (Mouse::getPosition(window).x >= 250 && Mouse::getPosition(window).x <= 250 + buttonWidth &&
        Mouse::getPosition(window).y >= buttonYPosition &&
        Mouse::getPosition(window).y <= buttonYPosition + buttonHeight){
        buttonBackToLevelsIsHover = true;
    }
    if(!(Mouse::getPosition(window).x >= 250 && Mouse::getPosition(window).x <= 250 + buttonWidth &&
         Mouse::getPosition(window).y >= buttonYPosition &&
         Mouse::getPosition(window).y <= buttonYPosition + buttonHeight)){
        buttonBackToLevelsIsHover = false;
    }
}