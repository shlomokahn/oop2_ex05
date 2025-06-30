#pragma once
#include "SmartCar.h"
class EnemeCar;

class Player : public SmartCar 
{
public:
	Player(sf::Vector2f pos);
	void move(const float deltaTime)override;
	void collision(Object* other) override;
	void collided(EnemyCar* enemyCar)override;
	void draw(sf::RenderWindow& window)override;

	static bool isDead() { return m_isDead; }

	~Player() = default;

private:
	int m_minSpeed = 30;
	int m_maxSpeed = 100;
	int m_accelerat = 50;
	int m_slow = 200;
	static bool m_isDead;

};