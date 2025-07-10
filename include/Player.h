#pragma once
#include "SmartCar.h"

class EnemeCar;
class Explotion;
class Player : public SmartCar 
{
public:
	Player(sf::Vector2f pos, std::istringstream& iss);
	void move(const float deltaTime)override;
	void collision(Object* other) override;
	void collided(EnemyCar* enemyCar)override;
	void collided(Block* block) override;
	void draw(sf::RenderWindow& window)override;

	static bool isDead() { return m_isDead; }

	~Player() = default;

private:
	int m_minSpeed = 30;
	int m_maxSpeed = 100;
	int m_accelerat = 20;
	int m_slow = 100;
	static float m_score;
	static bool m_isDead;
	Explotion* m_explotion = nullptr;
	sf::CircleShape m_circle;
	void printData(sf::RenderWindow& window);


};