#include "Texture.h"
#include <stdexcept>
#include <iostream>

Texture& Texture::getInstance() {
    static Texture instance;
    return instance;
}

void Texture::init()
{

    for (int i = 0; i < m_textureNames.size(); i++)
    {
        sf::Texture texture;
        std::string path = "resources/" + m_textureNames[i] + ".png";
        texture.loadFromFile(path);

        m_textures[m_textureNames[i]] =  std::move(texture);
    }
}

sf::Texture& Texture::getTexture(const std::string& name)
{
    auto it = m_textures.find(name);
    //if (it == m_textures.end())
        //throw std::runtime_error("Texture not found: " + name);
    return it->second;
}
