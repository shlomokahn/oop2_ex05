#include <SFML/Graphics.hpp>
#include "RoadLine.h"

class ObjectMove;

class Road
{
public:
	Road();
	~Road() {}
	void gameStart(sf::Vector2u sizeWindow,const int roadWidth, const int numLanes);
	void draw(sf::RenderWindow& window);
	void promoteRoad(const float positionViewY);

	void inRoad(ObjectMove* objectMove);

private:
	std::vector<RoadLine> m_roadLines;
	std::vector< sf::Sprite> m_backGame;
	float m_lastViewCenter;
	int m_toPromote = 12;
	int m_backGametoPromote = 2;
	float m_backGamelastViewCenter;
};