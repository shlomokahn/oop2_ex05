#pragma once
#include "SrartWindow.h"
#include <fstream>
#include "Controller.h"
#include "Help.h"
#include "Exit.h"
#include "UserSettings.h"
#include "SoundManager.h"

StartWindow::StartWindow() 
    :Object("back", { 0,0 })
{
}
//===========================================
void StartWindow::createButtons() 
{
	const float width = m_window.getSize().x;
    const float height = m_window.getSize().y;
    const sf::Vector2f sizeBotton(width / 5, height / 16);
    sf::Vector2f posBotton = { (width - sizeBotton.x) / 2, height / 4 };
    menu.add("Play", std::make_unique<Controller>(), sizeBotton, posBotton);
    posBotton.y += sizeBotton.y * 2;
	menu.add("Settings", std::make_unique<UserSettings>(), sizeBotton, posBotton);
    posBotton.y += sizeBotton.y * 2;
    menu.add("Help", std::make_unique<Help>(), sizeBotton, posBotton);
    posBotton.y += sizeBotton.y * 2;
    menu.add("Exit", std::make_unique<Exit>(), sizeBotton, posBotton);
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
                sf::View view = m_window.getView();
                view.setCenter(view.getSize().x / 2, view.getSize().y / 2);
                m_window.setView(view);
			}
        }
    }
    return true;
}
//============================================
void StartWindow::draw() 
{
    m_window.clear();
    Object::draw(m_window);
	menu.draw(m_window);
    m_window.display();
}
//============================================
bool StartWindow::run() 
{
    m_window.create(sf::VideoMode(1400, 1000), "Game Start Menu");
    m_window.setFramerateLimit(60);
    createButtons();
    SoundManager::getInstance().playSound("menuBackraund");
    setScale(m_window.getSize().x, m_window.getSize().y);

    while (m_window.isOpen()) 
    {
		if (!handleEvents())
			return false;
        draw();
    }
	return true;
}
