#pragma once

#include "ObjectMove.h"
#include "Io.h"

ObjectMove::ObjectMove(std::string name, sf::Vector2f pos)
	: Object(name, pos), m_toMove(0.f, 0.f)
{
}
//===========================================================
void ObjectMove::move(const float deltaTime)
{
	m_sprite.move(m_toMove.x * deltaTime * KMH, m_toMove.y * deltaTime * KMH);
}
//===========================================================
void ObjectMove::setRect(const float rotation)
{
	m_sprite.setOrigin(SIZE_CAR.x / 2, SIZE_CAR.y / 2);
	m_sprite.setRotation(rotation);
}
