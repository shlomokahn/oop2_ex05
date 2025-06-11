#include "Player.h"

Player::Player(sf::Vector2f pos)
	:SmartCar("car", pos)
{
	m_toMove.y = 100;
}
//===========================================
void Player::action(const float time)
{
	m_toMove.x = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		setRect(-10.f);
		m_toMove.x = m_toMove.y;
		
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		m_toMove.x = -m_toMove.y;
		setRect(10.f);
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
		if (countTimeDOWN > 0.001)
		{
			countTimeDOWN -= 0.001f;
			m_toMove.y--;
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
	//if (other.getSprite().getGlobalBounds().intersects(m_sprite.getGlobalBounds())) {
	//	// Handle collision logic here
	//	// For example, you can stop the player or change its position
	//	m_sprite.setPosition(m_sprite.getPosition().x, m_sprite.getPosition().y - 10); // Move up slightly on collision
	//}
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
