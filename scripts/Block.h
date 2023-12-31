#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class BlockClass {
private:
    int x;
    int y;
    Texture kind;
public:
    RectangleShape drawBlock();
    BlockClass(int setX ,int setY, Texture &setKind);

};