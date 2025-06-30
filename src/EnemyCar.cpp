#pragma once
#include "EnemyCar.h"
#include "Io.h"

EnemyCar::EnemyCar(const sf::Vector2f path, const int speed)
	: Car("car", path)
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
	player->collided(this);
}
//====================================
void EnemyCar::collided(EnemyCar* enemyCar)
{
	m_toMove.y += ((getGlobal().top > enemyCar->getGlobal().top) ? -1 : 1);
}
