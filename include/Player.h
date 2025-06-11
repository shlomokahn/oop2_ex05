#pragma once
#include "SmartCar.h"

class Player : public SmartCar 
{
public:
	Player(sf::Vector2f pos);
	void action(const float time)override;
	void collision(Object& other) override;
	void collided(Object& other) override;
	void draw(sf::RenderWindow& window)override;

	~Player() = default;

private:

};