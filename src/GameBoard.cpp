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
void GameBoard::drawObjects()
{
    for(auto& object : m_objects) 
        object->draw(m_window);
}
//===============================
void GameBoard::drawBoard()
{
    m_window.clear(sf::Color(100, 180, 80));
    drawSixLaneRoad();
    drawObjects();
}
//===============================
void GameBoard::drawSixLaneRoad()
{
    for (int i = 0; i < 10; i++)
    {
        drawSixLaneRoadLine(m_window.getSize().y - (i + 1) * m_roadWidth/m_numLanes);
    }
}
//===============================
void GameBoard::drawSixLaneRoadLine(const int location)
{
    sf::RectangleShape road(sf::Vector2f(m_roadWidth, m_roadWidth / m_numLanes+1));
	road.setPosition((m_window.getSize().x - m_roadWidth) / 2, location);
    road.setFillColor(sf::Color(30, 30, 30));
    m_window.draw(road);

    for (int lane = 0; lane < m_numLanes + 1; ++lane)
    {
        sf::RectangleShape line(sf::Vector2f(10, road.getSize().y/2));
        float x = road.getPosition().x + (m_roadWidth * lane) / (m_numLanes) - line.getSize().x/2;
        line.setPosition(x, road.getPosition().y + line.getSize().y / 2);
        line.setFillColor((lane == 0 || lane == 6) ? sf::Color::Yellow : sf::Color::White);
        m_window.draw(line);
    }
}
//===============================

