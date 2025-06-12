#pragma once
#include <SFML/Graphics.hpp>

class Command {
public:
	Command() = default;
	// Execute the command
	virtual void execute(sf::RenderWindow& window) = 0;
private:

};