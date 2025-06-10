#include "SmartCar.h"

class Player : public SmartCar 
{
public:
	Player(sf::Vector2f pos);
	void action(const float time);
	void collision(Object& other) override;
	void collided(Object& other) override;

	~Player() = default;

private:

};