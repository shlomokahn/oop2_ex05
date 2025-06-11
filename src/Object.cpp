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
void Object::setRect(const float rotation)
{
	m_sprite.setOrigin(SIZE_CAR.x / 2, SIZE_CAR.y / 2);
	m_sprite.setRotation(rotation);
	//m_sprite.setTextureRect(sf::IntRect(SIZE_CAR.x * location.x, SIZE_CAR.y * location.y, SIZE_CAR.x, SIZE_CAR.y));
}
//===============================================
void Object::setSise(const float scale)
{
	m_sprite.setScale(scale, scale);
}
//===============================================
void Object::action(const float time)
{
	m_sprite.move(m_toMove.x * time * KMH, m_toMove.y * time * KMH);
	auto i = m_sprite.getGlobalBounds();
}