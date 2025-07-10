#pragma once
#include <sstream>

#include "Player.h"
#include <Io.h>
#include <SoundManager.h>
#include "Explotion.h"
#include "PrintText.h"

bool Player::m_isDead = false;
float Player::m_score = 0;

Player::Player(sf::Vector2f pos, std::istringstream& iss)
	:SmartCar("car", pos)
{
	iss >> m_minSpeed >> m_maxSpeed >> m_accelerat >> m_slow;

	m_isDead = false;
	m_toMove.y = m_minSpeed;
	m_circle.setRadius(getSizeCar().x/1.5);
	m_circle.setFillColor(sf::Color::White);
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
		m_toMove.y -= deltaTime * m_slow/3;
	}
	m_score += ((deltaTime * m_toMove.y) / 2000) * m_toMove.y;
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
	printData(window);
	ObjectMove::draw(window); // צייר את האובייקט
	if (m_explotion != nullptr) {
		m_explotion->draw(window);
	}
}
//===========================================
void Player::printData(sf::RenderWindow &window)
{
	m_circle.setPosition(m_sprite.getPosition().x - window.getSize().x / 2 + getSizeCar().x, m_sprite.getPosition().y);
	window.draw(m_circle);
	PrintText::getInstance().drawText(window, std::to_string(int(m_toMove.y)) + "KMH", m_circle.getRadius()/2, (m_toMove.y > 80) ? sf::Color::Red : sf::Color::Black, m_circle);

	m_circle.setPosition(m_sprite.getPosition().x + window.getSize().x / 2 - getSizeCar().x, m_sprite.getPosition().y);
	window.draw(m_circle);
	PrintText::getInstance().drawText(window, std::to_string(int(m_score)) + "$", m_circle.getRadius() / 2, (m_toMove.y > 50) ? sf::Color::Green : sf::Color::Black, m_circle);
}
//===========================================
