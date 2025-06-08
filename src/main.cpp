#include "Controller.h"
#include "SrartWindow.h"

int main() {
    StartWindow startWindow;
    startWindow.run();

    if (!startWindow.isOpen()) {
        Controller controller;
        controller.run();
    }

    return 0;
} 