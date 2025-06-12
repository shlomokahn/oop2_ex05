#pragma once
#include "Command.h"

class Exit : public Command
{
public:
	Exit() = default;
	~Exit() = default;
	void execute(sf::RenderWindow& window) override {
		window.close();
	}
};