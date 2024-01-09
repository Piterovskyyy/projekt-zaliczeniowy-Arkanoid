#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
using namespace sf;

class BlockClass {
private:
    int x;
    int y;
    Texture kindTexture;
    int kind;
public:
    RectangleShape drawBlock();
    BlockClass(int setX ,int setY, Texture &setKindTexture, int setKind);
    int getKind();
    int getX();
    int getY();

};