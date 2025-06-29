#pragma once
#include <fstream>  
#include <string>  
#include <vector>

class ReadFromFile  
{  
public:  
    ReadFromFile(const std::string name);
    ~ReadFromFile() {}
	void ReadLevel();
	std::string GetLevelData(const int index) const { return m_levelData[index]; }

private:  
    std::ifstream m_file; 
	std::vector<std::string> m_levelData;
};