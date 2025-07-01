#pragma once
#include "SmartCar.h"
#include <Io.h>

SmartCar::SmartCar(std::string name, sf::Vector2f pos)
	:Car(name, pos)
{
}
//===============================
void SmartCar::move(const float deltaTime)
{
	m_deltaTime = deltaTime;
	straighten(deltaTime);
	setRect();
	m_toMove.x = -m_countRect * (m_toMove.y / 3) * m_steere;
	Car::move(deltaTime);
}
//================================================
void SmartCar::moveBackToRoad(const float moveTo)
{
	straighten(m_deltaTime);
	setRect();
	ObjectMove::moveBackToRoad(moveTo);
}
//================================================
void SmartCar::setRect()
{
	m_sprite.setOrigin(getSizeCar().x / 2, getSizeCar().y / 2);
	m_sprite.setRotation(m_countRect * m_steere * 1.2);
}
//===============================
void SmartCar::straighten(const float time)
{
	if (std::abs(m_countRect) < time)
		m_countRect = 0;
	else
		m_countRect += ((m_countRect < 0) ? 1 : -1) * time / 2;
}
