#pragma once

#include "Object.h"

class ObjectMove : public Object
{
public:
	ObjectMove(std::string name, sf::Vector2f pos);
	~ObjectMove() = default;

	virtual void move(const float deltaTime);
	virtual void moveBackToRoad(const float moveTo);
	void setRect(const float rotation);

protected:
	sf::Vector2f m_toMove = { 0,0 };

private:
};