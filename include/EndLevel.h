#pragma once

#include "Object.h"

class EndLevel : public Object 
{
public:
	EndLevel( sf::Vector2f location, const float width);
	~EndLevel() {};
	void collided(Player* player) override;
	static bool isEndLevel() { return m_isEndLevel; }

private:
	static bool m_isEndLevel;
};