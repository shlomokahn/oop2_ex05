#include "Object.h"

Object::Object(std::string name, sf::Vector2f pos)
	:m_texture(name, pos)
{
}
//===============================================
void Object::draw(sf::RenderWindow& window)
{
	m_texture.draw(window);
}
//===============================================