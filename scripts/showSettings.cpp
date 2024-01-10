#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;
void showSettingsScreen(RenderWindow &window){
    Texture settingsTexture;
    settingsTexture.loadFromFile("../images/settings-screen.png");

    RectangleShape settingsShape;
    settingsShape.setSize(Vector2f(306,442));
    settingsShape.setTexture(&settingsTexture);
    settingsShape.setPosition(320-153,240-221);

    window.draw(settingsShape);


}
