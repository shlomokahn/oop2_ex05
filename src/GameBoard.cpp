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
    int winWidth = m_window.getSize().x;
    int winHeight = m_window.getSize().y;

    // ציור הכביש (מלבן ישר)
    int roadWidth = m_roadWidth; // אין פרספקטיבה
    int roadLeft = (winWidth - roadWidth) / 2;
    sf::RectangleShape road(sf::Vector2f(roadWidth, winHeight));
    road.setPosition(roadLeft, 0);
    road.setFillColor(sf::Color(30, 30, 30));
    m_window.draw(road);

    for (int lane = 0; lane < m_numLanes + 1; ++lane) {
        float x = roadLeft + (roadWidth * lane) / (m_numLanes);
        sf::RectangleShape line(sf::Vector2f(4, winHeight));
        line.setPosition(x - 2, 0); // מרכז הקו
        line.setFillColor((lane == 0 || lane == 6)?sf::Color::Yellow : sf::Color::White);
        m_window.draw(line);
    }
}
//===============================

