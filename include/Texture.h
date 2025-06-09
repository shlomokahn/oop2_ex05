#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <string>
#include <vector>

class Texture {
public:
    static Texture& getInstance();
    void init();
    sf::Texture& getTexture(const std::string& name);

private:
    Texture() {init();};
    ~Texture() = default;
    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;

    std::unordered_map<std::string, sf::Texture> m_textures;
    std::vector<std::string> m_textureNames = {"back", "car"};

};
