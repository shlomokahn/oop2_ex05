#pragma once
#include "Car.h"
#include <Io.h>


sf::Vector2f Car::m_sizeCar;

Car::Car(std::string name,sf::Vector2f pos)
	:ObjectMove(name, { pos.x + m_sizeCar.x / 4 , pos.y })
{
	setScale(m_sizeCar.x, m_sizeCar.y);
}
//===============================
void Car::move(const float deltaTime)
{
	ObjectMove::move(-deltaTime);
}
