#pragma once

#include "ObjectMove.h"
#include "Io.h"

ObjectMove::ObjectMove(std::string name, sf::Vector2f pos)
	: Object(name, pos), m_toMove(0.f, 0.f)
{
}
//===========================================================
void ObjectMove::draw(sf::RenderWindow& window)
{
	sf::View view = window.getView();
	sf::Vector2f center = view.getCenter();
	sf::Vector2f size = view.getSize();
	sf::FloatRect viewRect(
		center.x - size.x / 2.f,
		center.y - size.y / 2.f,
		size.x,
		size.y
	);

	if (m_sprite.getGlobalBounds().intersects(viewRect))
	{
		m_inView = true;
	}


	if (m_inView)
		Object::draw(window);

}
//===========================================================
void ObjectMove::move(const float deltaTime)
{
	if(m_inView)
		m_sprite.move(m_toMove.x * deltaTime * KMH, m_toMove.y * deltaTime * KMH);
}
//===========================================================
void ObjectMove::moveBackToRoad(const float moveTo)
{
	m_sprite.setPosition({ moveTo, m_sprite.getPosition().y});
}
//===========================================================
