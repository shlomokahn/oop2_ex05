#pragma once
#include "Object.h"
#include "Enemy.h"
#include "Player.h"

class Block : public Object ,public Enemy
{
public:
	Block(const sf::Vector2f path);
	~Block() = default;

	void collided(Player* player) override { player->collided(this); }
	void collided(EnemyCar* enemyCar) override;

private:
	
};

