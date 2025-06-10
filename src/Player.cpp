#include "Player.h"

Player::Player(sf::Vector2f pos)
	:SmartCar("car", pos)
{
	m_speed = 100;
}
//===========================================
void Player::action(const float time)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		setRect(sf::Vector2f(2, 5));
		m_sprite.move(-m_speed * time, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_sprite.move(m_speed * time, 0);
		setRect(sf::Vector2f(2, 2));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_sprite.move(0, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_sprite.move(0, 0);
	}
	else
	{
		m_sprite.move(0, 0);
		setRect(sf::Vector2f(2, 4));
	}
}
//===========================================
void Player::collision(Object& other)
{
	if (other.getSprite().getGlobalBounds().intersects(m_sprite.getGlobalBounds())) {
		// Handle collision logic here
		// For example, you can stop the player or change its position
		m_sprite.setPosition(m_sprite.getPosition().x, m_sprite.getPosition().y - 10); // Move up slightly on collision
	}
}
//===========================================
void Player::collided(Object& other)
{
}
