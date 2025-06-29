#pragma once
#include "EnemyCar.h"
#include "Io.h"

EnemyCar::EnemyCar(const sf::Vector2f path, const int speed)
	: Car("car", path)
{
	m_toMove.y = speed;
}
//==============================
void EnemyCar::collided(Player* player)
{
	player->collided(this);
}
