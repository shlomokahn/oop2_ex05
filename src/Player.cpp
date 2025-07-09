#pragma once
#include "Player.h"
#include <Io.h>
#include <SoundManager.h>
#include "Explotion.h"

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
	if (m_explotion != nullptr) {
		m_explotion->move(deltaTime);
		if (m_explotion->isEnd()) {
			delete m_explotion;
			m_explotion = nullptr;
			m_isDead = true;
			return;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		m_countRect -= deltaTime ;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_countRect += deltaTime ;
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
	if (m_explotion == nullptr && !m_isDead)
		m_explotion = new Explotion(getGlobal().getPosition());
	m_toMove.y *= 0.2f;
}
//===========================================
void Player::collided(Block* block)
{
	if (m_explotion == nullptr && !m_isDead)
		m_explotion = new Explotion(getGlobal().getPosition());
	m_toMove.y *= 0.2f;
}
//===========================================
void Player::draw(sf::RenderWindow& window)
{
	sf::View view = window.getView(); 

	view.setCenter({ getGlobal().getPosition().x + getSizeCar().x/2,getGlobal().getPosition().y- window.getSize().y/2 + float(getSizeCar().y * 1.3)}); // קבע את המרכז למיקום השחקן
	window.setView(view); // עדכן את ה-View של החלון

	Object::draw(window); // צייר את האובייקט
	if (m_explotion != nullptr) {
		m_explotion->draw(window);
	}
}
//===========================================
