#pragma once

class Command {
public:
	Command() = default;
	// Execute the command
	virtual void execute() = 0;
private:

};