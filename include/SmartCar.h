#pragma once
#include "Car.h"

class SmartCar : public Car 
{
public:

	SmartCar(std::string name, sf::Vector2f pos);
	~SmartCar() = default;
	virtual void move(const float deltaTime) override;

protected:
	float m_countRect = 0;
private:
	void straighten(const float time);


};

