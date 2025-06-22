#pragma once
#include "SmartCar.h"

class Player : public SmartCar 
{
public:
	Player(sf::Vector2f pos);
	void action(const float time)override;
	void collision(Object& other) override;
	void collided(Object& other) override;
	void collided(EnemeCar& enemeCar)override { m_isDead = true;}
	void draw(sf::RenderWindow& window)override;

	~Player() = default;

private:
	int m_minSpeed = 30;
	int m_maxSpeed = 200;
	int m_accelerat = 50;
	int m_slow = 200;
	int m_steere = 5;

};