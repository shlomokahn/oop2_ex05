#include "GameBoard.h"

class Controller : public GameBoard
{
    public:
        Controller();
        ~Controller(){};

        void run();
    private:
        void fillObjects(const float time);
        void actionObjects();
        sf::Clock m_clock;
};