#pragma once
#include "SrartWindow.h"
#include <fstream>

StartWindow::StartWindow() 
{
    createButtons();
}
//===========================================
sf::RectangleShape StartWindow::createButton(const sf::Vector2f& size, const sf::Vector2f& position) 
{
    sf::RectangleShape button;
    button.setSize(size);
    button.setPosition(position);
    button.setFillColor(sf::Color(50, 50, 50));
    button.setOutlineThickness(2);
    button.setOutlineColor(sf::Color::White);
    return button;
}
//===========================================
void StartWindow::createButtons() {
    // Play button
    m_playButtonRect = createButton({ 200, 50 }, { 300, 200 });

    // Help button
    m_helpButtonRect = createButton({ 200, 50 }, { 300, 300 });

    // Help background
    m_helpBackground = createButton({ 600, 400 }, { 100, 100 });
    m_helpBackground.setFillColor(sf::Color(30, 30, 30, 230));
}
//===========================================
void StartWindow::handleEvents() 
{
    sf::Event event;
    while (m_window.pollEvent(event)) 
    {
        if (event.type == sf::Event::Closed)
            m_window.close();

        else if (event.type == sf::Event::MouseButtonPressed) 
        {
            if (event.mouseButton.button == sf::Mouse::Left) 
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                if (m_playButtonRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
                {
                    m_window.close();
                }
                else if (m_helpButtonRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) 
                {
                        showHelp();
                }
            }
        }
    }
}
//===========================================
void StartWindow::showHelp() 
{
    m_window.draw(m_helpBackground);
    std::ifstream helpFile("resources/help.txt");
    std::string line;
    std::string helpContent;

    while (std::getline(helpFile, line)) 
        helpContent += line + '\n';

    helpFile.close();
    PrintText::getInstance().drawText(m_window, helpContent, 20, sf::Color::White, sf::Vector2f(120, 120));
}
//============================================
void StartWindow::draw() {
    m_window.clear(sf::Color(100, 100, 100));

    m_window.draw(m_playButtonRect);
    PrintText::getInstance().drawText(m_window, "Play", 30, sf::Color::White, m_playButtonRect);
    m_window.draw(m_helpButtonRect);
    PrintText::getInstance().drawText(m_window, "Help", 30, sf::Color::White, m_helpButtonRect);

    m_window.display();
}
//============================================
void StartWindow::run() 
{
    m_window.create(sf::VideoMode(800, 600), "Game Start Menu");
    m_window.setFramerateLimit(60);

    while (m_window.isOpen()) 
    {
        handleEvents();
        draw();
    }
}
