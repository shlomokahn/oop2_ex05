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
	m_toMove.x = 0;
	static float countRect = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		setRect(countRect -= time*5);
		m_toMove.x = -countRect * 30;
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		setRect(countRect += time*5);
		m_toMove.x = -countRect * 30;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
	{
		static float countTimeUP = 0;
		countTimeUP += time;
		if(countTimeUP > 0.01)
		{
			countTimeUP -= 0.01f;
			m_toMove.y++;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_toMove.y > 30) {
		static float countTimeDOWN = 0;
		countTimeDOWN += time;
		if (countTimeDOWN > 0.01)
		{
			countTimeDOWN -= 0.01f;
			m_toMove.y-=3;
		}
	}
	else if(m_toMove.y > 30)
	{
		static float countTime = 0;
		countTime += time;
		if (countTime > 0.03)
		{
			countTime -= 0.03f;
			m_toMove.y--;
		}
	}
	Car::action(time);
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
