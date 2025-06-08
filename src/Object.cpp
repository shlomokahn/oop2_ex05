#include "Object.h"

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