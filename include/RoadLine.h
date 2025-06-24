#pragma once
#include <SFML/Graphics.hpp>

class RoadLine
{
public:
	RoadLine(const int roadWidth, const int numLanes);
	~RoadLine() {}

	void setPositionLine(const sf::Vector2f& position);
	sf::Vector2f getPositionLine() const;
	sf::Vector2f getRoadSize() const;

	void draw(sf::RenderWindow& window) const ;

private:
	sf::RectangleShape m_roadLine;
	std::vector< sf::RectangleShape> m_separationLines;
	int m_roadWidth;
	int m_numLanes;
};