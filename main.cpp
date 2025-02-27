#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Audio/Music.hpp>
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
#include "scripts/showSettingsScreen.h"
#include "scripts/HoverAndClickSettingsButtons.h"


using namespace std;
using namespace sf;

int main() {
    RenderWindow window(VideoMode(640, 480), "Arkanoid");
    window.setFramerateLimit(70);

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


    Texture musicToggleTexture, decreaseMusicValueTexture, increaseMusicValueTexture, leaveButonTexture;
    bool isMusicToggleButtonHover = false;
    bool isDecreaseMusicValueButtonHover = false;
    bool isIncreaseMusicValueButtonHover = false;
    bool isLeaveButtonHover = false;



    bool newGameButtonIsHover = false;
    bool settingsButtonIsHover = false;
    bool level1SelectButtonIsHover = false;
    bool level2SelectButtonIsHover = false;
    bool buttonBackToLevelsIsHover = false;
    bool buttonRestartLevelIsHover = false;
    bool isMiniSettingsButtonHover = false;
    int numberOfCompletedLevels = 1;
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
    Texture blockTextureKind0;
    if (blockTextureKind0.loadFromFile("../images/spritessheet.png", IntRect(0, 0, 64, 32)) == -1) {
        return 1;

    }
    Texture blockTextureKind1;
    if (blockTextureKind1.loadFromFile("../images/spritessheet.png", IntRect(64, 0, 64, 32)) == -1) {
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

    Texture buttonMiniSettingsTexture;
    if(buttonMiniSettingsTexture.loadFromFile("../images/button-mini-settings.png") == -1){
        return 1;
    }
    Texture buttonMiniSettingsHoverTexture;
    if(buttonMiniSettingsHoverTexture.loadFromFile("../images/button-mini-settings-hover.png") == -1){
        return 1;
    }


    Music backgroundMusic;
    if(!(backgroundMusic.openFromFile("../sounds/music.ogg"))){
        return 1;
    }
    backgroundMusic.play();
    backgroundMusic.setVolume(50);
    backgroundMusic.setLoop(true);



    PaddleClass paddle;
    RectangleShape player = paddle.drawPaddle(paddleTexture);
    GameBackgroundClass background;
    BallClass ballRect;
    RectangleShape ball = ballRect.drawBall(ballTexture);
    int xValocityBall = -5;
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
            if (isUserInMenu && !isUserInLevelSelect &&  !isUserInSettings && (event.type == Event::MouseMoved ||
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


            if (isUserInGame && !isUserInSettings) {
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
                    if(event.type == Event::MouseMoved ||
                       (event.type == Event::MouseButtonPressed &&
                        event.mouseButton.button == Mouse::Left)){
                        if (Mouse::getPosition(window).x >= 520 &&
                            Mouse::getPosition(window).x <= 520 + 50 && Mouse::getPosition(window).y >= 350 &&
                            Mouse::getPosition(window).y <= 350 + 50){
                            isMiniSettingsButtonHover = true;
                            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                                isUserInSettings = true;
                                window.clear();
                                background.drawGameBackground(gameBackgroundTexture, window);
                                window.draw(player);

                                for (int i = 0; i < blocks.size(); i++) {
                                    window.draw(blocks[i].drawBlock());
                                }
                                RectangleShape miniSettingsButton;
                                miniSettingsButton.setSize(Vector2f(50,50));
                                miniSettingsButton.setPosition(520,350);
                                if(isMiniSettingsButtonHover){
                                    miniSettingsButton.setTexture(&buttonMiniSettingsHoverTexture);
                                }else{
                                    miniSettingsButton.setTexture(&buttonMiniSettingsTexture);
                                }

                                window.draw(miniSettingsButton);
                                window.draw(ball);


                                window.display();
                                //refresh window
                                Mouse::setPosition(Vector2i(Mouse::getPosition(window).x,Mouse::getPosition(window).y),window);

                            }
                        }else{
                            isMiniSettingsButtonHover = false;
                        }
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
            if(isUserInSettings){
                HoverAndClickSettingsButtons(window, event, isLeaveButtonHover, isMusicToggleButtonHover, isIncreaseMusicValueButtonHover, isDecreaseMusicValueButtonHover, isUserInSettings, backgroundMusic);
            }

        }


        if (isUserInGame) {
            if (createBorad) {
                xValocityBall = -5;
                yValocityBall = -4;
                blocks.clear();
                for (int i = 0; i < gameLevels[selectedLevel - 1].size(); i++) {
                    Texture kindTexture;
                    if( gameLevels[selectedLevel-1][i].kind == 0){
                        kindTexture = blockTextureKind0;
                    }else{
                        kindTexture = blockTextureKind1;
                    }
                    BlockClass Block(gameLevels[selectedLevel - 1][i].x, gameLevels[selectedLevel - 1][i].y,
                                     kindTexture, gameLevels[selectedLevel - 1][i].kind);
                    blocks.push_back(Block);
                };
                numberOfBlocks = blocks.size();
                ball.setPosition(320-11,480-22-23);
                player.setPosition(320-51,480-23);
                createBorad = false;
            }

            if (numberOfBlocks > 0 && !userLost && !createBorad) {
                if(!isUserInSettings) {


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
                        if (ball.getPosition().y < window.getSize().y - 38) {
                            yValocityBall = -yValocityBall;
                        } else {
                            xValocityBall = -xValocityBall;
                        }

                    }
                    for (int i = 0; i < blocks.size(); i++) {
                        if (ball.getGlobalBounds().intersects(blocks[i].drawBlock().getGlobalBounds()) == true) {
                            if (blocks[i].getKind() == 1) {
                                int x = blocks[i].getX();
                                int y = blocks[i].getY();
                                BlockClass Block(x, y,
                                                 blockTextureKind0, 0);
                                blocks[i] = Block;
                            } else {
                                blocks.erase(blocks.begin() + i);
                                numberOfBlocks--;
                            }
                            yValocityBall = -yValocityBall;
                        }
                    }

                    ball.move(xValocityBall, yValocityBall);


                    window.clear();
                    background.drawGameBackground(gameBackgroundTexture, window);
                    window.draw(player);

                    for (int i = 0; i < blocks.size(); i++) {
                        window.draw(blocks[i].drawBlock());
                    }
                    RectangleShape miniSettingsButton;
                    miniSettingsButton.setSize(Vector2f(50,50));
                    miniSettingsButton.setPosition(520,350);
                    if(isMiniSettingsButtonHover){
                        miniSettingsButton.setTexture(&buttonMiniSettingsHoverTexture);
                    }else{
                        miniSettingsButton.setTexture(&buttonMiniSettingsTexture);
                    }

                    window.draw(miniSettingsButton);
                    window.draw(ball);


                    window.display();
                }
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


        if (isUserInMenu && !newGameButtonIsHover && !settingsButtonIsHover && !isUserInLevelSelect && !isUserInSettings) {
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


        if(isUserInSettings){

            if(isUserInMenu){
                window.clear();
            }
            if(isMusicToggleButtonHover){
                musicToggleTexture.loadFromFile("../images/button-music-hover.png");
            }else{
                musicToggleTexture.loadFromFile("../images/button-music.png");
            }

            if(isDecreaseMusicValueButtonHover){
                decreaseMusicValueTexture.loadFromFile("../images/button-minus-hover.png");
            }else{
                decreaseMusicValueTexture.loadFromFile("../images/button-minus.png");
            }

            if(isIncreaseMusicValueButtonHover){
                increaseMusicValueTexture.loadFromFile("../images/button-plus-hover.png");
            }else{
                increaseMusicValueTexture.loadFromFile("../images/button-plus.png");
            }

            if(isLeaveButtonHover){
                leaveButonTexture.loadFromFile("../images/button-exit-hover.png");
            }else{
                leaveButonTexture.loadFromFile("../images/button-exit.png");
            }


            showSettingsScreen(window, leaveButonTexture, musicToggleTexture, increaseMusicValueTexture, decreaseMusicValueTexture);
            window.display();
        }


    }

    return 0;
}


