#include "Help.h"
#include <fstream>
#include <PrintText.h>

void Help::showHelp() const
{
	std::ifstream helpFile("resources/help.txt");
	std::string line;
	std::string helpContent;
	while (std::getline(helpFile, line)) {
		helpContent += line + '\n';
	}
	PrintText::getInstance().drawText(sf::RenderWindow(), helpContent, 20, sf::Color::White, sf::Vector2f(50, 50));

	helpFile.close();
}
