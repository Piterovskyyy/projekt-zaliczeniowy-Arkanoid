#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;
void showSettingsScreen(RenderWindow &window, Texture &leaveButtonTexture,Texture &musicToggleTexture, Texture &increaseMusicValueTexture, Texture &decreaseMusicValueTexture){
    Texture settingsTexture;
    settingsTexture.loadFromFile("../images/settings-screen.png");

    RectangleShape settingsShape;
    settingsShape.setSize(Vector2f(306,442));
    settingsShape.setTexture(&settingsTexture);
    settingsShape.setPosition(320-153,240-221);

    RectangleShape leaveButton;
    leaveButton.setSize(Vector2f(50,50));
    leaveButton.setTexture(&leaveButtonTexture);
    leaveButton.setPosition(320-25, 250);

    RectangleShape musicToggleButton;
    musicToggleButton.setSize(Vector2f(50,50));
    musicToggleButton.setTexture(&musicToggleTexture);
    //320-25-20-50 middle - half button - margin- button;
    musicToggleButton.setPosition(320-25-20-50, 100);

    RectangleShape increaseMusicValueButton;
    increaseMusicValueButton.setSize(Vector2f(50,50));
    increaseMusicValueButton.setTexture(&increaseMusicValueTexture);
    increaseMusicValueButton.setPosition(320-25, 100);

    RectangleShape decreaseMusicValueButton;
    decreaseMusicValueButton.setSize(Vector2f(50,50));
    decreaseMusicValueButton.setTexture(&decreaseMusicValueTexture);
    //320+25+20 middle + half button + margin
    decreaseMusicValueButton.setPosition(320+25+20, 100);




    window.draw(settingsShape);
    window.draw(musicToggleButton);
    window.draw(increaseMusicValueButton);
    window.draw(decreaseMusicValueButton);
    window.draw(leaveButton);


}
