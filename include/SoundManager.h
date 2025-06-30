#pragma once

#include <SFML/Audio.hpp>
#include <map>
#include <string>
#include <vector>

class SoundManager 
{
public:
    static SoundManager& getInstance();

    void playSound(const std::string& name);
    void stopAllSounds();

private:
    void loadAllSounds();
    SoundManager();
    ~SoundManager() = default;

    SoundManager(const SoundManager&) = delete;
    SoundManager& operator=(const SoundManager&) = delete;

    std::map<std::string, sf::SoundBuffer> m_buffers;
    std::map<std::string, sf::Sound> m_sounds;

    std::vector<std::string> m_soundNames = {"menuBackraund", "gameBackraund", "accident"};
	std::vector<std::string> m_loopingSounds = { "menuBackraund", "gameBackraund" };
};
