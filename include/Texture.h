#pragma once
#include <SFML/Graphics.hpp>

class Texture
{
public:
	Texture(std::string name, sf::Vector2f pos);
	void draw(sf::RenderWindow& window) { window.draw(m_sprite); }
	void setPosition(sf::Vector2f pos) { m_sprite.setPosition(pos); }
	~Texture() {};
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
};
