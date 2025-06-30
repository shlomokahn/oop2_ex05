#pragma once
#include "Object.h"
#include "Io.h"

Object::Object(std::string name, sf::Vector2f pos)
{
	m_sprite.setTexture(Texture::getInstance().getTexture(name));
	m_sprite.setPosition(pos);
}
//===============================================
void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//===============================================
void Object::setScale(float x, float y)
{
	sf::Vector2f textureSize = m_sprite.getGlobalBounds().getSize();
	float scaleX = x / textureSize.x;
	float scaleY = y / textureSize.y;
	m_sprite.setScale(scaleX, scaleY);
}
//===============================================
