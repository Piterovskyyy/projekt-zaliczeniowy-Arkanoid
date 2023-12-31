#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "scripts/Paddle.h"
#include "scripts/GameBackGround.h"
#include "scripts/Block.h"
#include "scripts/Ball.h"
#include "vector"

using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(640, 480), "Arkanoid");
    window.setFramerateLimit(60);

    struct BoardItem {
        int x;
        int y;
        int kind;
    };

    vector<vector<BoardItem>> gameLevels = {
            {
                    {0, 0, 0},
                    {1, 0, 0},
                    {2, 0, 0},
                    {3, 0, 0},
                    {4, 0, 0},
                    {5, 0, 0},
                    {6, 0, 0},
                    {7, 0, 0},
                    {0, 1, 0},
                    {1, 1, 0},
                    {2, 1, 0},
                    {3, 1, 0},
                    {4, 1, 0},
                    {5, 1, 0},
                    {6, 1, 0},
                    {7, 1, 0}
            },
            {
                    {0, 0, 1},
                    {1, 0, 0},
                    {3, 0, 1},
                    {4, 0, 0},
                    {6, 0, 1},
                    {7, 0, 0},
                    {1, 1, 1},
                    {2, 1, 0},
                    {4, 1, 1},
                    {5, 1, 0},
                    {7, 1, 1}
            }
    };


    bool play = true;

    Event event;
    Texture gameBackgroundTexture;
    if (gameBackgroundTexture.loadFromFile("../images/spritessheet.png", IntRect(0, 33, 800, 450)) == -1) {
        return 1;

    }
    Texture paddleTexture;
    if (paddleTexture.loadFromFile("../images/spritessheet.png", IntRect(129, 0, 102, 23)) == -1) {
        return 1;

    }

    Texture ballTexture;
    if (ballTexture.loadFromFile("../images/spritessheet.png", IntRect(232, 0, 22, 22)) == -1) {
        return 1;

    }
    Texture blockTexture;
    if ( blockTexture.loadFromFile("../images/spritessheet.png", IntRect(0, 0, 64, 32)) == -1) {
        return 1;

    }


    PaddleClass paddle;
    RectangleShape player = paddle.drawPaddle(paddleTexture);
    GameBackgroundClass background;
    BallClass ballRect;
    RectangleShape ball = ballRect.drawBall(ballTexture);
    int xValocityBall = -4;
    int yValocityBall = -4;

    vector<BlockClass>blocks;
    for (int i = 0; i < gameLevels[0].size(); i++) {
        BlockClass Block(gameLevels[0][i].x,gameLevels[0][i].y, blockTexture);
        blocks.push_back(Block);
    };

    // run the program as long as the window is open
    while (play) {
        // check all the window's events that were triggered since the last iteration of the loop

        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == Event::Closed) {
                play = false;
                window.close();
            }
            if (event.type == Event::KeyPressed &&
                (event.key.code == Keyboard::D || event.key.code == Keyboard::Right) &&
                player.getPosition().x + player.getSize().x <= window.getSize().x) {
                player.move(10, 0);
            }
            if (event.type == Event::KeyPressed &&
                (event.key.code == Keyboard::A || event.key.code == Keyboard::Left) && player.getPosition().x >= 0) {
                player.move(-10, 0);
            }
        }
        ball.move(xValocityBall, yValocityBall);
        if (ball.getPosition().x < 0 || ball.getPosition().x > window.getSize().x) {
            xValocityBall = -xValocityBall;
        }
        if (ball.getPosition().y < 0) {
            yValocityBall = -yValocityBall;
        }
        if(ball.getGlobalBounds().intersects(player.getGlobalBounds()) == true){
            yValocityBall = -yValocityBall;
        }
        for(int i = 0; i < blocks.size();i++){
            if(ball.getGlobalBounds().intersects(blocks[i].drawBlock().getGlobalBounds()) == true){
                yValocityBall = -yValocityBall;
                blocks.erase(blocks.begin()+i);
            }
        }

        window.clear();
        background.drawGameBackground(gameBackgroundTexture, window);
        window.draw(player);
        window.draw(ball);
        for(int i = 0; i < blocks.size();i++){
            window.draw(blocks[i].drawBlock());
        }


        window.display();


    }

    return 0;
}


