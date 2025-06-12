#include <SFML/Graphics.hpp>
#include "RoadLine.h"

class Road
{
public:
	Road();
	~Road() {}
	void gameStart(sf::Vector2u sizeWindow,const int roadWidth, const int numLanes);
	void draw(sf::RenderWindow& window);
	void promoteRoad();

private:
	std::vector<RoadLine> m_roadLines;
	int m_toPromote;
};