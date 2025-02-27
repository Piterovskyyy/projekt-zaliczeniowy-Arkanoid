#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace sf;
using namespace std;
void HoverAndClickSettingsButtons(RenderWindow &window, Event &event, bool &isLeaveButtonHover, bool &isMusicToggleButtonHover, bool &isIncreaseMusicButtonHover, bool &isDecreaseMusicButtonHover, bool &isUserInSettings, Music &bgMusic){
    const int buttonWidth = 50;
    const int buttonHeight = 50;
    //320-25= 295 leave button position x
    //250 leave button position y
    if (Mouse::getPosition(window).x >= 295 &&
        Mouse::getPosition(window).x <= 295 + buttonWidth && Mouse::getPosition(window).y >= 250 &&
        Mouse::getPosition(window).y <= 250 + buttonHeight){
        isLeaveButtonHover = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            isUserInSettings = false;
            isLeaveButtonHover = false;
            //refresh window
            Mouse::setPosition(Vector2i(Mouse::getPosition(window).x,Mouse::getPosition(window).y),window);
            isLeaveButtonHover = false;
            }
    }else{
        isLeaveButtonHover = false;
    }
    //320-25-20-50 = 225 button music x position
    if (Mouse::getPosition(window).x >= 225 &&
        Mouse::getPosition(window).x <= 225 + buttonWidth && Mouse::getPosition(window).y >= 100 &&
        Mouse::getPosition(window).y <= 100 + buttonHeight){
        isMusicToggleButtonHover = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            if(bgMusic.getStatus() == Music::Status::Paused){
                bgMusic.play();
            }else{
                bgMusic.pause();
            }
        }
    }else{
        isMusicToggleButtonHover = false;
    }

    //295 increaseMusicValueButton position x

    if (Mouse::getPosition(window).x >= 295 &&
        Mouse::getPosition(window).x <= 295 + buttonWidth && Mouse::getPosition(window).y >= 100 &&
        Mouse::getPosition(window).y <= 100 + buttonHeight){
        isIncreaseMusicButtonHover = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            if(bgMusic.getVolume() < 100){
                bgMusic.setVolume(bgMusic.getVolume()+10);
            }else{
                bgMusic.setVolume(100);
            }
        }
    }else{
        isIncreaseMusicButtonHover = false;
    }

     //365 decreaseMusicValueButton position x

    if (Mouse::getPosition(window).x >= 365 &&
        Mouse::getPosition(window).x <= 365 + buttonWidth && Mouse::getPosition(window).y >= 100 &&
        Mouse::getPosition(window).y <= 100 + buttonHeight){
        isDecreaseMusicButtonHover = true;
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
            if(bgMusic.getVolume() >= 10){
                cout<< bgMusic.getVolume() <<endl;
                bgMusic.setVolume(bgMusic.getVolume()-10);
                }else{
                    bgMusic.setVolume(0);
                }

        }
    }else{
        isDecreaseMusicButtonHover = false;
    }


}