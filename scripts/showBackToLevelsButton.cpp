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
void hoverAndClickBackToLevelsButton(RenderWindow &window, Event &event, bool &buttonBackToLevelsIsHover, bool &isUserInLevelSelect, bool &isUserInGame){
    const int buttonYPosition = 300;
    const int buttonWidth = 50;
    const int buttonHeight = 50;
    if (Mouse::getPosition(window).x >= 250 && Mouse::getPosition(window).x <= 250 + buttonWidth &&
        Mouse::getPosition(window).y >= buttonYPosition &&
        Mouse::getPosition(window).y <= buttonYPosition + buttonHeight){
        buttonBackToLevelsIsHover = true;
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
            isUserInLevelSelect = true;
            isUserInGame = false;
            Mouse::setPosition(Vector2i(Mouse::getPosition(window).x,Mouse::getPosition(window).y),window);
            buttonBackToLevelsIsHover = false;
        }
    }
    if(!(Mouse::getPosition(window).x >= 250 && Mouse::getPosition(window).x <= 250 + buttonWidth &&
         Mouse::getPosition(window).y >= buttonYPosition &&
         Mouse::getPosition(window).y <= buttonYPosition + buttonHeight)){
        buttonBackToLevelsIsHover = false;
    }
}