#pragma once
#include "Object.h"

class Car : public Object
{
public:
	Car(std::string name, sf::Vector2f pos);
	~Car()= default;
	virtual void action(const float time);
protected:
	
private:
};
