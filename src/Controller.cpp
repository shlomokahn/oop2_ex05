#pragma once
#include <fstream>
#include <sstream>
#include "Controller.h"
#include "Player.h"
#include <Io.h>
#include <EnemyCar.h>
#include <ReadFromFile.h>
#include "EndLevel.h"
#include "SoundManager.h"
#include "Block.h"


Controller::Controller() 
	:m_readFromFile("resources/info.txt")
{
}
//===============================================
void Controller::run(sf::RenderWindow& window)
{
	SoundManager::getInstance().stopAllSounds();
	SoundManager::getInstance().playSound("gameBackraund");
	openWindow(window);
	Car::setSizeCar(sf::Vector2f(window.getSize().x / 12, window.getSize().y / 5));

	if(static bool firstRun = true; firstRun)
	{
		m_readFromFile.ReadLevel();
		firstRun = false;
	}
	
	fillObjects();
	fillroad();
	m_clock.restart();
	while (isOpen())
	{
		runBoard();
		moveObjects();
		collisionObjects();

		if(EndLevel::isEndLevel() || Player::isDead())
		{
			m_objects.clear();
			m_objectsMove.clear();
			if(EndLevel::isEndLevel())
				m_readFromFile.ReadLevel();
			SoundManager::getInstance().playSound("menuBackraund");
			return;
		}
	}
}
//=================================
bool Controller::fillObjects()
{
	int i = 0;	
	std::string info = m_readFromFile.GetLevelData(i);
	std::istringstream iss(info);
	int sizeLine = 0;
	iss >> m_Level >> sizeLine >> m_numLanes;
	sizeLine *= 200;
	
	m_roadWidth = m_numLanes * (Car::getSizeCar().x * 1.5);

	m_objectsMove.push_back(std::make_unique<Player>(sf::Vector2f(getWindowSize().x / 2, getWindowSize().y - Car::getSizeCar().y*2), iss));

	i++;
	std::string line;
	float leftRoad = (getWindowSize().x - m_roadWidth) / 2;
	while (m_readFromFile.GetLevelData(i) != "+")
	{
		line = m_readFromFile.GetLevelData(i);
		i++;
		if (line.empty()) continue;
		for(int j = 0; j < line.size(); j++)
		{
			if (line[j] == '*')
			{
				int carType = rand() % 3;
				if (carType == 1) 
					m_objectsMove.push_back(std::make_unique<EnemyCar>(sf::Vector2f(float(leftRoad + (j * (m_roadWidth / m_numLanes))), float(-i * sizeLine)), rand() % 20 + 20, "whiteCar"));
				else if (carType == 2)
					m_objectsMove.push_back(std::make_unique<EnemyCar>(sf::Vector2f(float(leftRoad + (j * (m_roadWidth / m_numLanes))), float(-i * sizeLine)), rand() % 20 + 20, "blueCar"));
				else
					m_objectsMove.push_back(std::make_unique<EnemyCar>(sf::Vector2f(float(leftRoad + (j * (m_roadWidth / m_numLanes))), float(-i * sizeLine)), rand() % 20 + 20, "redCar"));
			}
			if(line[j] == '!')
			{
				m_objects.push_back(std::make_unique<Block>(sf::Vector2f(float(leftRoad + (j * (m_roadWidth / m_numLanes))),float(-i * sizeLine))));
			}
		}

		
	}
	m_objects.push_back(std::make_unique<EndLevel>(sf::Vector2f(leftRoad, -(i+5) * sizeLine), m_roadWidth));
	return true;
}
//================================
void Controller::moveObjects()
{
	float time = m_clock.restart().asSeconds();
	for (auto& object : m_objectsMove)
		object->move(time);
}
//================================
void Controller::collisionObjects()
{
	for(int i = 0; i < m_objectsMove.size();i++)
	{
		for (int j = 0; j < m_objectsMove.size(); j++)
			if (i != j)
				m_objectsMove[i]->collision(m_objectsMove[j].get());

		for(int j = 0; j < m_objects.size(); j++)
			m_objectsMove[i]->collision(m_objects[j].get());
	}
}
