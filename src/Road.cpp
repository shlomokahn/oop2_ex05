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
	for (int i = 0; i < 3; i++)
	{
		m_backGame.push_back(backgroundSprite);
		m_backGame[i].setPosition(0, -i * sizeWindow.y);
	}
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



