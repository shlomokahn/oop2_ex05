#include "Block.h"
#include "Car.h"
#include "EnemyCar.h"

Block::Block(const sf::Vector2f path)
	:Object("Block", path)
{
	setScale(Car::getSizeCar().x*1.5, Car::getSizeCar().y * 0.5);
}
//===========================================================
void Block::collided(EnemyCar* enemyCar)
{
	enemyCar->collided(this);
}
