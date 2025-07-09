#pragma once
#include "GameBoard.h"
#include <PrintText.h>

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
	
	m_road.promoteRoad(m_window->getView().getCenter().y);
		
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
		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
		{
			Pause(event);
			return true;
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
void GameBoard::Pause(sf::Event event)
{
		if (event.type == sf::Event::Closed)
		{
			m_window->close();
			return;
		}
			// מציג מסך פאוזה (אם קיים)
			// למשל pauseMenu.draw(window);
			// מחכה ללחיצה על רווח
			bool waitingForResume = true;
			while (waitingForResume)
			{
				sf::Event pauseEvent;
				while (m_window->pollEvent(pauseEvent))
				{
					if (pauseEvent.type == sf::Event::Closed)
					{
						m_window->close();
						waitingForResume = false; // יציאה גם מהפאוז
					}
					if (pauseEvent.type == sf::Event::KeyPressed && pauseEvent.key.code == sf::Keyboard::Space)
						waitingForResume = false;
				}
				// תוכל להוסיף כאן ציור של מסך "Paused" אם תרצה
				m_window->clear();
				// pauseMenu.draw(window); // לדוגמה
				m_window->display();
			}
		}
//===============================
void GameBoard::drawObjects()
{
	for (auto& object : m_objects)
		object->draw(*m_window);

    for(auto& objectMove : m_objectsMove)
        objectMove->draw(*m_window);
}
void GameBoard::drawBoard()  
{  
	m_window->clear(); 
	m_road.draw(*m_window);  
	drawObjects(); 
	drawData();
}
//===============================
void GameBoard::drawData()
{
	sf::View view = m_window->getView();
	sf::Vector2f position(view.getCenter().x, view.getCenter().y - view.getSize().y * 0.45);

	PrintText::getInstance().drawText(*m_window, "Level: " + std::to_string(m_Level), m_window->getSize().y * 0.06, sf::Color::Green, position);
}
//===============================

