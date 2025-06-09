#pragma once
#include "Enemy.h"
#include "Car.h"

class EnemyCar : public Enemy, public Car
{
public:
	EnemyCar(const int path,const int speed);
	~EnemyCar() = default;

private:

};
