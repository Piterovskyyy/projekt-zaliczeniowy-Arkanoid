#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Button.h"

using namespace sf;

RectangleShape ButtonClass:: drawButton(Texture &button ,int y){
    RectangleShape buttonRect;
    buttonRect.setSize(Vector2f (124, 60));
    //x = window size /2 - button size / 2
    buttonRect.setPosition(320-62,y);
    buttonRect.setTexture(&button);

    return buttonRect;
}


