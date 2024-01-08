#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;
void showResultScreen(RenderWindow &window, bool userWon, int &completedLevels){
    Texture ResultTexture;
    Font font;
    font.loadFromFile("../fonts/RubikDoodleShadow-Regular.ttf");
    Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setStyle(Text::Bold);
    text.setFillColor(Color::Black);
    if(userWon){
        ResultTexture.loadFromFile("../images/result-screen-win.png");
        text.setString("Wygrales!");
        text.setPosition(260,200);
        completedLevels++;
    }else{
        ResultTexture.loadFromFile("../images/result-screen-lose.png");
        text.setString("Przegrales!");
        text.setPosition(243,200);
    }
    RectangleShape ResultShape;
    ResultShape.setSize(Vector2f(306,442));
    ResultShape.setTexture(&ResultTexture);
    ResultShape.setPosition(320-153,240-221);

    window.draw(ResultShape);
    window.draw(text);

}