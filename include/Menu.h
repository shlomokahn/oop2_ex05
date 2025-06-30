#pragma once
#include <map>
#include <string>
#include <memory>
#include "Command.h"
#include <SFML/System/Vector2.hpp>
#include "Botton.h"

class Menu : public Command
{
public:
	Menu();
	void add(const std::string& name, std::unique_ptr<Command> command, const sf::Vector2f& size, const sf::Vector2f& position); 
	void maneger(sf::RenderWindow& window, const sf::Vector2f& mousePos);
	void execute(sf::RenderWindow& window) override { ; }
	void draw(sf::RenderWindow& window);
private:
	std::map < std::string, std::unique_ptr<Command>> m_commands;
	std::vector<Botton> m_buttons;
};