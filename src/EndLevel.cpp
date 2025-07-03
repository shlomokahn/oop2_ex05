#pragma once
#include "EndLevel.h"
#include "SoundManager.h"
bool EndLevel::m_isEndLevel = false;

EndLevel::EndLevel( sf::Vector2f location,const float width)
	:Object("levelUp" , location)
{
	m_isEndLevel = false;
	setScale(width, width/5);
}
//==============================
void EndLevel::collided(Player* player)
{
	m_isEndLevel = true;
	SoundManager::getInstance().stopAllSounds();
}
