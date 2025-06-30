#pragma once
#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager() 
{
    loadAllSounds();
}
//================================================
SoundManager& SoundManager::getInstance() 
{
    static SoundManager instance;
    return instance;
}
//================================================
void SoundManager::loadAllSounds() 
{
    for (const auto& name : m_soundNames) 
    {
        if (m_buffers.find(name) != m_buffers.end())
            continue;

        std::string path = "resources/" + name + ".mp3";
        sf::SoundBuffer buffer;
        if (!buffer.loadFromFile(path)) 
        {
            std::cerr << "Failed to load sound: " << path << std::endl;
            continue;
        }

        m_buffers[name] = buffer;
        m_sounds[name].setBuffer(m_buffers[name]);

		if (std::find(m_loopingSounds.begin(), m_loopingSounds.end(), name) != m_loopingSounds.end())
		{
			m_sounds[name].setLoop(true);
		}
    }
}
//================================================
void SoundManager::playSound(const std::string& name) 
{
    auto it = m_sounds.find(name);
    if (it != m_sounds.end()) {
        it->second.play();
    }
}
//================================================
void SoundManager::stopAllSounds() 
{
    for (auto& pair : m_sounds)
        pair.second.stop();
}
//================================================
