#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;
void showRestartLevelButton(RenderWindow &window, Texture &buttonRestartTexture){
    RectangleShape buttonRestartRect;
    buttonRestartRect.setSize(Vector2f (50, 50));
    buttonRestartRect.setPosition(340,300);
    buttonRestartRect.setTexture(&buttonRestartTexture);
    window.draw(buttonRestartRect);
};
void hoverAndClickRestartLevelButton(RenderWindow &window, Event &event, bool &buttonRestartLevelIsHover){
    const int buttonYPosition = 300;
    const int buttonWidth = 50;
    const int buttonHeight = 50;
    if (Mouse::getPosition(window).x >= 340 && Mouse::getPosition(window).x <= 340 + buttonWidth &&
        Mouse::getPosition(window).y >= buttonYPosition &&
        Mouse::getPosition(window).y <= buttonYPosition + buttonHeight){
        buttonRestartLevelIsHover = true;
    }
    if(!(Mouse::getPosition(window).x >= 340 && Mouse::getPosition(window).x <= 340 + buttonWidth &&
         Mouse::getPosition(window).y >= buttonYPosition &&
         Mouse::getPosition(window).y <= buttonYPosition + buttonHeight)){
        buttonRestartLevelIsHover = false;
    }
}
