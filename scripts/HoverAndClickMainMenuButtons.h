#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


using namespace sf;
void HoverAndClickMainMenuButtons(RenderWindow &window, Event &event,int y, Texture &menuTexture, RectangleShape &buttonShape,Texture &buttonHoverTexture, bool &buttonIsHover,RectangleShape &secendButtonShape);