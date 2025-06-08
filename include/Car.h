#include "Object.h"

class Car : public Object
{
public:
	Car(std::string name, sf::Vector2f pos);
	~Car()= default;

private:
	int m_speed = 0;
};
