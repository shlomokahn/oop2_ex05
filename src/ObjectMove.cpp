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
void ObjectMove::moveBackToRoad(const float moveTo)
{
	m_sprite.setPosition({ moveTo, m_sprite.getPosition().y});
}
//===========================================================
