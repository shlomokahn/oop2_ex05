#pragma once
//#include <SFML/Graphics.hpp>
//#include <string>
//#include "PrintText.h"
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
   // void showHelp();

	sf::RenderWindow m_window;
    Menu menu;
};
