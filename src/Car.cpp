#pragma once
#include "Car.h"

Car::Car(std::string name,sf::Vector2f pos)
	:Object(name, pos)
{
}
//===============================
void Car::action(const float time)
{
	Object::action(-time);
}
