#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "scripts/Paddle.h"
#include "scripts/GameBackGround.h"
using namespace std;
using namespace sf;
int main() {
    RenderWindow window(VideoMode(640, 480), "Arkanoid");

    bool play = true;

    Event event;
    Texture gameBackgroundTexture;
    if(gameBackgroundTexture.loadFromFile("../images/spritessheet.png",  IntRect(0,33,800,450)) == -1){
        return 1;

    }
    Texture paddleTexture;
    if(paddleTexture.loadFromFile("../images/spritessheet.png",  IntRect(129,0,102,23)) == -1){
        return 1;

    }






    PaddleClass paddle;
    RectangleShape player = paddle.drawPaddle(paddleTexture);
    GameBackgroundClass background;

    // run the program as long as the window is open
    while (play) {
        // check all the window's events that were triggered since the last iteration of the loop

        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == Event::Closed) {
                play = false;
                window.close();
            }
            if(event.type == Event::KeyPressed && (event.key.code == Keyboard::D ||  event.key.code == Keyboard::Right) && player.getPosition().x + player.getSize().x <= window.getSize().x ){
                player.move(10,0);
            }
            if(event.type == Event::KeyPressed && (event.key.code == Keyboard::A  ||  event.key.code == Keyboard::Left) && player.getPosition().x >= 0){
                player.move(-10,0);
            }
        }

        window.clear();
        window.draw(background.drawGameBackground(gameBackgroundTexture));
        window.draw(player);
        window.display();

    }

    return 0;
}


