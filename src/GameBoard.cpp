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

	static float lastViewCenter = m_window.getView().getCenter().y;

	float currentCenter = m_window.getView().getCenter().y;

	if( std::abs(currentCenter - lastViewCenter) > m_roadWidth/m_numLanes)
	{
		static int count = 0;
		count++;
		m_road.promoteRoad();
		lastViewCenter = currentCenter;
	}
}
//===============================
void GameBoard::openWindow(const sf::Vector2u size)
{
	m_window.create(sf::VideoMode(size.x, size.y), "Game Board");
	m_window.setFramerateLimit(60);
}
//===============================
bool GameBoard::isOpen()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_window.close();
			return false;
		}
	}
	m_window.display();
	return true;
}
//===============================
void GameBoard::fillroad()
{
	m_road.gameStart(m_window.getSize(), m_roadWidth, m_numLanes);
}
//===============================
void GameBoard::drawObjects()
{
    for(auto& object : m_objects) 
        object->draw(m_window);
}
//===============================
void GameBoard::drawBoard()
{
    m_window.clear(sf::Color(100, 180, 80));
	m_road.draw(m_window);
    drawObjects();
}
//===============================

