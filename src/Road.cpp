#include "Road.h"
#include "ObjectMove.h"

Road::Road() { }
//==================================
void Road::gameStart(sf::Vector2u sizeWindow, const int roadWidth, const int numLanes)
{
	int left = (sizeWindow.x - roadWidth) / 2;
	for (int i = 0; i < 10; i++)
	{
        m_roadLines.push_back(RoadLine(roadWidth, numLanes));
		int rowLocation = sizeWindow.y - roadWidth / numLanes * i;
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

	sf::Vector2f newPosition = m_roadLines[m_toPromote].getPositionLine();
	m_toPromote = (m_toPromote + 1) % m_roadLines.size();
	newPosition.y -= m_roadLines[m_toPromote].getRoadSize().y;
	m_roadLines[m_toPromote].setPositionLine(newPosition);
}
//==================================
void Road::inRoad(ObjectMove* objectMove)
{
	sf::FloatRect global = objectMove->getGlobal();
	if (global.left < m_roadLines[0].getPositionLine().x)
		objectMove->moveBackToRoad(m_roadLines[0].getPositionLine().x+30);
	
	else if(global.left + global.width > m_roadLines[0].getPositionLine().x + m_roadLines[0].getRoadSize().x)
		objectMove->moveBackToRoad(m_roadLines[0].getPositionLine().x + m_roadLines[0].getRoadSize().x - global.width+20);
}



