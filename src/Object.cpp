#include "Object.h"
#include "Io.h"

Object::Object(std::string name, sf::Vector2f pos)
{
	m_sprite.setTexture(Texture::getInstance().getTexture(name));
	setRect(sf::Vector2f(2, 4));
	m_sprite.setPosition(pos);
}
//===============================================
void Object::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}
//===============================================
void Object::setRect(const sf::Vector2f location)
{
	m_sprite.setTextureRect(sf::IntRect(SIZE_CAR.x * location.x, SIZE_CAR.y * location.y, SIZE_CAR.x, SIZE_CAR.y));
}
//===============================================
void Object::setSise(const float scale)
{
	m_sprite.setScale(scale, scale);
}
//===============================================
void Object::action(const float time)
{
	int x = (m_sprite.getPosition().x - 800);
	float moveX = ((x < 0) ? -time/5 : time/5);
	m_sprite.move(moveX, time);

}