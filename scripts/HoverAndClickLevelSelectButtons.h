#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>


using namespace sf;
using  namespace std;
void  HoverAndClickLevelSelectButtons(RenderWindow &window, Event &event,int x, bool &LevelSelectButtonIsHover, string levelNumberString, bool &userInGame, int &selectedLevel);