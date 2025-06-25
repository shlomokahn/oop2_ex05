#pragma once
#include "Car.h"

Car::Car(std::string name,sf::Vector2f pos)
	:ObjectMove(name, pos)
{
}
//===============================
void Car::move(const float deltaTime)
{
	ObjectMove::move(-deltaTime);
}
