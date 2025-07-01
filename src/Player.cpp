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
	SoundManager::getInstance().stopAllSounds();
	SoundManager::getInstance().playSound("accident");
	_sleep(2000);
	m_isDead = true;
}
//===========================================
void Player::draw(sf::RenderWindow& window)
{
	sf::View view = window.getView(); 

	view.setCenter({ getGlobal().getPosition().x + getSizeCar().x/2,getGlobal().getPosition().y- getSizeCar().y }); // ��� �� ����� ������ �����
	window.setView(view); // ���� �� �-View �� �����

	Object::draw(window); // ���� �� ��������
}
