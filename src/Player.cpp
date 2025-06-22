#pragma once
#include "Player.h"

Player::Player(sf::Vector2f pos)
	:SmartCar("car", pos)
{
	m_toMove.y = 30;
}
//===========================================
void Player::action(const float time)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_countRect -= time * m_steere;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_countRect += time * m_steere;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_toMove.y < m_maxSpeed) {
		m_toMove.y += time * m_accelerat;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_toMove.y > m_minSpeed) {
		m_toMove.y-= time * m_slow;
	}
	else if(m_toMove.y > m_minSpeed){
		m_toMove.y -= time * 50;
	}
	SmartCar::action(time);
}
//===========================================
void Player::collision(Object& other)
{
	if (this->getGlobal().intersects(other.getGlobal()))
		other.collided(*this);
}
//===========================================
void Player::collided(Object& other)
{
}
//===========================================
void Player::draw(sf::RenderWindow& window)
{
	sf::View view = window.getView(); 

	view.setCenter(getGlobal().getPosition()); // קבע את המרכז למיקום השחקן
	window.setView(view); // עדכן את ה-View של החלון

	Object::draw(window); // צייר את האובייקט
}
