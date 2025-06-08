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
	m_window.clear(sf::Color::Black);
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
