#pragma once
#include "ObjectMove.h"

class Car : public ObjectMove
{
public:
	Car(std::string name, sf::Vector2f pos);
	~Car()= default;

	virtual void move(const float deltaTime) override;

	static void setSizeCar(sf::Vector2f size) { m_sizeCar = size; }
	static sf::Vector2f getSizeCar() { return m_sizeCar; }
protected:
	
private:
	static sf::Vector2f m_sizeCar;
};
