#include "Player.h"

Player::Player(sf::Vector2f pos)
	:SmartCar("car", pos)
{
	m_speed = 0;
}
