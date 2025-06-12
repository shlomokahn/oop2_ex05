#include "RoadLine.h"

RoadLine::RoadLine(const int roadWidth, const int numLanes)
	: m_roadWidth(roadWidth), m_numLanes(numLanes) 
{
	float sizeRoadLine = m_roadWidth / m_numLanes;
	m_roadLine.setSize(sf::Vector2f(m_roadWidth, sizeRoadLine));
	m_roadLine.setFillColor(sf::Color(30, 30, 30));

	sf::RectangleShape separation(sf::Vector2f(10, m_roadLine.getSize().y / 2));
	for (int i = 0; i < m_numLanes + 1; i++)
	{
		separation.setFillColor((i == 0 || i == 6) ? sf::Color::Yellow : sf::Color::White);
		m_separationLines.push_back(separation);
	}
}
//==========================
void RoadLine::setPositionLine(const sf::Vector2f& position)
{
	m_roadLine.setPosition(position);
	for (int i = 0; i < m_separationLines.size(); i++)
	{
		float x = m_roadLine.getPosition().x + (m_roadWidth * i) / (m_numLanes);
		float y = m_roadLine.getPosition().y + m_roadLine.getSize().y / 2;
		m_separationLines[i].setPosition(x, y);
	}
	
}
//==========================
sf::Vector2f RoadLine::getPositionLine()const
{
	return m_roadLine.getPosition();
}
//==========================
float RoadLine::getRoadWidth() const
{
	return m_roadLine.getSize().y;
}
//==========================
void RoadLine::draw(sf::RenderWindow& window) const
{
	window.draw(m_roadLine);
	for (const auto& separation : m_separationLines)
	{
		window.draw(separation);
	}
}