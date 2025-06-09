#pragma once
#include <SFML/Graphics.hpp>
#include "Texture.h"

class Object
{
public:
	Object(std::string name, sf::Vector2f pos);

	virtual void action(const float time);

	void draw(sf::RenderWindow& window);
	void setRect(const sf::Vector2f location);
	~Object() {};
protected:
	void setSise(const float scale);
private:
	sf::Sprite m_sprite;
};
