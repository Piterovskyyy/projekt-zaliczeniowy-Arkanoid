#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Ball.h"

using namespace sf;

RectangleShape BallClass:: drawBall(Texture &ball){
    RectangleShape ballRect;
    ballRect.setSize(Vector2f (22, 22));
    // x = screen width/2 - ball size /2
    // y =screen height - ball size - paddle height
    ballRect.setPosition(320-11,480-22-23);
    ballRect.setTexture(&ball);
    return ballRect;
}




