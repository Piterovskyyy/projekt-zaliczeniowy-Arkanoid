#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;
void HoverAndClickSettingsButtons(RenderWindow &window, Event &event, bool &isLeaveButtonHover, bool &isMusicToggleButtonHover){
    const int buttonWidth = 50;
    const int buttonHeight = 50;
    //320-25= 295 leave button position x
    //250 leave button position y
    if (Mouse::getPosition(window).x >= 295 &&
        Mouse::getPosition(window).x <= 295 + buttonWidth && Mouse::getPosition(window).y >= 250 &&
        Mouse::getPosition(window).y <= 250 + buttonHeight){
        isLeaveButtonHover = true;
    }else{
        isLeaveButtonHover = false;
    }
    //320-25-20-50 = 225 button music x position
    if (Mouse::getPosition(window).x >= 225 &&
        Mouse::getPosition(window).x <= 225 + buttonWidth && Mouse::getPosition(window).y >= 100 &&
        Mouse::getPosition(window).y <= 100 + buttonHeight){
        isMusicToggleButtonHover = true;
    }else{
        isMusicToggleButtonHover = false;
    }





}