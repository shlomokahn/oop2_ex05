#pragma once
#include <SFML/Graphics.hpp>
#include "Object.h"

class GameBoard
{
public:
	GameBoard();
	~GameBoard();

protected:
	void runBoard();
	void openWindow(const sf::Vector2u size);
	bool isOpen();
	sf::Vector2u getWindowSize() const {return m_window.getSize(); }
	std::vector<std::unique_ptr<Object>> m_objects;
	int m_roadWidth = 1000;
	int m_numLanes = 6;
private:
	void drawObjects();
	void drawBoard();
	void drawSixLaneRoad();
	void drawSixLaneRoadLine(const int location);
	
	
	sf::RenderWindow m_window;
};