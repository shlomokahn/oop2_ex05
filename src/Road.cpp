#include "Road.h"
#include "ObjectMove.h"

Road::Road() { }
//==================================
void Road::gameStart(sf::Vector2u sizeWindow, const int roadWidth, const int numLanes)
{
	m_toPromote = 12;
	m_roadLines.clear();
	int left = (sizeWindow.x - roadWidth) / 2;
	for (int i = 0; i < m_toPromote+1; i++)
	{
        m_roadLines.push_back(RoadLine(roadWidth, numLanes));
		int rowLocation = sizeWindow.y - roadWidth / numLanes * i;
		m_roadLines[i].setPositionLine( sf::Vector2f(left, rowLocation) );
	}
	m_lastViewCenter = sizeWindow.y/2 + m_roadLines[0].getRoadSize().y;
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
void Road::promoteRoad(const float positionViewY)
{
	 

	float currentCenter = positionViewY;

	while (std::abs(currentCenter - m_lastViewCenter) > m_roadLines[0].getRoadSize().y)
	{
		sf::Vector2f newPosition = m_roadLines[m_toPromote].getPositionLine();
		m_toPromote = (m_toPromote + 1) % m_roadLines.size();
		newPosition.y -= m_roadLines[m_toPromote].getRoadSize().y;
		m_roadLines[m_toPromote].setPositionLine(newPosition);

		m_lastViewCenter -= m_roadLines[0].getRoadSize().y;
	}
}
//==================================
void Road::inRoad(ObjectMove* objectMove)
{
	sf::FloatRect global = objectMove->getGlobal();
	if (global.left < m_roadLines[0].getPositionLine().x)
		objectMove->moveBackToRoad(m_roadLines[0].getPositionLine().x+25);
	
	else if(global.left + global.width > m_roadLines[0].getPositionLine().x + m_roadLines[0].getRoadSize().x)
		objectMove->moveBackToRoad(m_roadLines[0].getPositionLine().x + m_roadLines[0].getRoadSize().x - global.width+20);
}



