#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class StartWindow {
public:
    StartWindow();
    ~StartWindow() = default;

    void run();
    bool isOpen() const;
    void close();

private:
    void initializeWindow();
    void createButtons();
    void handleEvents();
    void draw();
    void showHelp();

    sf::RenderWindow m_window;
    sf::Font m_font;
    sf::Text m_playButton;
    sf::Text m_helpButton;
    sf::RectangleShape m_playButtonRect;
    sf::RectangleShape m_helpButtonRect;
    bool m_showHelp;
    sf::Text m_helpText;
    sf::RectangleShape m_helpBackground;
};
