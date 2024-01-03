#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "scripts/Paddle.h"
#include "scripts/GameBackGround.h"
#include "scripts/Block.h"
#include "scripts/Ball.h"
#include "vector"
#include "scripts/Menu.h"
#include "scripts/Button.h"
#include "scripts/HoverAndClickMainMenuButtons.h"

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


    bool isUserInGame = false;
    bool isUserInMenu = true;
    bool newGameButtonIsHover = false;
    bool settingsButtonIsHover = false;
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
    Texture menuTexture;
    if ( menuTexture.loadFromFile("../images/title.png") == -1) {
        return 1;
    }

    Texture newGameButtonTexture;
    if ( newGameButtonTexture.loadFromFile("../images/button-start.png") == -1) {
        return 1;
    }
    Texture newGameButtonHoverTexture;
    if ( newGameButtonHoverTexture.loadFromFile("../images/button-start-hover.png") == -1) {
        return 1;
    }
    Texture settingsButtonTexture;
    if ( settingsButtonTexture.loadFromFile("../images/button-settings.png") == -1) {
        return 1;
    }
    Texture settingsButtonHoverTexture;
    if ( settingsButtonHoverTexture.loadFromFile("../images/button-settings-hover.png") == -1) {
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



    MenuClass menu;
    ButtonClass newGameButton;
    ButtonClass settingsButton;


    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        RectangleShape newGameButtonShape =  newGameButton.drawButton(newGameButtonTexture, 250);
        RectangleShape settingsButtonShape = settingsButton.drawButton(settingsButtonTexture, 320);
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == Event::Closed) {
                isUserInGame = false;
                window.close();
            }
            if(isUserInMenu && (event.type == Event::MouseMoved || (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left))){
                HoverAndClickMainMenuButtons(window,event,250,menuTexture,newGameButtonShape,newGameButtonHoverTexture,newGameButtonIsHover,settingsButtonShape);
                HoverAndClickMainMenuButtons(window,event,320,menuTexture,settingsButtonShape,settingsButtonHoverTexture,settingsButtonIsHover,newGameButtonShape);
            }

            if(isUserInGame){
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
        }




        if(isUserInGame ){
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

        if(isUserInMenu && !newGameButtonIsHover && !settingsButtonIsHover){
            window.clear();
            menu.drawMenu(menuTexture,window);
            window.draw(newGameButtonShape);
            window.draw(settingsButtonShape);
            window.display();
//
        }



    }

    return 0;
}


