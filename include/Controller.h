#pragma once
#include "GameBoard.h"
#include "Command.h"

class Controller : public GameBoard,  public Command
{
    public:
        Controller();
        ~Controller(){};

		void execute() override { run(); }
        void run();
    private:
        void fillObjects(const float time);
        void actionObjects();
        sf::Clock m_clock;
};