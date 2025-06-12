#pragma once
#include "SrartWindow.h"
#include <fstream>
#include "Controller.h"
#include "Help.h"
#include "Exit.h"
#include "UserSettings.h"

StartWindow::StartWindow() 
{
    createButtons();
}
//===========================================
void StartWindow::createButtons() 
{
	menu.add(m_window, "Play", std::make_unique<Controller>(), { 200, 50 }, { 300, 150 });
	menu.add(m_window, "Settings", std::make_unique<UserSettings>(), { 200, 50 }, { 300, 250 });
	menu.add(m_window, "Help", std::make_unique<Help>(), { 200, 50 }, { 300, 350 });
	menu.add(m_window, "Exit", std::make_unique<Exit>(), { 200, 50 }, { 300, 450 });
}
//===========================================
bool StartWindow::handleEvents() 
{
    sf::Event event;
    while (m_window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
        {
            m_window.close();
			return false;
        }

        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
			{
				sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
				menu.maneger(m_window, mousePos);
			}
        }
    }
    return true;
}
//============================================
void StartWindow::draw() 
{
    m_window.clear();
    sf::Sprite background(Texture::getInstance().getTexture("back"));
    sf::Vector2f targetSize((float)m_window.getSize().x, (float)m_window.getSize().y);
    sf::Vector2u textureSize = background.getTexture()->getSize();

    float scaleX = targetSize.x / textureSize.x;
    float scaleY = targetSize.y / textureSize.y;

    background.setScale(scaleX, scaleY);
    m_window.draw(background);
	menu.draw(m_window);
    m_window.display();
}
//============================================
bool StartWindow::run() 
{
    m_window.create(sf::VideoMode(800, 600), "Game Start Menu");
    m_window.setFramerateLimit(60);

    while (m_window.isOpen()) 
    {
		if (!handleEvents())
			return false;
        draw();
    }
	return true;
}
