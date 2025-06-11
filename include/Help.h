#pragma once
#include "Command.h"
class Help : public Command
{
public:
	Help() = default ;
	~Help() = default;
	void execute() { showHelp(); }

private:
	void showHelp() const;
};