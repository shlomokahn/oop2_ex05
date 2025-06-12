#include "Help.h"
#include <fstream>
#include <PrintText.h>

void Help::showHelp(sf::RenderWindow& window) const
{
	std::ifstream helpFile("resources/help.txt");
	std::string line;
	std::string helpContent;
	while (std::getline(helpFile, line))
		helpContent += line + '\n';

	window.clear(sf::Color::Black);
	PrintText::getInstance().drawText(window, helpContent, 20, sf::Color::White, sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	window.display();
	// Wait for user to close the help window
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			else if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					helpFile.close();
					return;
				}
			}
		}
	}
}
