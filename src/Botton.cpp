#pragma once
#include "Botton.h"

Botton::Botton(const std::string& name, const sf::Vector2f& size, const sf::Vector2f& position)
{
	m_buttonRect.setSize(size);
	m_buttonRect.setPosition(position);
	m_buttonRect.setFillColor(sf::Color(50, 50, 50));
	m_buttonRect.setOutlineThickness(2);
	m_buttonRect.setOutlineColor(sf::Color::White);
	m_name = name;
}
//===========================================
void Botton::draw(sf::RenderWindow& window)
{
	window.draw(m_buttonRect);
	PrintText::getInstance().drawText(window, m_name, 30, sf::Color::White, m_buttonRect );
}
