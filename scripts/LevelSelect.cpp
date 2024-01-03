#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "LevelSelect.h"

using namespace sf;

void LevelSelectClass::drawLevelSelect(sf::Texture &levelSelectTexture, sf::RenderWindow &window) {
    RectangleShape levelSelectRect;
    levelSelectRect.setSize(Vector2f (640, 480));
    levelSelectRect.setPosition(0,0);
    levelSelectRect.setTexture(&levelSelectTexture);
    window.draw(levelSelectRect);
}

