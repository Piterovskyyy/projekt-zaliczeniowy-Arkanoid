#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Block.h"

using namespace sf;

void BlockClass::drawBlock(int x, int y, Texture &BlockShape, RenderWindow &window) {
    RectangleShape blockRect;
    blockRect.setSize(Vector2f (64, 32));
    blockRect.setPosition((x*64)+64,(y*32)+32);
    blockRect.setTexture(&BlockShape);
    window.draw(blockRect);
}

