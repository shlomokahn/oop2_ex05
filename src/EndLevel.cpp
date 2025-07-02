#include "EndLevel.h"

bool EndLevel::m_isEndLevel = false;

EndLevel::EndLevel(const float location)
	:Object("levelUp" , {0,location })
{
	m_isEndLevel = false;
}
