#include "Controller.h"
#include "Player.h"
#include <Io.h>


Controller::Controller() 
{
}
//===============================================
void Controller::run() 
{
	openWindow(sf::Vector2u(1600,1000));
	fillObjects();
	m_clock.restart();
	while (isOpen())
	{
		actionObjects();
		runBoard();
	}
}
//===============================================
void Controller::fillObjects()
{

	m_objects.push_back(std::make_unique<Player>(sf::Vector2f(getWindowSize().x / 2 , getWindowSize().y - SIZE_CAR.y - 50)));
}
//================================
void Controller::actionObjects()
{
	float time = m_clock.restart().asSeconds();
	for (auto& object : m_objects)
		object->action(time);
}
