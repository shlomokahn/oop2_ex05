#pragma once

#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Command.h"

class PauseMenu {
public:
    PauseMenu(sf::RenderWindow& window);

    void draw();
    void handleEvent(const sf::Event& event, bool& resume, bool& exit);

private:
    sf::RenderWindow& m_window;
    Menu m_menu;
    sf::RectangleShape m_background;

    bool m_clicked = false;
};
