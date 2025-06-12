#include "Road.h"

Road::Road() { }
//==================================
void Road::gameStart(sf::Vector2u sizeWindow, const int roadWidth, const int numLanes)
{
	int left = (sizeWindow.x - roadWidth) / 2;
	for (int i = 0; i < 30; i++)
	{
        m_roadLines.push_back(RoadLine(roadWidth, numLanes));
		int rowLocation = sizeWindow.y - roadWidth / numLanes * (i + 1);
		m_roadLines[i].setPositionLine( sf::Vector2f(left, rowLocation) );
	}
}
//==================================
void Road::draw(sf::RenderWindow& window)
{
	for (auto& roadLine : m_roadLines)
	{
		roadLine.draw(window);
	}
}
//===============================
void Road::promoteRoad()
{

	sf::Vector2f newPosition = m_roadLines[(m_toPromote-1) % m_roadLines.size()].getPositionLine();
	newPosition.y -= m_roadLines[m_toPromote % m_roadLines.size()].getRoadWidth();

	m_roadLines[m_toPromote % m_roadLines.size()].setPositionLine(newPosition);
	m_toPromote++;
}


