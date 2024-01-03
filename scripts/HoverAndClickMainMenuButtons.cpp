#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "HoverAndClickMainMenuButtons.h"
#include <iostream>
#include "Menu.h"
using namespace sf;
using namespace std;
void HoverAndClickMainMenuButtons(RenderWindow &window, Event &event,int y,Texture &menuTexture, RectangleShape &buttonShape,Texture &buttonHoverTexture, bool &buttonIsHover,RectangleShape &secendButtonShape){
    const int buttonXPosition =  320-62;
    const int buttonWidth = 124;
    const int buttonHeight = 60;
    MenuClass menu;
    if(Mouse::getPosition(window).x >= buttonXPosition && Mouse::getPosition(window).x <= buttonXPosition + buttonWidth && Mouse::getPosition(window).y>=y && Mouse::getPosition(window).y<=y+buttonHeight){

        buttonShape.setTexture(&buttonHoverTexture);
        buttonIsHover = true;
        window.clear();
        menu.drawMenu(menuTexture,window);
        window.draw(buttonShape);
        window.draw(secendButtonShape);
        window.display();
        if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left){
            cout<<"123" <<endl;
        }

    }
    if(!(Mouse::getPosition(window).x >= buttonXPosition && Mouse::getPosition(window).x <= buttonXPosition + buttonWidth && Mouse::getPosition(window).y>=y && Mouse::getPosition(window).y<=y+buttonHeight)){
        buttonIsHover = false;

    }


}