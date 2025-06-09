#include "Controller.h"
#include "Player.h"
#include <Io.h>
#include <EnemyCar.h>


Controller::Controller() 
{
}
//===============================================
void Controller::run() 
{
	openWindow(sf::Vector2u(1600,1000));
	m_objects.push_back(std::make_unique<Player>(sf::Vector2f(getWindowSize().x / 2, getWindowSize().y - SIZE_CAR.y - 50)));
	m_clock.restart();
	while (isOpen())
	{
		actionObjects();
		runBoard();
	}
}
//===============================================
void Controller::fillObjects(const float time)
{
	static float timer = 0.f;
	timer += time;
	if (timer > 2)
	{
		timer = 0.f;
		int path = getWindowSize().x / 2 - (getWindowSize().x / 20 * 2) + ((rand() % 4)) * getWindowSize().x/20;
		m_objects.push_back(std::make_unique<EnemyCar>(path, rand() % 20 + 100));
	}
}
//================================
void Controller::actionObjects()
{
	float time = m_clock.restart().asSeconds();
	fillObjects(time);
	for (auto& object : m_objects)
		object->action(time);
}
