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
		m_countRect -= time * 5;	
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_countRect += time * 5;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		m_toMove.y += time * 50;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_toMove.y > 30) {
		m_toMove.y-= time * 200;
	}
	else if(m_toMove.y > 30){
		m_toMove.y -= time * 100;
	}
	SmartCar::action(time);
}
//===========================================
void Player::collision(Object& other)
{
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
