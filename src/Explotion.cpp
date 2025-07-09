#pragma once
#include "Explotion.h"
#include <SoundManager.h>

Explotion::Explotion(sf::Vector2f pos)
	:ObjectMove("explotion", sf::Vector2f(pos.x, pos.y - 124))
{
	//setScale(0.5f, 0.5f);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 122.8, 124));
	SoundManager::getInstance().stopAllSounds();
	SoundManager::getInstance().playSound("accident");

}
//===========================================================
void Explotion::move(const float deltaTime)
{
	m_deltaTime += deltaTime;
	ObjectMove::move(deltaTime);
}
//===========================================================
void Explotion::draw(sf::RenderWindow& window)
{
	if (m_deltaTime > m_time)
	{
		m_time += 0.05;
		m_sprite.setTextureRect(sf::IntRect(m_sprite.getGlobalBounds().width * 20 * m_time, 0, m_sprite.getTextureRect().width, m_sprite.getTextureRect().height));
	}
	Object::draw(window);
	
	if (m_time >= 0.5)
	{
		m_isEnd = true;
	}
}
