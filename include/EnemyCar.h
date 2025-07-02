#pragma once
#include "Enemy.h"
#include "Car.h"
#include "Player.h"

class EnemyCar : public Enemy, public Car
{
public:
	EnemyCar(const  sf::Vector2f path,const int speed, std::string carType);
	~EnemyCar() = default;
	void collision(Object* other) override;
	void collided(Player* player) override;
	void collided(EnemyCar* enemyCar) override;

private:

};
