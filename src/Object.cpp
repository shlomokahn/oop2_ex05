#pragma once
#include "Object.h"
#include "Io.h"

Object::Object(std::string name, sf::Vector2f pos)
{
	m_sprite.setTexture(Texture::getInstance().getTexture(name));
	sf::Vector2f textureSize = m_sprite.getGlobalBounds().getSize();
	float scaleX = SIZE_CAR.x / textureSize.x;
	float scaleY = SIZE_CAR.y / textureSize.y;
	m_sprite.setScale(scaleX, scaleY);
	m_sprite.setPosition(pos);
}
//===============================================
void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//===============================================