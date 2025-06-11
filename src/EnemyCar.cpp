#pragma once
#include "EnemyCar.h"
#include "Io.h"

EnemyCar::EnemyCar(const int path, const int speed)
	: Car("car", sf::Vector2f(path,-SIZE_CAR.y/2))
{
	m_toMove.y = speed;
}
