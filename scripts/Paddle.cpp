#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Paddle.h"

using namespace sf;

RectangleShape PaddleClass:: drawPaddle(Texture &paddle){
    RectangleShape paddleRect;
    paddleRect.setSize(Vector2f (102, 23));
    paddleRect.setPosition(320-51,480-23);
    paddleRect.setTexture(&paddle);
    return paddleRect;
}



