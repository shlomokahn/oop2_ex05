#pragma once
#include "SrartWindow.h"
#include <fstream>
#include "Controller.h"
#include "Help.h"

StartWindow::StartWindow() 
{
    createButtons();
}
//===========================================
void StartWindow::createButtons() 
{
	menu.add(m_window, "Play", std::make_unique<Controller>(), { 200, 50 }, { 300, 200 });
	menu.add(m_window, "Help", std::make_unique<Help>(), { 200, 50 }, { 300, 300 });



    // Help background
 //   m_helpBackground = createButton({ 600, 400 }, { 100, 100 });
 //   m_helpBackground.setFillColor(sf::Color::Black);
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
////===========================================
//void StartWindow::showHelp() 
//{
//    //m_window.draw(m_helpBackground);
//    std::ifstream helpFile("resources/help.txt");
//    std::string line;
//    std::string helpContent;
//
//    while (std::getline(helpFile, line)) 
//        helpContent += line + '\n';
//
//    helpFile.close();
//    //PrintText::getInstance().drawText(m_window, helpContent, 20, sf::Color::White, m_helpBackground);
//	m_window.display();
//	// Wait for user to close the help window
//	bool helpOpen = true;
//	while (helpOpen)
//	{
//		sf::Event event;
//		while (m_window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed)
//			{
//				m_window.close();
//				helpOpen = false;
//			}
//			else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
//			{
//				helpOpen = false; // Close help on mouse click
//			}
//		}
//	}
//}
//============================================
void StartWindow::draw() {
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
