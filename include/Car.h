#pragma once
#include "ObjectMove.h"

class Car : public ObjectMove
{
public:
	Car(std::string name, sf::Vector2f pos);
	~Car()= default;

	virtual void move(const float deltaTime) override;
protected:
	
private:
};
