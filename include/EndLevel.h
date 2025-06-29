
#include "Object.h"

class EndLevel : public Object 
{
public:
	EndLevel(const float location);
	~EndLevel() {};
	void collided(Player* player) { m_isEndLevel = true; }
	static bool isEndLevel() { return m_isEndLevel; }

private:
	static bool m_isEndLevel;
};