#pragma once
#include "GameBoard.h"
#include "Command.h"

class Controller : public GameBoard,  public Command
{
    public:
        Controller();
        ~Controller(){};

		void execute(sf::RenderWindow& window) override { run(window); }
    private:
        void run(sf::RenderWindow& window);
        void fillObjects(const float time);
        void moveObjects();
		void collisionObjects();
        sf::Clock m_clock;
};