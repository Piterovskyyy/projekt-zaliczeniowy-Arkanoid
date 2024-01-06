#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


using namespace sf;
void showResultScreen(RenderWindow &window, bool userWon){
    Texture ResultTexture;
    if(userWon){
        ResultTexture.loadFromFile("../images/result-screen-win.png");
    }else{
        ResultTexture.loadFromFile("../images/result-screen-lose.png");
    }
    RectangleShape ResultShape;
    ResultShape.setSize(Vector2f(306,442));
    ResultShape.setTexture(&ResultTexture);
    ResultShape.setPosition(0,0);
    window.draw(ResultShape);
    window.display();
}