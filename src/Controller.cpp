#include "Controller.h"
#include <SFML/Graphics.hpp>

Controller::Controller() {
    // Constructor implementation
}
//===============================================
void Controller::run() 
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }
}