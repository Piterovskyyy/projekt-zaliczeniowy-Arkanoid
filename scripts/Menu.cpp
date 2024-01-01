#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Menu.h"

using namespace sf;

void MenuClass:: drawMenu(Texture &menu, RenderWindow &window){
    RectangleShape menuRect;
    menuRect.setSize(Vector2f (640, 480));
    menuRect.setPosition(0,0);
    menuRect.setTexture(&menu);
    window.draw(menuRect);
    Texture titleTexture;
    titleTexture.loadFromFile("../images/Arkanoid.png");
    RectangleShape titleRect;
    titleRect.setSize(Vector2f(300,109));
    titleRect.setPosition(320-150,50);
    titleRect.setTexture(&titleTexture);
    titleRect.setFillColor(Color::Green);
    window.draw(titleRect);
}

