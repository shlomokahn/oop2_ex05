#pragma once
#include "Texture.h"
#include "Menu.h"
#include "Object.h"

class StartWindow : public Object 
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
