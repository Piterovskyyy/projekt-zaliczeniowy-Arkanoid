#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameBackGround.h"

using namespace sf;

RectangleShape GameBackgroundClass:: drawGameBackground(Texture &gameBackground){
    RectangleShape backgroundRect;
    backgroundRect.setSize(Vector2f (640, 480));
    backgroundRect.setPosition(0,0);
    backgroundRect.setTexture(&gameBackground);
    return backgroundRect;
}

