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
#include "scripts/LevelSelect.h"
#include "scripts/HoverAndClickLevelSelectButtons.h"
#include "scripts/showResultScreen.h"
#include "scripts/showBackToLevelsButton.h"
#include "scripts/showRestartLevelButton.h"

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

    bool isUserInMenu = true;
    bool isUserInLevelSelect = false;
    bool isUserInSettings = false;
    bool isUserInGame = false;


    bool newGameButtonIsHover = false;
    bool settingsButtonIsHover = false;
    bool level1SelectButtonIsHover = false;
    bool level2SelectButtonIsHover = false;
    bool buttonBackToLevelsIsHover = false;
    bool buttonRestartLevelIsHover = false;
    int numberOfCompletedLevels = 0;
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
    if (blockTexture.loadFromFile("../images/spritessheet.png", IntRect(0, 0, 64, 32)) == -1) {
        return 1;

    }
    Texture menuTexture;
    if (menuTexture.loadFromFile("../images/title.png") == -1) {
        return 1;
    }
    Texture levelSelectTexture;
    if (levelSelectTexture.loadFromFile("../images/levelselectscreen.png") == -1) {
        return 1;
    }

    Texture newGameButtonTexture;
    if (newGameButtonTexture.loadFromFile("../images/button-start.png") == -1) {
        return 1;
    }
    Texture newGameButtonHoverTexture;
    if (newGameButtonHoverTexture.loadFromFile("../images/button-start-hover.png") == -1) {
        return 1;
    }
    Texture settingsButtonTexture;
    if (settingsButtonTexture.loadFromFile("../images/button-settings.png") == -1) {
        return 1;
    }
    Texture settingsButtonHoverTexture;
    if (settingsButtonHoverTexture.loadFromFile("../images/button-settings-hover.png") == -1) {
        return 1;
    }
    Texture levelButtonTexture;
    if (levelButtonTexture.loadFromFile("../images/levelicon.png") == -1) {
        return 1;
    }


    PaddleClass paddle;
    RectangleShape player = paddle.drawPaddle(paddleTexture);
    GameBackgroundClass background;
    BallClass ballRect;
    RectangleShape ball = ballRect.drawBall(ballTexture);
    int xValocityBall = -4;
    int yValocityBall = -4;


    vector<BlockClass> blocks;

    int selectedLevel = 0;
    bool createBorad = true;
    int numberOfBlocks;
    bool userLost = false;
    MenuClass menu;
    ButtonClass newGameButton;
    ButtonClass settingsButton;
    LevelSelectClass levelSelect;


    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        RectangleShape newGameButtonShape = newGameButton.drawButton(newGameButtonTexture, 250);
        RectangleShape settingsButtonShape = settingsButton.drawButton(settingsButtonTexture, 320);
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == Event::Closed) {
                window.close();
            }
            if (isUserInMenu && !isUserInLevelSelect && (event.type == Event::MouseMoved ||
                                                         (event.type == Event::MouseButtonPressed &&
                                                          event.mouseButton.button == Mouse::Left))) {
                HoverAndClickMainMenuButtons(window, event, 250, menuTexture, newGameButtonShape,
                                             newGameButtonHoverTexture, newGameButtonIsHover, settingsButtonShape,
                                             isUserInLevelSelect);
                HoverAndClickMainMenuButtons(window, event, 320, menuTexture, settingsButtonShape,
                                             settingsButtonHoverTexture, settingsButtonIsHover, newGameButtonShape,
                                             isUserInSettings);
            }

            if (isUserInLevelSelect && !isUserInGame && (event.type == Event::MouseMoved ||
                                                         (event.type == Event::MouseButtonPressed &&
                                                          event.mouseButton.button == Mouse::Left))) {

                HoverAndClickLevelSelectButtons(window, event, 130, level1SelectButtonIsHover, "1", isUserInGame,
                                                selectedLevel);
                if (numberOfCompletedLevels > 0) {
                    HoverAndClickLevelSelectButtons(window, event, 200, level2SelectButtonIsHover, "2", isUserInGame,
                                                    selectedLevel);
                }
            }


            if (isUserInGame) {
                if (numberOfBlocks > 0 && !userLost) {
                    if (event.type == Event::KeyPressed &&
                        (event.key.code == Keyboard::D || event.key.code == Keyboard::Right) &&
                        player.getPosition().x + player.getSize().x <= window.getSize().x) {
                        player.move(10, 0);
                    }
                    if (event.type == Event::KeyPressed &&
                        (event.key.code == Keyboard::A || event.key.code == Keyboard::Left) &&
                        player.getPosition().x >= 0) {
                        player.move(-10, 0);
                    }
                }else{
                    if(event.type == Event::MouseMoved ||
                       (event.type == Event::MouseButtonPressed &&
                        event.mouseButton.button == Mouse::Left)){
                        hoverAndClickBackToLevelsButton(window,event,buttonBackToLevelsIsHover, isUserInLevelSelect, isUserInGame);
                        hoverAndClickRestartLevelButton(window,event,buttonRestartLevelIsHover, userLost, createBorad);
                    }
                }
            }
        }


        if (isUserInGame) {
            if (createBorad) {
                blocks.clear();
                for (int i = 0; i < gameLevels[selectedLevel - 1].size(); i++) {
                    BlockClass Block(gameLevels[selectedLevel - 1][i].x, gameLevels[selectedLevel - 1][i].y,
                                     blockTexture);
                    blocks.push_back(Block);
                };
                numberOfBlocks = blocks.size();
                ball.setPosition(320-11,480-22-23);
                yValocityBall = -4;
                xValocityBall = -4;
                player.setPosition(320-51,480-23);
                createBorad = false;
            }

            if (numberOfBlocks > 0 && !userLost) {
                if (ball.getPosition().x < 0 || ball.getPosition().x > window.getSize().x) {
                    xValocityBall = -xValocityBall;
                }
                if (ball.getPosition().y < 0) {
                    yValocityBall = -yValocityBall;
                }
                if (ball.getPosition().y >= window.getSize().y) {
                    userLost = true;
                }

                if (ball.getGlobalBounds().intersects(player.getGlobalBounds()) == true) {
                    yValocityBall = -yValocityBall;
                }
                for (int i = 0; i < blocks.size(); i++) {
                    if (ball.getGlobalBounds().intersects(blocks[i].drawBlock().getGlobalBounds()) == true) {

                        yValocityBall = -yValocityBall;
                        blocks.erase(blocks.begin() + i);
                        numberOfBlocks--;
                    }
                }
                ball.move(xValocityBall, yValocityBall);


                window.clear();
                background.drawGameBackground(gameBackgroundTexture, window);
                window.draw(player);
                window.draw(ball);
                for (int i = 0; i < blocks.size(); i++) {
                    window.draw(blocks[i].drawBlock());
                }


                window.display();
            } else {
                window.clear();
                background.drawGameBackground(gameBackgroundTexture, window);
                window.draw(player);
                window.draw(ball);
                for (int i = 0; i < blocks.size(); i++) {
                    window.draw(blocks[i].drawBlock());
                }
                showResultScreen(window, !userLost,numberOfCompletedLevels);
                Texture buttonExitTexture;
                Texture buttonRestartTexture;
                if(buttonBackToLevelsIsHover){
                    buttonExitTexture.loadFromFile("../images/button-exit-hover.png");
                }else{
                    buttonExitTexture.loadFromFile("../images/button-exit.png");
                }
                if(buttonRestartLevelIsHover){
                    buttonRestartTexture.loadFromFile("../images/button-restart-hover.png");
                }else{
                    buttonRestartTexture.loadFromFile("../images/button-restart.png");
                }
                showBackToLevelsButton(window,buttonExitTexture);
                showRestartLevelButton(window, buttonRestartTexture);
                window.display();
            }
        }


        if (isUserInMenu && !newGameButtonIsHover && !settingsButtonIsHover && !isUserInLevelSelect) {
            window.clear();
            menu.drawMenu(menuTexture, window);
            window.draw(newGameButtonShape);
            window.draw(settingsButtonShape);
            window.display();

        }

        if (isUserInLevelSelect && !level1SelectButtonIsHover && !level2SelectButtonIsHover && !isUserInGame) {
            if (isUserInMenu) {
                isUserInMenu = false;
            }
            userLost = false;
            createBorad = true;
            window.clear();
            levelSelect.drawLevelSelect(levelSelectTexture, window, levelButtonTexture, numberOfCompletedLevels);

            window.display();
        }

    }

    return 0;
}


