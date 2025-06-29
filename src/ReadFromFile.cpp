#pragma once
#include "ReadFromFile.h"
#include <iostream>

ReadFromFile::ReadFromFile(const std::string name)
{
	m_file.open(name, std::ios::in);
	if (!m_file.is_open()) {
		std::cerr << "Could not open file: " << name << std::endl;
		//throw std::runtime_error("Could not open file: " + name);
	}
}
//============================
void ReadFromFile::ReadLevel()
{
	m_levelData.clear();
	std::string line;
	while (std::getline(m_file, line)) {
		m_levelData.push_back(line);
		if (line == " + ") continue;
	}
}
