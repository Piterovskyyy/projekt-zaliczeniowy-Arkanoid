#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "scripts/Paddle.h"
using namespace std;
using namespace sf;
int main() {
    RenderWindow window(VideoMode(640, 480), "Arkanoid");

    bool play = true;

    Event event;
    Texture gameBackground;
    if(gameBackground.loadFromFile("../images/spritessheet.png",  IntRect(0,33,800,450)) == -1){
        return 1;

    }
    Texture paddleTexture;
    if(paddleTexture.loadFromFile("../images/spritessheet.png",  IntRect(129,0,102,23)) == -1){
        return 1;

    }
    RectangleShape backgroundRect;
    backgroundRect.setSize(Vector2f (640, 480));
    backgroundRect.setPosition(0,0);
    backgroundRect.setTexture(&gameBackground);







    // run the program as long as the window is open
    while (play) {
        // check all the window's events that were triggered since the last iteration of the loop

        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == Event::Closed) {
                play = false;
                window.close();
            }

        }

        window.clear();
        window.draw(backgroundRect);
        PaddleClass paddle;
        window.draw(paddle.drawPaddle(paddleTexture));
        window.display();

    }

    return 0;
}


