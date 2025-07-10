#pragma once
#include <SFML/Graphics.hpp>
#include "ObjectMove.h"
#include <Road.h>

class GameBoard
{
public:
	GameBoard();
	~GameBoard();

protected:
	void runBoard();
	void openWindow(sf::RenderWindow& window);
	bool isOpen(sf::Clock& m_clock);
	sf::Vector2u getWindowSize() const {return m_window->getSize(); }
	void fillroad();
	void checkInRoad();
	std::vector<std::unique_ptr<ObjectMove>> m_objectsMove;
	std::vector<std::unique_ptr<Object>> m_objects;
	int m_roadWidth = 1200;
	int m_numLanes = 6;
	int m_Level = 0;
private:
	void Pause();
	void drawObjects();
	void drawBoard();
	void drawData();
	Road m_road;
	sf::RenderWindow* m_window;
};