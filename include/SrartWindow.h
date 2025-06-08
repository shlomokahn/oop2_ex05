#pragma once
//#include <SFML/Graphics.hpp>
//#include <string>
#include "PrintText.h"

class StartWindow {
public:
    StartWindow();
    ~StartWindow() = default;

    void run();

private:
    void createButtons();
    void handleEvents();
    void draw();
    void showHelp();
    sf::RectangleShape createButton(const sf::Vector2f& size, const sf::Vector2f& position);


    sf::RenderWindow m_window;
    sf::RectangleShape m_playButtonRect;
    sf::RectangleShape m_helpButtonRect;
    sf::RectangleShape m_helpBackground;
};
