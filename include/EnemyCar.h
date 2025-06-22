#pragma once
#include "Enemy.h"
#include "Car.h"
#include "Player.h"

class EnemyCar : public Enemy, public Car
{
public:
	EnemyCar(const int path,const int speed);
	~EnemyCar() = default;
	void collided(Player& player) override { player.collided(*this); }

private:

};
