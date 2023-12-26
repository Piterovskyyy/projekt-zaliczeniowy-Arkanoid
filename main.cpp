#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

int main() {
    sf::Window window(sf::VideoMode(800, 600), "Arkanoid");
    bool play = true;
    sf::Event event;
    // run the program as long as the window is open
    while (play) {
        // check all the window's events that were triggered since the last iteration of the loop

        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                play = false;
                window.close();
            }

        }
    }

    return 0;
}


