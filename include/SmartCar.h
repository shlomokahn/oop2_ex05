#pragma once
#include "Car.h"

class SmartCar : public Car 
{
public:

	SmartCar(std::string name, sf::Vector2f pos);
	~SmartCar() = default;
	virtual void move(const float deltaTime) override;
	void moveBackToRoad(const float moveTo) override;

protected:
	float m_countRect = 0;
private:
	void setRect();
	void straighten(const float time);
	int m_steere = 10;
	float m_deltaTime = 0;


};

