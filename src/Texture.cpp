#pragma once
#include "Texture.h"

Texture::Texture(std::string name, sf::Vector2f pos)
{
	m_texture.loadFromFile(name);
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	m_sprite.setPosition(pos);
}
//===============================================