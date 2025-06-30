#pragma once
#include "Menu.h"
#include <SFML/Graphics/RectangleShape.hpp>

Menu::Menu() { }
////===========================================
void Menu::add(const std::string& name, std::unique_ptr<Command> command, const sf::Vector2f& size, const sf::Vector2f& position)
{
	m_commands[name] = std::move(command);
	m_buttons.push_back(Botton(name, size, position));
}
//===========================================
void Menu::maneger(sf::RenderWindow& window, const sf::Vector2f& mousePos)
{
	for (auto& button : m_buttons)
	{
		if (button.getGlobalBounds().contains(mousePos))
		{
			auto it = m_commands.find(button.getName());
			if (it != m_commands.end())
			{
				it->second->execute(window);

			}
		}
	}
}
//===========================================
void Menu::draw(sf::RenderWindow& window)
{
	for (auto& button : m_buttons)
	{
		button.draw(window);
	}
}
//===========================================