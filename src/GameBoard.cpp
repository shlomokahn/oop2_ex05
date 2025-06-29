#pragma once
#include "GameBoard.h"


//===============================
GameBoard::GameBoard()
{
}
//===============================
GameBoard::~GameBoard()
{
}
//===============================
void GameBoard::runBoard()
{	
    drawBoard();
	checkInRoad();

	static float lastViewCenter = m_window->getView().getCenter().y - (m_roadWidth / m_numLanes);

	float currentCenter = m_window->getView().getCenter().y;

	while(std::abs(currentCenter - lastViewCenter) > m_roadWidth / m_numLanes)
	{
		m_road.promoteRoad();
		lastViewCenter -= m_roadWidth / m_numLanes;
	}
}
//===============================
void GameBoard::openWindow(sf::RenderWindow& window)
{
	m_window = &window;
}
//===============================
bool GameBoard::isOpen()
{
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window->close();
			return false;
		}
	}
	m_window->display();
	return true;
}
//===============================
void GameBoard::fillroad()
{
	m_road.gameStart(m_window->getSize(), m_roadWidth, m_numLanes);
}
//=========================
void GameBoard::checkInRoad()
{
	for (auto& objectMove : m_objectsMove)
		m_road.inRoad(objectMove.get());

}
//===============================
void GameBoard::drawObjects()
{
	for (auto& object : m_objects)
		object->draw(*m_window);

    for(auto& objectMove : m_objectsMove)
        objectMove->draw(*m_window);

}
//===============================
void GameBoard::drawBoard()
{
    m_window->clear(sf::Color(100, 180, 80));
	m_road.draw(*m_window);
    drawObjects();
}
//===============================

