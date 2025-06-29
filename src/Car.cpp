#pragma once
#include "Car.h"
#include <Io.h>

Car::Car(std::string name,sf::Vector2f pos)
	:ObjectMove(name, pos)
{
	setScale(SIZE_CAR.x, SIZE_CAR.y);
}
//===============================
void Car::move(const float deltaTime)
{
	ObjectMove::move(-deltaTime);
}
