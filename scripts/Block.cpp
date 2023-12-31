#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Block.h"

using namespace sf;
using namespace std;

RectangleShape BlockClass::drawBlock() {
    RectangleShape blockRect;
    blockRect.setSize(Vector2f (64, 32));
    blockRect.setPosition((x*64)+64,(y*32)+32);
    blockRect.setTexture(&kind);
    return blockRect;
}
BlockClass::BlockClass(int setX ,int setY, Texture &setKind){
    x = setX;
    y = setY;
    kind = setKind;
}
