#pragma once
#include "Player.h"

bool Player::m_isDead = false;

Player::Player(sf::Vector2f pos)
	:SmartCar("car", pos)
{
	m_isDead = false;
	m_toMove.y = 30;
}
//===========================================
void Player::move(const float deltaTime)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_countRect -= deltaTime * m_steere;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_countRect += deltaTime * m_steere;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_toMove.y < m_maxSpeed) {
		m_toMove.y += deltaTime * m_accelerat;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_toMove.y > m_minSpeed) {
		m_toMove.y-= deltaTime * m_slow;
	}
	else if(m_toMove.y > m_minSpeed){
		m_toMove.y -= deltaTime * 50;
	}
	SmartCar::move(deltaTime);
}
//===========================================
void Player::collision(Object* other)
{
	if (this->getGlobal().intersects(other->getGlobal()))
		other->collided(this);
}
//===========================================
void Player::draw(sf::RenderWindow& window)
{
	sf::View view = window.getView(); 

	view.setCenter({ getGlobal().getPosition().x,getGlobal().getPosition().y-200 }); // קבע את המרכז למיקום השחקן
	window.setView(view); // עדכן את ה-View של החלון

	Object::draw(window); // צייר את האובייקט
}
