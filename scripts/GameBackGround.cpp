#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameBackGround.h"

using namespace sf;

void GameBackgroundClass:: drawGameBackground(Texture &gameBackground, RenderWindow &window){
    RectangleShape backgroundRect;
    backgroundRect.setSize(Vector2f (640, 480));
    backgroundRect.setPosition(0,0);
    backgroundRect.setTexture(&gameBackground);
    window.draw(backgroundRect);

}

