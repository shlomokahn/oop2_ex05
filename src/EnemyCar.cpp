#pragma once
#include "EnemyCar.h"
#include "Io.h"

EnemyCar::EnemyCar(const sf::Vector2f path, const int speed, std::string carType)
	: Car(carType, path)
{
	m_toMove.y = speed;
}
//====================================
void EnemyCar::collision(Object* other)
{
	if (this->getGlobal().intersects(other->getGlobal()))
		other->collided(this);
}
//==============================
void EnemyCar::collided(Player* player)
{
}
//====================================
void EnemyCar::collided(EnemyCar* enemyCar)
{
	m_toMove.y += ((getGlobal().top > enemyCar->getGlobal().top) ? -1 : 1);
}
//====================================
void EnemyCar::collided(Block* block)
{
	m_toMove.y = 0;
}
