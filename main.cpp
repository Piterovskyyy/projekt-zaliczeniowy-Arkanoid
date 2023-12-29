#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "scripts/Paddle.h"
#include "scripts/GameBackGround.h"
#include "scripts/Block.h"
#include "vector"
using namespace std;
using namespace sf;
int main() {
    RenderWindow window(VideoMode(640, 480), "Arkanoid");

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
    if(gameBackgroundTexture.loadFromFile("../images/spritessheet.png",  IntRect(0,33,800,450)) == -1){
        return 1;

    }
    Texture paddleTexture;
    if(paddleTexture.loadFromFile("../images/spritessheet.png",  IntRect(129,0,102,23)) == -1){
        return 1;

    }
    Texture blockTexture;
    if(blockTexture.loadFromFile("../images/spritessheet.png",  IntRect(0,0,64,32)) == -1){
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
        BlockClass Block;
        window.clear();
        background.drawGameBackground(gameBackgroundTexture,window);
        window.draw(player);
        for(int i = 0; i < gameLevels[0].size();i++){
            Block.drawBlock(gameLevels[0][i].x,gameLevels[0][i].y,blockTexture,window);
        };

        window.display();

    }

    return 0;
}


