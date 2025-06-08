#include "GameBoard.h"

class Controller : public GameBoard
{
    public:
        Controller();
        ~Controller(){};

        void run();
    private:
        void fillObjects();
};