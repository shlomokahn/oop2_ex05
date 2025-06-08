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
private:
	void drawObjects();
	void drawBoard();
	void drawRoad(int roadWidthBottom, int roadWidthTop);
	sf::RenderWindow m_window;
};