#include "SrartWindow.h"
#include <fstream>
#include <iostream>

StartWindow::StartWindow() : m_showHelp(false) {
    initializeWindow();
    createButtons();
}

void StartWindow::initializeWindow() {
    m_window.create(sf::VideoMode(800, 600), "Game Start Menu");
    m_window.setFramerateLimit(60);

    // Load font
    if (!m_font.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
}

void StartWindow::createButtons() {
    // Create Play button
    m_playButtonRect.setSize(sf::Vector2f(200, 50));
    m_playButtonRect.setPosition(300, 200);
    m_playButtonRect.setFillColor(sf::Color(50, 50, 50));
    m_playButtonRect.setOutlineThickness(2);
    m_playButtonRect.setOutlineColor(sf::Color::White);

    m_playButton.setFont(m_font);
    m_playButton.setString("Play");
    m_playButton.setCharacterSize(30);
    m_playButton.setFillColor(sf::Color::White);
    m_playButton.setPosition(
        m_playButtonRect.getPosition().x + (m_playButtonRect.getSize().x - m_playButton.getLocalBounds().width) / 2,
        m_playButtonRect.getPosition().y + (m_playButtonRect.getSize().y - m_playButton.getLocalBounds().height) / 2 - 5
    );

    // Create Help button
    m_helpButtonRect.setSize(sf::Vector2f(200, 50));
    m_helpButtonRect.setPosition(300, 300);
    m_helpButtonRect.setFillColor(sf::Color(50, 50, 50));
    m_helpButtonRect.setOutlineThickness(2);
    m_helpButtonRect.setOutlineColor(sf::Color::White);

    m_helpButton.setFont(m_font);
    m_helpButton.setString("Help");
    m_helpButton.setCharacterSize(30);
    m_helpButton.setFillColor(sf::Color::White);
    m_helpButton.setPosition(
        m_helpButtonRect.getPosition().x + (m_helpButtonRect.getSize().x - m_helpButton.getLocalBounds().width) / 2,
        m_helpButtonRect.getPosition().y + (m_helpButtonRect.getSize().y - m_helpButton.getLocalBounds().height) / 2 - 5
    );

    // Create Help text background
    m_helpBackground.setSize(sf::Vector2f(600, 400));
    m_helpBackground.setPosition(100, 100);
    m_helpBackground.setFillColor(sf::Color(30, 30, 30, 230));
    m_helpBackground.setOutlineThickness(2);
    m_helpBackground.setOutlineColor(sf::Color::White);

    // Create Help text
    m_helpText.setFont(m_font);
    m_helpText.setCharacterSize(20);
    m_helpText.setFillColor(sf::Color::White);
    m_helpText.setPosition(120, 120);
}

void StartWindow::handleEvents() {
    sf::Event event;
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);

                // Check Play button
                if (m_playButtonRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_window.close();
                }
                // Check Help button
                else if (m_helpButtonRect.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_showHelp = !m_showHelp;
                    if (m_showHelp) {
                        showHelp();
                    }
                }
                // Close help if clicking outside
                else if (m_showHelp && !m_helpBackground.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                    m_showHelp = false;
                }
            }
        }
    }
}

void StartWindow::showHelp() {
    std::ifstream helpFile("resources/help.txt");
    if (helpFile.is_open()) {
        std::string helpContent;
        std::string line;
        while (std::getline(helpFile, line)) {
            helpContent += line + "\n";
        }
        m_helpText.setString(helpContent);
        helpFile.close();
    }
    else {
        m_helpText.setString("Help file not found!");
    }
}

void StartWindow::draw() {
    m_window.clear(sf::Color(100, 100, 100));

    // Draw buttons
    m_window.draw(m_playButtonRect);
    m_window.draw(m_playButton);
    m_window.draw(m_helpButtonRect);
    m_window.draw(m_helpButton);

    // Draw help if active
    if (m_showHelp) {
        m_window.draw(m_helpBackground);
        m_window.draw(m_helpText);
    }

    m_window.display();
}

void StartWindow::run() {
    while (m_window.isOpen()) {
        handleEvents();
        draw();
    }
}

bool StartWindow::isOpen() const {
    return m_window.isOpen();
}

void StartWindow::close() {
    m_window.close();
}
