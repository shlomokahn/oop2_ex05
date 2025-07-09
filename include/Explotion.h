#pragma once
#include "ObjectMove.h"

class Explotion : public ObjectMove
{
public:
	Explotion(sf::Vector2f pos);
	~Explotion() = default;
	void move(const float deltaTime) override;
	void draw(sf::RenderWindow& window) override;
	bool isEnd() const { return m_isEnd; }

private:
	float m_deltaTime = 0;
	float m_time = 0.05;
	bool m_isEnd = false;
};
