#pragma once
#include "Texture.h"
#include "Menu.h"

class StartWindow 
{
public:
    StartWindow();
    ~StartWindow() = default;
    bool run();

private:
    void createButtons();
    bool handleEvents();
    void draw();

	sf::RenderWindow m_window;
    Menu menu;
};
