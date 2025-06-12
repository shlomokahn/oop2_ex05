#pragma once
#include "Car.h"

class SmartCar : public Car 
{
public:

	SmartCar(std::string name, sf::Vector2f pos);
	~SmartCar() = default;
	virtual void action(const float time)override;

protected:
	float m_countRect = 0;
private:
	void straighten(const float time);


};

