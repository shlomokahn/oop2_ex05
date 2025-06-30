#pragma once
#include "Player.h"
#include <Io.h>
#include <SoundManager.h>

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
void Player::collided(EnemyCar* enemyCar)
{
	SoundManager::getInstance().stopAllSounds();
	SoundManager::getInstance().playSound("accident");
	_sleep(3000);
	m_isDead = true;
}
//===========================================
void Player::draw(sf::RenderWindow& window)
{
	sf::View view = window.getView(); 

	view.setCenter({ getGlobal().getPosition().x + SIZE_CAR.x/2,getGlobal().getPosition().y- SIZE_CAR.y }); // קבע את המרכז למיקום השחקן
	window.setView(view); // עדכן את ה-View של החלון

	Object::draw(window); // צייר את האובייקט
}
