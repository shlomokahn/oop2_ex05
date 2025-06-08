#include "PrintText.h"
#include <iostream>

PrintText::PrintText()
{
    if (!m_font.loadFromFile("resources/arial.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
    }
}
//===================================
PrintText::~PrintText() = default;
//===================================
PrintText& PrintText::getInstance()
{
    static PrintText instance;
    return instance;
}
//===================================
void PrintText::drawText(sf::RenderWindow& window, const std::string& str, unsigned int size, sf::Color color, sf::Vector2f position)
{
    m_text.setFont(m_font);
    m_text.setString(str);
    m_text.setCharacterSize(size);
    m_text.setFillColor(color);

    auto bounds = m_text.getLocalBounds();
    m_text.setOrigin(bounds.width / 2, bounds.height / 2);

    if (position.x == 0)
		return; // If position is (0,0), do not draw the text
    else
        m_text.setPosition(position);
        window.draw(m_text);
}
//=====================================
void PrintText::drawText(sf::RenderWindow& window, const std::string& str, unsigned int size, sf::Color color, const sf::RectangleShape& rect)
{
	drawText(window, str, size, color, sf::Vector2f(0,0));
    auto bounds = m_text.getLocalBounds();
    m_text.setPosition(rect.getPosition().x + rect.getSize().x / 2.f,
        rect.getPosition().y + rect.getSize().y / 2.f);
    window.draw(m_text);
}
