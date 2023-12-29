#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class BlockClass {
public:
    void drawBlock(int x, int y, Texture &BlockShape, RenderWindow &window);
};