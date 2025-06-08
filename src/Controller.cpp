#include "Controller.h"


Controller::Controller() 
{
}
//===============================================
void Controller::run() 
{
	openWindow(sf::Vector2u(1600,1000));

	while (isOpen())
	{
		runBoard();
	}
}