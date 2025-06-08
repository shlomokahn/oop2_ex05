#pragma once
#include <SFML/Graphics.hpp>
#include "Texture.h"

class Object
{
public:
	Object(std::string name, sf::Vector2f pos);
	void draw(sf::RenderWindow& window);
	void setRect(const sf::Vector2f location);
	~Object() {};
private:
	sf::Sprite m_sprite;
};
