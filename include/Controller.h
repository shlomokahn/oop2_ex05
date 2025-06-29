#pragma once
#include "GameBoard.h"
#include "Command.h"
#include "ReadFromFile.h"

class Controller : public GameBoard,  public Command
{
    public:
        Controller();
        ~Controller(){};

		void execute(sf::RenderWindow& window) override { run(window); }
    private:
        void run(sf::RenderWindow& window);
        void fillObjects(const float time);
        bool fillObjects();
        void moveObjects();
		void collisionObjects();
        sf::Clock m_clock;
        ReadFromFile m_readFromFile;
		int m_Level = 0;
};