#pragma once
#include "SmartCar.h"

SmartCar::SmartCar(std::string name, sf::Vector2f pos)
	:Car(name, pos)
{
}
//===============================
void SmartCar::move(const float deltaTime)
{
	straighten(deltaTime);
	setRect(m_countRect);
	m_toMove.x = -m_countRect * m_toMove.y / 3;
	Car::move(deltaTime);
}
//===============================
void SmartCar::straighten(const float time)
{
	if(std::abs(m_countRect) < time )
		m_countRect = 0;
	else
		m_countRect += ((m_countRect < 0) ? 1 : -1) * time*2;
}
