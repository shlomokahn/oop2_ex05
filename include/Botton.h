#pragma once
#include <SFML/Graphics.hpp>
#include "PrintText.h"

class Botton
{
public:
	Botton(const std::string& name, const sf::Vector2f& size, const sf::Vector2f& position);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getGlobalBounds() const { return m_buttonRect.getGlobalBounds(); }
	const std::string& getName() const { return m_name; }
private:
	sf::RectangleShape m_buttonRect;
	std::string m_name;
};