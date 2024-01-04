#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "LevelSelect.h"

using namespace sf;

void LevelSelectClass::drawLevelSelect(sf::Texture &levelSelectTexture, sf::RenderWindow &window,Texture &levelButtonTexture) {
    RectangleShape levelSelectRect;
    levelSelectRect.setSize(Vector2f (640, 480));
    levelSelectRect.setPosition(0,0);
    levelSelectRect.setTexture(&levelSelectTexture);
    RectangleShape levelButtonRect;
    levelButtonRect.setSize(Vector2f(50,50));
    levelButtonRect.setPosition(130,130);
    levelButtonRect.setTexture(&levelButtonTexture);
    Font font;
    font.loadFromFile("../fonts/RubikDoodleShadow-Regular.ttf");
    Text levelNumber;
    levelNumber.setFont(font);
    levelNumber.setCharacterSize(32);
    levelNumber.setStyle(Text::Bold);
    levelNumber.setFillColor(Color::Black);
    levelNumber.setString("1");
    levelNumber.setPosition(145,133);
    window.draw(levelSelectRect);
    window.draw(levelButtonRect);
    window.draw(levelNumber);
    levelButtonRect.setPosition(200,130);
    Color gray(105,105,105);
    levelButtonRect.setFillColor(gray);
    levelNumber.setString("2");
    levelNumber.setPosition(215,133);
    window.draw(levelButtonRect);
    window.draw(levelNumber);

}

