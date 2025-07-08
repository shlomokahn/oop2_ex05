#include "Road.h"
#include "ObjectMove.h"
#include "SoundManager.h"

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

	sf::Sprite backgroundSprite(Texture::getInstance().getTexture("backGame"));
    sf::Vector2f sizeBackground = sf::Vector2f(sizeWindow.x + roadWidth, sizeWindow.y);
	backgroundSprite.setScale({ sizeBackground.x / backgroundSprite.getGlobalBounds().width, sizeBackground.y / backgroundSprite.getGlobalBounds().height});
	for (int i = 0; i < m_backGametoPromote+1; i++)
	{
		backgroundSprite.setPosition(-roadWidth/2, -i * float(sizeWindow.y));
		m_backGame.push_back(backgroundSprite);
	}
	m_backGamelastViewCenter = 0;
}
//==================================
void Road::draw(sf::RenderWindow& window)
{
	for (auto& background : m_backGame)
	{
		window.draw(background);
	}
	for (auto& roadLine : m_roadLines)
	{
		roadLine.draw(window);
	}
}
//===============================
void Road::promoteRoad(const float positionViewY)
{

	while (std::abs(positionViewY - m_lastViewCenter) > m_roadLines[0].getRoadSize().y)
	{
		sf::Vector2f newPosition = m_roadLines[m_toPromote].getPositionLine();
		m_toPromote = (m_toPromote + 1) % m_roadLines.size();
		newPosition.y -= m_roadLines[m_toPromote].getRoadSize().y;
		m_roadLines[m_toPromote].setPositionLine(newPosition);

		m_lastViewCenter -= m_roadLines[0].getRoadSize().y;
	}
	if(std::abs(positionViewY - m_backGamelastViewCenter) > m_backGame[0].getGlobalBounds().height)
	{
		sf::Vector2f newPosition = m_backGame[m_backGametoPromote].getPosition();
		m_backGametoPromote = (m_backGametoPromote + 1) % m_backGame.size();
		newPosition.y -= m_backGame[0].getGlobalBounds().height;
		m_backGame[m_backGametoPromote].setPosition(newPosition);
		m_backGamelastViewCenter -= m_backGame[0].getGlobalBounds().height;
	}


}
//==================================
void Road::inRoad(ObjectMove* objectMove)
{
    sf::FloatRect global = objectMove->getGlobal();
    float leftX = global.left;
    float rightX = global.left + global.width;
    float y = global.top;

    for (int i = 0; i < m_roadLines.size(); i++)
    {
        bool leftIsInRoad = m_roadLines[i].getGlobal().contains({ leftX, y });
        bool rightIsInRoad = m_roadLines[i].getGlobal().contains({ rightX, y });

        if (!leftIsInRoad && !rightIsInRoad)
            continue;

        if (!leftIsInRoad) {
            // החלק השמאלי מחוץ לכביש
            
            float newX = m_roadLines[i].getPositionLine().x;
            objectMove->moveBackToRoad(newX+1);
			SoundManager::getInstance().playSound("drag");
            return;
        }
        if (!rightIsInRoad) {
            // החלק הימני מחוץ לכביש
            float newX = m_roadLines[i].getPositionLine().x + m_roadLines[0].getRoadSize().x - global.width;
            objectMove->moveBackToRoad(newX);
			SoundManager::getInstance().playSound("drag");
            return;
        }
    }
}



