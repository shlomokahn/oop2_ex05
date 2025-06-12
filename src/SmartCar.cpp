#pragma once
#include "SmartCar.h"

SmartCar::SmartCar(std::string name, sf::Vector2f pos)
	:Car(name, pos)
{
}
//===============================
void SmartCar::action(const float time)
{
	straighten(time);
	setRect(m_countRect);
	m_toMove.x = -m_countRect * m_toMove.y / 3;
	Car::action(time);
}
//===============================
void SmartCar::straighten(const float time)
{
	if(std::abs(m_countRect) < time )
		m_countRect = 0;
	else
		m_countRect += (m_countRect < 0) ? time : -time;
}
