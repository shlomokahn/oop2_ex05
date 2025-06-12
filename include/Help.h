#pragma once
#include "Command.h"
class Help : public Command
{
public:
	Help() = default ;
	~Help() = default;
	void execute(sf::RenderWindow& window) { showHelp(window); }

private:
	void showHelp(sf::RenderWindow& window) const;
};