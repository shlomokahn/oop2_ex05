#pragma once
#include "Command.h"
class UserSettings : public Command
{
public:
	UserSettings() {};
	void execute(sf::RenderWindow& window) override {
		// Implementation for user settings
	}
	~UserSettings() = default;

private:

};
